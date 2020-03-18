/*************************************************************************
	> File Name: a.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月12日 星期四 22时29分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(){
    freopen("day.txt","w",stdout);
    for(int i = 0; i <= 1000; i++){
        printf("0\n");
    }
    fclose(stdout);
    return 0;
}
