#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int CharCount(char *file)// �����ļ�file.c���ַ���
{
  FILE *path=fopen(file,"r");
  int ch,num=0;//num��ʾ�ַ��� 
  if(NULL==path)
    {
	 printf("�ļ���ȡʧ�ܣ�");
	 system("pause"); 
	 exit(-1);
    }
  ch=fgetc(path);//��Ϊ����ԭ�򣬲����ַ����ܱ�ʵ����Ŀ+1��ֻ���Դ˷������� 
     while(!feof(path))
	   {
	   	ch=fgetc(path);
	   	if(ch!=' '&&ch!='\n'&&ch!='\t') 
	   	num++;
	   }	
   fclose(path);    
   printf("�ļ��е��ַ���Ϊ��%d\n",num);
   return num;
}


int WordCount(char *file)// �����ļ�file.c�Ĵʵ���Ŀ 
{
  FILE *path=fopen(file,"r");
  int ch,num=0,flag;//num��ʾ���� 
  if(NULL==path)
    {
	 printf("�ļ���ȡʧ�ܣ�");
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
  printf("�ļ��еĵ�����Ϊ��%d\n",num);
  return num;
}


int LineCount(char *file)// �����ļ�file.c������
{
  FILE *path=fopen(file,"r");
  int ch,num=0;//num��ʾ���� 
  if(NULL==path)
    {
	 printf("�ļ���ȡʧ�ܣ�");
	 system("pause"); // 
	 exit(-1);
    }
  if(ch=fgetc(path)&&!feof(path))//��Կ��ļ���� 
  num++;
     while(!feof(path))
	   {
	   	ch=fgetc(path);
	   	if(ch=='\n')
	   	    num++;
	   }
  fclose(path);  	     	  
  printf("�ļ��е�����Ϊ��%d\n",num);
  return num;
}

int main()
{
	char name[30];	
	printf("������������Ҫͳ�Ƶ��ļ���:") ;
	scanf("%s",name);
	printf("\n");
    CharCount(name);
    WordCount(name);
    LineCount(name);
    system("pause"); 
}




