# Inception

*This project has been created as part of the 42 curriculum by maxime.*

## Description

Inception is a system administration and containerization project that involves setting up a small infrastructure composed of different services using Docker. The goal is to virtualize several Docker images and create them in a personal virtual machine.

The project consists of setting up:
- A Docker container with NGINX and TLSv1.2 or TLSv1.3
- A Docker container with WordPress + php-fpm (without nginx)
- A Docker container with MariaDB (without nginx)
- A volume for the WordPress database
- A volume for the WordPress website files
- A docker-network to establish connections between containers

All services run in dedicated containers built from the penultimate stable version of Alpine or Debian.

## Instructions

### Prerequisites

- Docker
- Docker Compose
- Make
- A domain name configured to point to your local machine (e.g., `<login>.42.fr`)

### Installation & Execution

1. Clone the repository:
```bash
git clone <repository-url> inception
cd inception
```

2. Configure your environment:
```bash
# Copy and edit the environment variables
cp srcs/.env.example srcs/.env
# Edit srcs/.env with your credentials
vim srcs/.env
```

3. Build and run the project:
```bash
make
```

4. Stop the project:
```bash
make down
```

5. Clean up everything (containers, volumes, images):
```bash
make fclean
```

### Accessing Services

- **WordPress Website**: https://<your_login>.42.fr
- **WordPress Admin Panel**: https://<your_login>.42.fr/wp-admin

## Project Design & Technical Choices

### Docker in This Project

This project uses Docker to containerize each service independently, ensuring isolation, portability, and easier management. Each service (NGINX, WordPress, MariaDB) runs in its own container, built from custom Dockerfiles based on Alpine or Debian.

The infrastructure is orchestrated using Docker Compose, which manages the networking, volumes, and dependencies between containers.

### Key Technical Comparisons

#### Virtual Machines vs Docker

| Aspect | Virtual Machines | Docker |
|--------|------------------|--------|
| **Architecture** | Full OS virtualization with hypervisor | OS-level virtualization using containers |
| **Resource Usage** | Heavy (GBs of RAM per VM) | Lightweight (MBs of RAM per container) |
| **Boot Time** | Minutes | Seconds |
| **Isolation** | Complete isolation with separate kernel | Process-level isolation, shared kernel |
| **Performance** | Overhead due to hypervisor layer | Near-native performance |
| **Use Case** | Running different OS, strong isolation needs | Microservices, CI/CD, development environments |

**Choice for this project**: Docker is used because it provides sufficient isolation for services while being more resource-efficient and faster to deploy than VMs.

#### Secrets vs Environment Variables

| Aspect | Secrets | Environment Variables |
|--------|---------|----------------------|
| **Security** | Encrypted at rest and in transit | Stored in plain text |
| **Visibility** | Limited exposure, not in container inspect | Visible in container inspect and logs |
| **Rotation** | Easier to rotate without rebuilding | Requires restart/rebuild |
| **Best For** | Passwords, API keys, certificates | Configuration values, non-sensitive data |

**Choice for this project**: Environment variables are used via `.env` file for configuration. For production environments, Docker secrets or other secret management solutions would be preferred for sensitive credentials.

#### Docker Network vs Host Network

| Aspect | Docker Network (Bridge) | Host Network |
|--------|------------------------|--------------|
| **Isolation** | Containers have isolated network namespace | Container shares host's network namespace |
| **Port Mapping** | Requires explicit port publishing | Direct access to all ports |
| **Security** | Better isolation between containers and host | Direct exposure to host network |
| **Performance** | Slight overhead due to NAT | No overhead, native performance |
| **Use Case** | Most containerized applications | Performance-critical apps needing direct network access |

**Choice for this project**: Bridge network is used to create an isolated network for the containers, allowing them to communicate securely while being isolated from the host network.

#### Docker Volumes vs Bind Mounts

| Aspect | Docker Volumes | Bind Mounts |
|--------|----------------|-------------|
| **Management** | Managed by Docker | User-managed file paths |
| **Location** | Docker's storage directory | Any location on host |
| **Portability** | More portable across environments | Path-dependent, less portable |
| **Performance** | Optimized by Docker | Direct file system access |
| **Backup** | Easier with Docker volume commands | Manual backup required |
| **Use Case** | Persistent data, databases | Development, source code mounting |

**Choice for this project**: 
- **Docker Volumes** are used for persistent data (MariaDB database, WordPress files) because they are managed by Docker and provide better portability.
- **Bind Mounts** could be used in development for easier file access, but volumes are preferred for production-like setups.

## Resources

### Classic References

- [Docker Official Documentation](https://docs.docker.com/)
- [Docker Compose Documentation](https://docs.docker.com/compose/)
- [NGINX Documentation](https://nginx.org/en/docs/)
- [WordPress Documentation](https://wordpress.org/support/)
- [MariaDB Documentation](https://mariadb.org/documentation/)
- [Docker Best Practices](https://docs.docker.com/develop/dev-best-practices/)
- [Dockerfile Best Practices](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)

### AI Usage

AI tools were used in this project for the following purposes:

- **Code Review**: Reviewing Dockerfiles and docker-compose.yml for best practices
- **Documentation**: Generating initial drafts of documentation structure
- **Troubleshooting**: Debugging container networking issues and configuration problems
- **Research**: Understanding the differences between various Docker concepts (volumes, networks, etc.)

**Parts of the project created with AI assistance**:
- Initial README.md structure and technical comparisons
- Documentation templates (USER_DOC.md, DEV_DOC.md)
- Configuration examples and troubleshooting guides

**Parts created manually**:
- All Dockerfiles
- Docker Compose configuration
- NGINX configuration
- WordPress setup scripts
- MariaDB initialization scripts
- Makefile
- Environment configuration

## License

This project is part of the 42 school curriculum.
