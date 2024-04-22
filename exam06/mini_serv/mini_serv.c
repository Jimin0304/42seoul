#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

const char *FATAL_ERROR = "Fatal Error\n";
const int BUFFER_SIZE = 42 * 4096;
int max_fd = 0, next_id = 0;
char rbuf[BUFFER_SIZE], wbuf[BUFFER_SIZE];
fd_set current_fds, rfds, wfds;

typedef struct s_client {
    int id;
    char msg[110000];
}   t_client;

t_client clients[1024];

void print_err(const char *str)
{
    write(2, str, strlen(str));
    exit(1);
}

void send_all(int socket)
{
    for (int i = 0; i <= max_fd; i++)
    {
        if (FD_ISSET(i, &wfds) && i != socket)
            send(i, &wbuf, strlen(wbuf), 0);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) 
        print_err("Wrong number of input\n");

    int servsocket = socket(AF_INET, SOCK_STREAM, 0);
    if (servsocket < 0)
        print_err(FATAL_ERROR);
    max_fd = servsocket;

    FD_ZERO(&current_fds);
    bzero(&clients, sizeof(clients));
    FD_SET(servsocket, &current_fds);

    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = htonl(2130706433);

    if (bind(servsocket, (const struct sockaddr *)&addr, len) < 0)
        print_err(FATAL_ERROR);
    if (listen(servsocket, 42) < 0)
        print_err(FATAL_ERROR);

    while(1)
    {
        rfds = wfds = current_fds;
        if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
            continue ;
        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (FD_ISSET(fd, &rfds) && fd == servsocket)
            {
                int new_fd = accept(servsocket, (struct sockaddr *)&addr, &len);
                if (new_fd < 0)
                    continue ;
                FD_SET(new_fd, &current_fds);
                clients[new_fd].id = next_id++;
                max_fd = new_fd > max_fd ? new_fd : max_fd;
                sprintf(wbuf, "server: client %d just arrived\n", clients[new_fd].id);
                send_all(new_fd);
                break ;
            }
            else if (FD_ISSET(fd, &rfds))
            {
                int res = recv(fd, rbuf, BUFFER_SIZE, 0);
                if (res <= 0)
                {
                    sprintf(wbuf, "server: client %d just left\n", clients[fd].id);
                    send_all(fd);
                    FD_CLR(fd, &current_fds);
                    close(fd);
                    break ;
                }
                else
                {
                    for (int i = 0, j = strlen(clients[fd].msg); i < res; i++, j++)
                    {
                        clients[fd].msg[j] = rbuf[i];
                        if (clients[fd].msg[j] == '\n')
                        {
                            clients[fd].msg[j] = '\0';
                            sprintf(wbuf, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                            send_all(fd);
                            bzero(&clients[fd].msg, strlen(clients[fd].msg));
                            j = -1;
                        }
                    }
                    break ;
                }
            }
        }
    }
}