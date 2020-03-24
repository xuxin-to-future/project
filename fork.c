/*************************************************************************
	> File Name: fork.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月24日 星期二 19时48分11秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    int pid, x = 0;
    for(int i = 1; i <= 10; i++){
        pid = fork();
        if(pid < 0){
            perror("fork()");
            continue;
        }
        if(pid == 0){
            x = i;
            break;
        }
    }
    printf("I'm %dth child.\n", x);
    sleep(60);
    return 0;
}
