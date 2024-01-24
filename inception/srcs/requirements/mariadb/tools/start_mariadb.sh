#!/bin/sh

# 명령어 실패하면 즉시 종료
set -e

MYSQL_SETUP_FILE=/var/lib/mysql/.setup

service mariadb start

if [ ! -e $MYSQL_SETUP_FILE ]; then # 처음에만 실행되도록 하기 위해서

	# mysql -e : mysql 에서 명령을 실행하라는 의미
	
	mysql -e "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE";
	mysql -e "CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'";
	mysql -e "GRANT ALL PRIVILEGES ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%'";
	mysql -e "FLUSH PRIVILEGES";
	mysql -e "ALTER USER '$MYSQL_ROOT'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'";

	touch $MYSQL_SETUP_FILE
fi

mysql $MYSQL_DATABASE -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD
mysqladmin -u$MYSQL_ROOT -p$MYSQL_ROOT_PASSWORD shutdown

exec mysqld_safe