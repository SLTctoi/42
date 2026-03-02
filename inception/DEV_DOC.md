# Developer Documentation

This document describes how a developer can set up and work with the Inception project.

## Table of Contents

1. [Environment Setup](#environment-setup)
2. [Building and Launching](#building-and-launching)
3. [Managing Containers and Volumes](#managing-containers-and-volumes)
4. [Data Storage and Persistence](#data-storage-and-persistence)

---

## Environment Setup

### Prerequisites

Before starting, ensure you have the following installed on your system:

- **Docker Engine** (version 20.10+)
- **Docker Compose** (version 2.0+)
- **Make**
- **Git**

#### Installing Docker on Linux

```bash
# Download and install Docker
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh

# Add your user to the docker group
sudo usermod -aG docker $USER

# Start Docker service
sudo service docker start

# Verify installation
docker --version
docker compose version
```

### Configuration Files

The project requires two main configuration files:

#### 1. Domain Configuration

Add your domain to `/etc/hosts`:

```bash
sudo nano /etc/hosts
```

Add this line (replace `maxime` with your login):
```
127.0.0.1  maxime.42.fr
```

#### 2. Environment Variables (.env)

Create the `.env` file in the `srcs/` directory:

```bash
cd srcs
cp .env.example .env  # If you have an example file
nano .env
```

Configure the following variables:

```bash
# Domain
DOMAIN_NAME=maxime.42.fr

# MariaDB Configuration
MYSQL_ROOT_PASSWORD=strong_root_password
MYSQL_DATABASE=wordpress
MYSQL_USER=wordpress_user
MYSQL_PASSWORD=strong_db_password

# WordPress Admin (username must NOT contain "admin")
WP_ADMIN_USER=mlebard
WP_ADMIN_PASSWORD=strong_admin_password
WP_ADMIN_EMAIL=admin@example.com

# WordPress Regular User
WP_USER=editor
WP_USER_PASSWORD=strong_user_password
WP_USER_EMAIL=editor@example.com

# WordPress Site Info
WP_TITLE=My Inception Site
WP_URL=https://maxime.42.fr
```

**Important**: 
- Never commit the `.env` file to Git
- Use strong passwords for all accounts
- The admin username must NOT contain "admin" or "administrator"

### Secrets

All sensitive information (passwords, credentials) is stored in environment variables via the `.env` file. This file is:
- Ignored by Git (listed in `.gitignore`)
- Read by Docker Compose at runtime
- Never included in Docker images

---

## Building and Launching

### Using the Makefile

The Makefile provides convenient commands for managing the entire stack:

#### Build and Start Everything

```bash
make
# or
make all
```

This command will:
1. Create necessary host directories (`~/data/mariadb` and `~/data/wordpress`)
2. Build all Docker images from Dockerfiles
3. Start all containers using Docker Compose

#### Stop Containers

```bash
make down
```

Stops and removes containers, but preserves volumes and images.

#### Clean Everything

```bash
make fclean
```

Removes containers, networks, volumes, images, and host data directories.

**Warning**: This will delete all your data!

#### Rebuild Everything

```bash
make re
```

Equivalent to `make fclean && make all`.

### Using Docker Compose Directly

For more control, you can use Docker Compose commands directly:

```bash
cd srcs

# Build images only
docker compose build

# Build without cache
docker compose build --no-cache

# Start containers in foreground (see logs)
docker compose up

# Start containers in background
docker compose up -d

# Stop and remove containers
docker compose down

# Stop and remove containers + volumes
docker compose down -v
```

---

## Managing Containers and Volumes

### Container Management Commands

#### View Running Containers

```bash
docker ps                    # Running containers
docker ps -a                 # All containers
```

#### Access Container Shell

```bash
docker exec -it nginx /bin/sh
docker exec -it wordpress /bin/bash
docker exec -it mariadb /bin/sh
```

#### View Container Logs

```bash
docker logs nginx
docker logs wordpress
docker logs mariadb

# Follow logs in real-time
docker logs -f wordpress

# Last 50 lines
docker logs --tail 50 mariadb
```

#### Restart Containers

```bash
docker restart nginx
docker restart wordpress
docker restart mariadb

# Or using Docker Compose
docker compose restart
```

#### View Container Details

```bash
docker inspect nginx
docker stats                  # Real-time resource usage
```

### Volume Management Commands

#### List Volumes

```bash
docker volume ls
```

You should see:
- `srcs_mariadb-data`
- `srcs_wordpress-data`

#### Inspect Volumes

```bash
docker volume inspect srcs_mariadb-data
docker volume inspect srcs_wordpress-data
```

This shows:
- Mountpoint location on the host
- Driver configuration
- Creation date

#### Backup Volumes

**MariaDB Backup**:
```bash
# Create a database dump
docker exec mariadb mysqldump -u root -p${MYSQL_ROOT_PASSWORD} wordpress > backup.sql

# Backup entire volume
docker run --rm -v srcs_mariadb-data:/data -v $(pwd):/backup \
  alpine tar czf /backup/mariadb-backup.tar.gz -C /data .
```

**WordPress Backup**:
```bash
docker run --rm -v srcs_wordpress-data:/data -v $(pwd):/backup \
  alpine tar czf /backup/wordpress-backup.tar.gz -C /data .
```

#### Restore Volumes

**Restore MariaDB**:
```bash
# From SQL dump
docker exec -i mariadb mysql -u root -p${MYSQL_ROOT_PASSWORD} wordpress < backup.sql

# From tar archive
docker run --rm -v srcs_mariadb-data:/data -v $(pwd):/backup \
  alpine tar xzf /backup/mariadb-backup.tar.gz -C /data
```

#### Remove Volumes

```bash
docker volume rm srcs_mariadb-data
docker volume rm srcs_wordpress-data

# Remove all unused volumes
docker volume prune
```

**Warning**: This will delete all data permanently!

---

## Data Storage and Persistence

### Where Data is Stored

The project uses **Docker named volumes** to persist data. These volumes ensure that data survives container restarts and removals.

#### Volume Configuration

In `docker-compose.yml`, two named volumes are defined:

```yaml
volumes:
  mariadb-data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/data/mariadb
  
  wordpress-data:
    driver: local
    driver_opts:
      type: none
      o: bind
      device: /home/${USER}/data/wordpress
```

This configuration:
- Creates Docker named volumes
- Binds them to specific directories on the host
- Stores all data in `/home/<your_username>/data/`

#### Physical Storage Locations

| Volume | Container Path | Host Path |
|--------|---------------|-----------|
| `mariadb-data` | `/var/lib/mysql` | `~/data/mariadb/` |
| `wordpress-data` | `/var/www/html` | `~/data/wordpress/` |

#### Accessing Volume Data

You can access the data directly on the host machine:

```bash
# View MariaDB data
sudo ls -la ~/data/mariadb/

# View WordPress files
sudo ls -la ~/data/wordpress/
```

**Note**: Files are owned by the container users (`mysql` and `www-data`), so you may need `sudo` to access them.

### How Data Persists

#### Volume Lifecycle

| Action | Containers | Volumes | Data |
|--------|-----------|---------|------|
| `make down` | Removed | **Kept** | ✅ Preserved |
| `docker compose down` | Removed | **Kept** | ✅ Preserved |
| `docker compose down -v` | Removed | Removed | ❌ Lost |
| `make fclean` | Removed | Removed | ❌ Lost |
| Container crash/restart | Restarted | **Kept** | ✅ Preserved |

#### Data Initialization

**MariaDB**:
- On first startup, if `/var/lib/mysql` is empty, the initialization script runs
- Creates the database, users, and sets permissions
- On subsequent startups, existing data is used

**WordPress**:
- On first startup, if `wp-config.php` doesn't exist:
  - Downloads WordPress core
  - Creates `wp-config.php` with database credentials
  - Installs WordPress and creates users
- On subsequent startups, existing installation is used

#### Testing Persistence

To verify that data persists correctly:

```bash
# 1. Create some content in WordPress
# (e.g., create a post, upload images)

# 2. Stop containers
make down

# 3. Restart containers
make up

# 4. Verify that all content is still there
# Your posts, users, uploads should all be intact
```

### Data Consistency

The project ensures data consistency through:

1. **Health checks**: MariaDB must be healthy before WordPress starts
2. **Dependency order**: NGINX waits for WordPress, WordPress waits for MariaDB
3. **Restart policy**: All containers restart automatically on failure
4. **Volume persistence**: Data is never stored in containers, only in volumes

---

## Additional Information

### Network Configuration

The project uses a custom Docker bridge network called `inception-network`. This allows containers to communicate using their service names (e.g., `wordpress` can connect to `mariadb` by name).

### Port Exposure

Only one port is exposed to the host:
- **Port 443** (HTTPS) on the NGINX container

All other communication happens internally via the Docker network.

### Rebuilding Individual Services

To rebuild a specific service:

```bash
cd srcs
docker compose build mariadb    # Rebuild only MariaDB
docker compose build wordpress  # Rebuild only WordPress
docker compose build nginx      # Rebuild only NGINX

# Restart the rebuilt service
docker compose up -d mariadb
```

### Troubleshooting

**Containers won't start**:
```bash
docker compose logs          # View all logs
docker compose logs mariadb  # Check specific service
```

**Database connection errors**:
```bash
# Check if MariaDB is ready
docker exec mariadb mysqladmin ping -h localhost

# Verify user exists
docker exec mariadb mysql -u root -p${MYSQL_ROOT_PASSWORD} \
  -e "SELECT User, Host FROM mysql.user;"
```

**Permission issues with volumes**:
```bash
# Fix ownership on host (if needed)
sudo chown -R $(id -u):$(id -g) ~/data/wordpress
sudo chown -R $(id -u):$(id -g) ~/data/mariadb
```

---

For user-oriented documentation, see [USER_DOC.md](USER_DOC.md).
For project overview and technical details, see [README.md](README.md).
