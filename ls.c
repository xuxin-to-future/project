#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/sysmacros.h>

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define CYAN "\033[0;36m"
#define PURPLE "\033[0;35m"
#define BROWN "\033[0;33m"
#define YELLOW "\033[0;33m"
#define WHITE "\033[1;37m"


void file_operation(char **);
void do_ls(char[]);
void do_stat(struct dirent *, char *);
long int show_file_info(struct dirent *, struct stat *);
void mode_to_letters(int, char[]);
char *uid_to_name(uid_t);
char *gid_to_name(gid_t);
long int file_size_total = 0;
void show_color(struct dirent *, char *, char str[]);


int main(int argc, char *argv[]){
    if(argc == 1){
        do_ls("./");
    }else{
        while(--argc){
            printf("%s\n", *(++argv));
            do_ls(*argv);
        }
    }
    return 0;
}

void do_ls(char dirname[]){
    struct dirent **file_list;
    int n = scandir(dirname, &file_list, 0, alphasort);
    if(n < 0){
        printf("无法访问");
    }else{
        int index = 0;
        while(index < n){
            char *str = (char *)malloc(sizeof(char) * 50);
            strcpy(str, dirname);
            strcat(str, file_list[index]->d_name);
            do_stat(file_list[index], str);
            free(file_list[index++]);
            free(str);
        }
        free(file_list);
    }
    file_size_total /= 1024;
    printf("total %ld\n", file_size_total);
}

void do_stat(struct dirent *direntp, char *filename){
    struct stat info;
    int ret;
    if((ret = stat(filename, &info)) == -1){
        perror("stat");
        exit(EXIT_FAILURE);
    }else{
        file_size_total += show_file_info(direntp, &info);
    }
}

long int show_file_info(struct dirent *direntp, struct stat *info_p){
    char *uid_to_name(), *ctime(), *gid_to_name(), *filemode();
    void mode_to_letters();
    char modestr[11];

    mode_to_letters(info_p->st_mode, modestr);

    printf("%s", modestr);
    printf("%4d ", (int)info_p->st_nlink);
    printf("%-8s", uid_to_name(info_p->st_uid));
    printf("%-8s", gid_to_name(info_p->st_gid));
    printf("%8ld ", (long)info_p->st_size);
    printf("%.12s ", 4+ctime(&info_p->st_mtime));
    show_color(direntp, direntp->d_name, modestr);
    return (long int)info_p->st_size;
}

void show_color(struct dirent *direntp, char *filename, char str[]){
    if(str[3] == 'x' && str[0] != 'd'){
        printf(GREEN"%s\033[0m\n", filename);
        return;
    }
    switch(direntp->d_type){
        case 1: printf(RED"%s\033[0m\n", filename); break;
        case 2: printf(GREEN"%s\033[0m\n ", filename); break;
        case 4: printf(BLUE"%s\033[0m\n", filename); break;
        case 6: printf(CYAN"%s\033[0m\n", filename); break;
        case 8: printf(WHITE"%s\033[0m\n", filename); break;//
        case 10: printf(WHITE"%s\033[0m\n", filename); break;
        case 12: printf(YELLOW"%s\033[0m\n", filename); break;
        case 14: printf(WHITE"%s\033[0m\n", filename); break;
    }
}


void mode_to_letters(int mode, char str[]){
    strcpy(str, "----------");
    if(S_ISDIR(mode)) str[0] = 'd';
    if(S_ISCHR(mode)) str[0] = 'c';
    if(S_ISBLK(mode)) str[0] = 'b';
    if(mode & S_IRUSR) str[1] = 'r';
    if(mode & S_IWUSR) str[2] = 'w';
    if(mode & S_IXUSR) str[3] = 'x';
    if(mode & S_IRGRP) str[4] = 'r';
    if(mode & S_IWGRP) str[5] = 'w';
    if(mode & S_IXGRP) str[6] = 'x';
    if(mode & S_IROTH) str[7] = 'r';
    if(mode & S_IWOTH) str[8] = 'w';
    if(mode & S_IXOTH) str[9] = 'x';
}

char *uid_to_name(uid_t uid){
    struct passwd *getpwuid(), *pw_ptr;
    static char numstr[10];

    if((pw_ptr = getpwuid(uid)) == NULL){
        sprintf(numstr, "%d", uid);
        return numstr;
    }else{
        return pw_ptr->pw_name;
    }
}

char *gid_to_name(gid_t gid){
    struct group *getgrgid(), *grp_ptr;
    static char numstr[10];

    if((grp_ptr = getgrgid(gid)) == NULL){
        sprintf(numstr, "%d", gid);
        return numstr;
    }else{
        return grp_ptr->gr_name;
    }
}
