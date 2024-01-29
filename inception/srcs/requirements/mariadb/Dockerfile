FROM debian:bullseye

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y mariadb-server

COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/
COPY ./tools/start_mariadb.sh /usr/local/bin/

EXPOSE 3306

ENTRYPOINT ["sh", "/usr/local/bin/start_mariadb.sh"]