/*************************************************************************
    > File Name: read_main_param.c
    > Author: Mr.Yang
    > Purpose:读取主函数中的参数 
    > Created Time: 2017年06月01日 星期四 09时46分38秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
        printf("%s\n",argv[0]);//读取可执行程序（包括路径）

        /*读取参数*/
        int i = 1;
        while(i < argc)
        {
                printf("%s\n",argv[i]);
                i++;
        }
        //说明在dos和unix环境下,用""扩起来的表示其是一个字符串，代表着一个参数
        return 0;
}
