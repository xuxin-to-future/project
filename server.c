/*************************************************************************
	> File Name: socket.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时05分22秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

int main(int argc, char **argv){
    if(argc != 2){
        fprintf(stderr,"Usage: %s port\n", argv[0]);
        exit(1);
    }

    int port, server_listen;

    port = atoi(argv[1]);//端口

    if((server_listen = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        perror("socket");
        exit(1);
    }
    
    printf("Socket create.\n");
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);//地址转换
    server.sin_addr.s_addr = INADDR_ANY;


    if(bind(server_listen, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("bind");
        exit(1);
    }

    printf("Socket bind.\n");
    if(listen(server_listen, 20) < 0){
        perror("server");
        exit(1);
    }

    while(1){
        int sockfd;
        printf("Socket before accept.\n");
        if((sockfd = accept(server_listen, NULL, NULL)) < 0){
            perror("accept");
            close(sockfd);
            continue;
        }
        
        pid_t pid;
        if((pid = fork()) < 0){
            perror("fork");
            continue;
        }
        
        if(pid == 0){    
            close(server_listen);
            char name[20] = {0};
            if(recv(sockfd, name, sizeof(name), 0) <= 0){
                perror("recv");
                close(sockfd);
            }
            printf("%s\n", name);
            exit(0);
        }
    }
    return 0;
}
