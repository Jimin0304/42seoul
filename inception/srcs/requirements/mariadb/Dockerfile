FROM alpine:3.18

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y \
    mariadb-server \
    mariadb-client

COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/
COPY ./tools/start_mariadb.sh /home

EXPOSE 3306

ENTRYPOINT ["sh", "/home/start_mariadb.sh"]