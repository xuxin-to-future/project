/*************************************************************************
	> File Name: more.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月21日 星期六 19时30分50秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define PAGELINE 10
#define LENLINE 512

void do_more(FILE *);
int get_cmd(FILE *);

int main(int argc, char *argv[]){
    FILE *fp;
    if(argc == 1){
        do_more(stdin);
    }else{
        while(--argc){
            if((fp = fopen(*++argv, "r")) != NULL){
                do_more(fp);
                fclose(fp);
            }
        }
    }
    return 0;
}

void do_more(FILE *fp){
    char line[LENLINE] = {0};
    FILE *cmd = fopen("/dev/tty", "r");
    int num_line = 0, response;//响应
    while(fgets(line, LENLINE, fp)){
        if(num_line == PAGELINE){
            response = get_cmd(cmd);
            if(response == 0) break;
            num_line -= response;
        }
        if(fputs(line, stdout) == EOF){
            perror("fputs");
            exit(1);
        }
        num_line++;
    }
}

int get_cmd(FILE *fp){
    //printf("more:");
    char c;
    while((c = fgetc(fp)) != EOF){
        switch(c){
            case 'q': return 0;
            case ' ': return PAGELINE;
            case '\n': return 1;
            default: return -1;
        }
    }
}
