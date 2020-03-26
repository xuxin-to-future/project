/*************************************************************************
	> File Name: exec.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月26日 星期四 18时13分28秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv){
    pid_t pid;
    char filename[512] = {0};
    char o_name[512] = {0};
    char f_type[256] = {0};
    char cmd[521] = {0};
    if(argc < 2) {
        fprintf(stderr, "Usage : %s filename arg...\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    //找文件名后缀
    char *sub;
    sub = strstr(filename, ".");
    strncpy(o_name, filename, sub - filename);
    strcpy(f_type, sub);

    if(!strcmp(f_type, ".c")) {
        strcpy(cmd, "gcc");
    } else if (!strcmp(f_type, ".cpp")){
        strcpy(cmd, "g++");
    } else {
        fprintf(stderr, "not support file type!\n");
        return 2;
    }

    
    if((pid = fork()) <  0){
        perror("fork");
        return 3;
    }

    if(pid == 0){//子进程进行vim
        execlp("vim", "vim", filename, NULL);
    }

    wait(NULL);//等待子进程结束
    
    if((pid = fork()) < 0){
        perror("fork");
        return 3;//资源错误返回3
    }
    if(pid == 0) {
        execlp(cmd, cmd, filename, "-o", o_name, NULL);//gcc file -o o_name

    }

    int status;
    wait(&status);
    if(status == 0) {
        printf("编译成功，下方显示输出：\n");
        execl(o_name, o_name, NULL);
    }else{
        printf("Failed\n");
        return 4;
    }

    return 0;
}
