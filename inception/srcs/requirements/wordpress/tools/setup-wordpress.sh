#!/bin/bash

# Colors for output
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RED='\033[0;31m'
NC='\033[0m' # No Color

echo -e "${YELLOW}Starting WordPress setup...${NC}"

# Wait for MariaDB to be ready
echo -e "${YELLOW}Waiting for MariaDB to be ready...${NC}"
while ! mysqladmin ping -h"${MYSQL_HOST}" --silent; do
    echo -n "."
    sleep 1
done
echo -e "${GREEN}MariaDB is ready!${NC}"

# Change to WordPress directory
cd /var/www/html

# Download WordPress if not already present
if [ ! -f "wp-config.php" ]; then
    echo -e "${YELLOW}Downloading WordPress...${NC}"
    
    # Download WordPress core (skip if already present)
    if [ ! -f "wp-login.php" ]; then
        wp core download --allow-root
        echo -e "${GREEN}WordPress downloaded!${NC}"
    else
        echo -e "${GREEN}WordPress files already present!${NC}"
    fi
    
    # Create wp-config.php
    echo -e "${YELLOW}Configuring WordPress...${NC}"
    
    wp config create \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${MYSQL_PASSWORD}" \
        --dbhost="${MYSQL_HOST}" \
        --allow-root \
        --force
    
    echo -e "${GREEN}WordPress configured!${NC}"
    
    # Check if WordPress is already installed in database
    if ! wp core is-installed --allow-root 2>/dev/null; then
        # Install WordPress
        echo -e "${YELLOW}Installing WordPress...${NC}"
        
        wp core install \
            --url="${WP_URL}" \
            --title="${WP_TITLE}" \
            --admin_user="${WP_ADMIN_USER}" \
            --admin_password="${WP_ADMIN_PASSWORD}" \
            --admin_email="${WP_ADMIN_EMAIL}" \
            --skip-email \
            --allow-root
        
        echo -e "${GREEN}WordPress installed!${NC}"
        
        # Create additional user
        echo -e "${YELLOW}Creating additional user...${NC}"
        
        if ! wp user get "${WP_USER}" --allow-root 2>/dev/null; then
            wp user create \
                "${WP_USER}" \
                "${WP_USER_EMAIL}" \
                --role=author \
                --user_pass="${WP_USER_PASSWORD}" \
                --allow-root
            
            echo -e "${GREEN}Additional user created!${NC}"
        else
            echo -e "${GREEN}Additional user already exists!${NC}"
        fi
    else
        echo -e "${GREEN}WordPress already installed in database!${NC}"
    fi
    
    # Set proper permissions
    chown -R www-data:www-data /var/www/html
    find /var/www/html -type d -exec chmod 755 {} \;
    find /var/www/html -type f -exec chmod 644 {} \;
    
    echo -e "${GREEN}WordPress setup complete!${NC}"
else
    echo -e "${GREEN}WordPress already configured, skipping setup...${NC}"
fi

# Create PHP-FPM directory if it doesn't exist
mkdir -p /run/php

# Start PHP-FPM
echo -e "${YELLOW}Starting PHP-FPM...${NC}"
exec "$@"
