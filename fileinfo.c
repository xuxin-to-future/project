/*************************************************************************
	> File Name: fileinfo.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月15日 星期日 21时00分23秒
 ************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int show_stat_info(char *fname, struct stat *buf){
    printf(" mode : %o\n", buf->st_mode);
    printf(" links: %ld\n", buf->st_nlink);
    printf(" user: %d\n", buf->st_uid);
    printf(" group: %d\n", buf->st_gid);
    printf(" size: %ld\n", buf->st_size);
    printf("modetime: %ld\n", buf->st_mtime);
    printf(" name: %s\n", fname);
}

int main(int argc, char *argv[]){
    struct stat info;
    if(argc > 1){
        if( stat(argv[1], &info) != -1){
            show_stat_info(argv[1], &info);
            return 0;
        }
    }else{
        perror(argv[1]);
        return 1;
    }
}
