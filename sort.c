/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月17日 星期二 10时14分45秒
 ************************************************************************/

#include<stdio.h>

#include<string.h>

 

void main()

{

       char str[8][9]={"CHINA","JAPAN","KOREA","INDIA","CANADA","AMERICAN","ENGLAND","FRANCE"};

       char temp[9];

       int i,l;

    for (i=0;i<8;i++)

       {

              for(l=0;l<9;l++)

              {

                     printf("%c",str[i][l]);

              }

              printf("\n");

       }

       //排序

       printf("以上8个国家按字典中排序如下所示：\n");

       int j,k;

       for(j=0;j<8;j++)

       for(k=j+1;k<8;k++)

       {

                     if(strcmp(str[j],str[k])>0)

                     {//交换

                            strcpy(temp,str[j]);

                            strcpy(str[j],str[k]);

                            strcpy(str[k],temp); 

                     }

       }

              for(i=0;i<8;i++)//输出

                     printf("%s\n",str[i]);

}
