#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int CharCount(char *file)// 返回文件file.c的字符数
{
  FILE *path=fopen(file,"r");
  int ch,num=0;//num表示字符数 
  if(NULL==path)
    {
	 printf("文件读取失败！");
	 system("pause"); 
	 exit(-1);
    }
  ch=fgetc(path);//因为不明原因，测试字符数总比实际数目+1，只能以此方法纠正 
     while(!feof(path))
	   {
	   	ch=fgetc(path);
	   	if(ch!=' '&&ch!='\n'&&ch!='\t') 
	   	num++;
	   }	
   fclose(path);    
   printf("文件中的字符数为：%d\n",num);
   return num;
}


int WordCount(char *file)// 返回文件file.c的词的数目 
{
  FILE *path=fopen(file,"r");
  int ch,num=0,flag;//num表示词数 
  if(NULL==path)
    {
	 printf("文件读取失败！");
	 system("pause"); 
	 exit(-1);
    }

    while(!feof(path))
	   {
	   	ch=fgetc(path);
	   	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
	   	    flag=0;
	   	else if(flag==0)
	   	       {
	   	       	flag=1;
	   	       	num++;
	   	       }
	   }
  fclose(path);    	  
  printf("文件中的单词数为：%d\n",num);
  return num;
}


int LineCount(char *file)// 返回文件file.c的行数
{
  FILE *path=fopen(file,"r");
  int ch,num=0;//num表示行数 
  if(NULL==path)
    {
	 printf("文件读取失败！");
	 system("pause"); // 
	 exit(-1);
    }
  if(ch=fgetc(path)&&!feof(path))//针对空文件情况 
  num++;
     while(!feof(path))
	   {
	   	ch=fgetc(path);
	   	if(ch=='\n')
	   	    num++;
	   }
  fclose(path);  	     	  
  printf("文件中的行数为：%d\n",num);
  return num;
}

int main()
{
	char name[30];	
	printf("请输入您所需要统计的文件名:") ;
	scanf("%s",name);
	printf("\n");
    CharCount(name);
    WordCount(name);
    LineCount(name);
    system("pause"); 
}




