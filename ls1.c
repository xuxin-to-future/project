/*************************************************************************
	> File Name: ls1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月17日 星期二 11时20分44秒
 ************************************************************************/

#include<stdio.h>
#include <stdio.h>
#include <string.h>
#include "dirent.h"
#define
#define
#define
#define
#define
#define
#define
#define
RED "\033[0;32;31m"
GREEN "\033[0;32;32m"
BLUE "\033[0;32;34m"
CYAN "\033[0;36m"
PURPLE "\033[0;35m"
BROWN "\033[0;33m"
YELLOW "\033[1;33m"
WHITE "\033[1;37m"
int output(char dirname[], int flag) {
DIR *dir = NULL;
struct dirent *file;
if ((dir = opendir(dirname)) == NULL) {
printf("
\'%s\'
\n", dirname);
return 1;
}
while (file = readdir(dir)) {
if (flag == 1 && file->d_name[0] == '.') continue;
switch (file->d_type) {
case 1: printf(RED"%s ", file->d_name);break;
case 2: printf(GREEN"%s ", file->d_name);break;
case 4: printf(BLUE"%s ", file->d_name);break;
case 6: printf(CYAN"%s ", file->d_name);break;
case 8: printf(PURPLE"%s ", file->d_name);break;
case 10: printf(BROWN"%s ", file->d_name);break;
case 12: printf(YELLOW"%s ", file->d_name);break;
case 14: printf(WHITE"%s ", file->d_name);break;
}
}
printf("\n");
closedir(dir);
return 0;
}
无法访问
:没有那个文件或目录
void output_argv(char *argv[]) {
for (int i = 0; argv[i]; i++) {
    printf("%s ", argv[i]);
}
printf("\n");
}
int main(int argc, char *argv[]) {
if (argc == 1) {
return output(".", 1);
}
else {
char *filename;
filename = ".";
int flag = 1;
for (int i = 1; argv[i]; i++) {
if (argv[i][0] == '-') {
for (int j = 1; argv[i][j]; j++) {
if (argv[i][j] == 'a') flag = 2;
}
}
else{
filename = argv[i];
}
}
return output(filename, flag);
}
return 0;
}
