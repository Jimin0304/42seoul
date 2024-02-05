FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y mariadb-server

COPY ./conf/my.cnf /etc/mysql/
COPY ./tools/start_mariadb.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/start_mariadb.sh

EXPOSE 3306

ENTRYPOINT ["start_mariadb.sh"]