/*************************************************************************
	> File Name: sort1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月17日 星期二 10时17分06秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>

int main(){
    char str[6][9]={"china", "japan","korea", "india", "canada", "america"};
    char temp[9];
    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            if(strcmp(str[i], str[j]) > 0){
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }
    for(int i = 0; i < 6; i++){
        printf("%s\n", str[i]);
    }
}
