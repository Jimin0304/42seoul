#!/bin/sh

set -e

mkdir -p /etc/nginx/ssl

if [ ! -e /etc/nginx/ssl/jimpark.42.fr.crt ]; then
    openssl req -newkey rsa:2048 -days 365 -nodes -x509 \
		-subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Gam/CN=localhost" \
		-out /etc/ssl/certs/jimpark.42.fr.crt \
		-keyout /etc/ssl/private/jimpark.42.fr.key
fi