#!/bin/bash
set -e

# Colors for output
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${YELLOW}Starting MariaDB initialization...${NC}"

# Create runtime directory for socket
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

# Check if MySQL data directory is empty (first run)
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo -e "${YELLOW}Initializing database...${NC}"
    
    # Initialize MySQL data directory
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
    
    # Start MySQL in the background
    mysqld --user=mysql --datadir=/var/lib/mysql &
    pid="$!"
    
    # Wait for MySQL to be ready
    echo -e "${YELLOW}Waiting for MariaDB to start...${NC}"
    for i in {30..0}; do
        if mysqladmin ping -h localhost --silent; then
            break
        fi
        echo -n "."
        sleep 1
    done
    
    if [ "$i" = 0 ]; then
        echo -e "${RED}MariaDB failed to start!${NC}"
        exit 1
    fi
    
    echo -e "${GREEN}MariaDB is ready!${NC}"
    
    # Secure installation and create database for Wordpress
    echo -e "${YELLOW}Configuring database...${NC}"
    
    mysql -u root <<-EOSQL
        -- Secure the installation
        DELETE FROM mysql.user WHERE User='';
        DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
        DROP DATABASE IF EXISTS test;
        DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
        
        -- Set root password
        ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
        
        -- Create database
        CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
        
        -- Create user with wildcard host
        CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
        
        -- Grant all privileges
        GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%' WITH GRANT OPTION;
        
        -- Also create user for localhost just in case
        CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';
        GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'localhost' WITH GRANT OPTION;
        
        -- Flush privileges
        FLUSH PRIVILEGES;
EOSQL
    
    echo -e "${GREEN}Database configured successfully!${NC}"
    
    # Stop the temporary MySQL instance
    if ! kill -s TERM "$pid" || ! wait "$pid"; then
        echo -e "${RED}Failed to stop temporary MySQL instance${NC}"
        exit 1
    fi
    
    echo -e "${GREEN}MariaDB initialization complete!${NC}"
else
    echo -e "${GREEN}Database already initialized, skipping installation...${NC}"
    
    # Even if DB exists, ensure user has correct permissions
    echo -e "${YELLOW}Ensuring database user exists...${NC}"
    
    # Start MySQL temporarily to check/create user
    mysqld --user=mysql --datadir=/var/lib/mysql &
    pid="$!"
    
    # Wait for MySQL to be ready
    for i in {30..0}; do
        if mysqladmin ping -h localhost --silent; then
            break
        fi
        sleep 1
    done
    
    if [ "$i" != 0 ]; then
        # Create/update user permissions
        mysql -u root -p"${MYSQL_ROOT_PASSWORD}" <<-EOSQL
            CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
            CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
            GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%' WITH GRANT OPTION;
            CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';
            GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'localhost' WITH GRANT OPTION;
            FLUSH PRIVILEGES;
EOSQL
        echo -e "${GREEN}Database user ensured!${NC}"
        
        # Stop the temporary MySQL instance
        kill -s TERM "$pid" 2>/dev/null || true
        wait "$pid" 2>/dev/null || true
    fi
fi

# Start MySQL normally
echo -e "${YELLOW}Starting MariaDB server...${NC}"
exec "$@"
