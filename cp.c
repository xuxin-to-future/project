/*************************************************************************
	> File Name: cp.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 14时32分37秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZE 512

int main(int argc, char **argv){
    int fd_in, fd_out;
    ssize_t numread;
    char buf[BUFSIZE + 5] = {0};
    if(argc != 3){
        printf("Usage: %s sourcefile destfile\n", argv[0]);
        exit(1);
    }
    
    if((fd_in = open(argv[1], O_RDONLY)) == -1){
        perror(argv[1]);
        exit(1);
    }

    if((fd_out = creat(argv[2], 0644)) == -1){
        perror(argv[2]);
        exit(1);
    }
    
    while((numread = read(fd_in, buf, sizeof(buf))) > 0){
        if(write(fd_out, buf, numread) != numread){
            perror("write");
            exit(1);
        }
    }
    close(fd_in);
    close(fd_out);
    printf("cp success\n");
    return 0;
}
