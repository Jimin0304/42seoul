FROM debian:bullseye 

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install nginx -y && \
    apt-get install openssl -y

COPY  ./conf/default /etc/nginx/sites-available/

COPY ./tools/ssl-keygen.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/ssl-keygen.sh && ssl-keygen.sh

EXPOSE 443

ENTRYPOINT     ["nginx", "-g", "daemon off;"]