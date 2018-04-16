#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//头文件库


char TOKEN[30];
char *table[7]={" ","begin","if","then","while","do","end"};
//定义关键字
extern int lookup(char*);
extern void out(int,char*);
extern void report_error(void);
//函数及全局变量声明
/*extern可置于变量或者函数前，以表示变量或者函数的定义在别的文件中，提示编译器遇到此变量和函数时在其他模块中寻找其定义。另外，extern也可用来进行链接指定*/

int lookup(char *TOKEN)
{
	int m,i;
	for(i=1;i<6;i++)
	{
		if((m=strcmp(TOKEN,table[i]))==0)
			//table中关键字匹配
			return i;
	}
	return 0;
}
//关键字匹配函数，返回关键字在表中的位置,空出空格

void out(int c,char *TOKEN)
{
	printf("(%d,%s)\n",c,TOKEN);
}
//输出在表中位置和读取的字符

void report_error()
{
	printf("error! there is a identifier error!\n");
	
}
//输出没有考虑的情况

void scanner(FILE *fp)
{
	char TOKEN[30]={'\0'};
	char ch;
	int i,c;
	ch=fgetc(fp);
	//获取字符，指针fp并自动指向下一个字符
	if(isalpha(ch))
		//判断该字符是否是字母
	{
		TOKEN[0]=ch;
		ch=fgetc(fp);
		i=1;
		while(isalnum(ch))
			//判断该字符是否是字母或数字
		{
			TOKEN[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		TOKEN[i]='\0';
		fseek(fp,-1,1);
		//回退一个字符
		c=lookup(TOKEN);
		if(c==0)
			out(10,TOKEN);
		//输出标识符号,定编号为10
		else
			out(c,TOKEN);
		//输出表中编号和关键字
	}
	else if(isdigit(ch))
		//判断是否是数字
	{
		TOKEN[0]=ch;
		ch=fgetc(fp);
		i=1;
		while(isdigit(ch))
		{
			TOKEN[i]=ch;
			i++;
			ch=fgetc(fp);}
		while (isalpha(ch))
		{
			report_error();
			fseek(fp,-1,SEEK_END);
			return ;
		}
		//判断是否是连续数字
		TOKEN[i]='\0';
		fseek(fp,0,1);
		out(11,TOKEN);
		//输出数字,定编号为11
		
		


		}
	else//读取的第一个既不是数字也不是字母
	{
		TOKEN[0]=ch;
		switch(ch)
		{	
		case'+':out(13,TOKEN);
			break;
		case'-':out(14,TOKEN);
			break;
		case'*':out(15,TOKEN);
			break;
		case'/':out(16,TOKEN);
			break;
		case';':out(26,TOKEN);
			break;
		case':':ch=fgetc(fp);
			//读取下一个字符，判断:,:=
			if(ch=='=')
			{
				TOKEN[1]=ch;
				out(18,TOKEN);
			}
			else
			{
				fseek(fp,-1,1);
				out(17,TOKEN);
			}
			break;
		case'<':ch=fgetc(fp);
			//读取下一个字符，判断<,<=,<>(空标签)
			if(ch=='=')
			{
				TOKEN[1]=ch;
				out(22,TOKEN);
			}
			//判断<=
			else if(ch=='>')
			{
				TOKEN[1]=ch;
				out(21,TOKEN);
			}
			//判断<>空标签
			else
			{
				fseek(fp,-1,1);
				out(20,TOKEN);
			}
			//判断小于号<
			break;
		case'=':out(25,TOKEN);
			break;
			//判断=,==
		case'>':ch=fgetc(fp);
			//读取下一个字符，判断>,>=
			if(ch=='=')
			{
				TOKEN[1]=ch;
				out(24,TOKEN);
			}
			else
			{
				fseek(fp,-1,1);
				out(23,TOKEN);
			}
			break;
		case'#':
			out(0,TOKEN);
			break;
		case'(':out(27,TOKEN);
			break;
		case')':out(28,TOKEN);
			break;
			//判断#(头文件)
		default:report_error();
			break;
		}
	}
}
//扫描函数

int main(void)
{
	FILE *fp;
	char ch;
	if((fp=fopen(".\\111.txt","r"))==NULL)
		//取当前目录下的tk.txt文件的第一个字符
	{
		fprintf(stderr,"error opening!\n");
		//格式化输出到流
		//错误打印到屏幕上By default, standard input is read from the keyboard, while standard output and //standard error are printed to the screen
		exit(1);
		//非0，非正常退出
	}
	do
	{
		ch=fgetc(fp);
		if(ch=='#')
			break;
		//作为文件结尾
		else if(ch==' ')
			scanner(fp);
		//空格略过

		else
		{
			fseek(fp,-1,1);
			scanner(fp);
		}
		//扫描
	}while(ch!='#');
	printf("(0,#)\n");
	system("pause");
	return 0;
}
