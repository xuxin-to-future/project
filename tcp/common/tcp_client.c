/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 14时36分15秒
 ************************************************************************/

#include "head.h"

int socket_connect(char *host, int port){
    int fd;
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(host);

    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        return -1;
    }
    printf("socket create\n");
    if(connect(fd, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("connect");
        return -1;
    }
    return fd;
}
