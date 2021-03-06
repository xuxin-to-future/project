/*************************************************************************
	> File Name: client.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 14时53分45秒
 ************************************************************************/

#include "head.h"
#include "tcp_client.h"

int main(int argc, char **argv){
    int sockfd;
    if(argc != 3){
        fprintf(stderr, "usage: %s ip port\n", argv[0]);
        return 1;
    }
    if((sockfd = socket_connect(argv[1], atoi(argv[2]))) < 0){
        perror("socket_connect");
        return 2;
    }
    return 0;
}
