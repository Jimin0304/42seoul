FROM debian:bullseye

RUN apt-get update && \
    apt-get install -y php7.4-fpm && \
    apt-get install -y php-mysql && \
    apt-get install -y mariadb-client && \
    apt-get install -y wget

RUN mkdir /run/php

COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/
COPY ./tools/start_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/start_wordpress.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT [ "start_wordpress.sh" ]