# User Documentation

This document explains how to use the Inception website.

## Table of Contents

1. [Starting and Stopping](#starting-and-stopping)
2. [Accessing the Website](#accessing-the-website)
3. [WordPress Usage](#wordpress-usage)
4. [Common Issues](#common-issues)

---

## Starting and Stopping

### Start the Website

```bash
make
```

Builds and starts all services (NGINX, WordPress, MariaDB).

### Stop the Website

```bash
make down
```

Stops all services but keeps your data.

### Clean Restart

```bash
make re
```

Performs a complete rebuild.

### Delete Everything

```bash
make fclean
```

⚠️ **Warning**: Deletes all data including posts and uploads.

---

## Accessing the Website

### Website URL

**https://maxime.42.fr**

(Replace `maxime` with your login)

### SSL Certificate Warning

Your browser will warn about the self-signed certificate:
1. Click **"Advanced"**
2. Click **"Proceed to site"**

This is normal for development environments.

---

## WordPress Usage

### Admin Dashboard

Access at: **https://maxime.42.fr/wp-admin**

### Credentials

Two accounts are configured:

**Administrator**:
- Username: `mlebard` (check `WP_ADMIN_USER` in `srcs/.env`)
- Password: check `WP_ADMIN_PASSWORD` in `srcs/.env`

**Regular User**:
- Username: `editor` (check `WP_USER` in `srcs/.env`)
- Password: check `WP_USER_PASSWORD` in `srcs/.env`

### View Your Passwords

```bash
cat srcs/.env
```

### Creating Posts

1. Log in to **https://maxime.42.fr/wp-admin**
2. Click **Posts → Add New**
3. Enter title and content
4. Click **Publish**

---

## Common Issues

### Website Not Loading

Check containers are running:
```bash
docker ps
```

Should show 3 containers: `nginx`, `wordpress`, `mariadb`.

Verify domain in `/etc/hosts`:
```bash
cat /etc/hosts | grep 42.fr
```

Should show: `127.0.0.1  maxime.42.fr`

### 502 Bad Gateway

Wait 30 seconds after `make` - WordPress needs time to start.

Check logs:
```bash
docker logs wordpress
docker logs nginx
```

### Can't Login

Verify credentials:
```bash
cat srcs/.env | grep WP_ADMIN
```

### Database Connection Error

Restart the stack:
```bash
make down
make
```

Check MariaDB logs:
```bash
docker logs mariadb
```

---

## Quick Reference

| Task | Command |
|------|---------|
| Start | `make` |
| Stop | `make down` |
| Logs | `docker logs wordpress` |
| Status | `docker ps` |
| Website | https://maxime.42.fr |
| Admin | https://maxime.42.fr/wp-admin |
| Passwords | `cat srcs/.env` |

---

For technical details, see [DEV_DOC.md](DEV_DOC.md).
