#include<stdio.h>
#include "head.h"
int main()
{
	int i=0;
	int hour,minute;
	char number[20];
	char ch;
	int up_hour, up_minute, down_hour, dowm_minute;
	plane li[8];
	FILE* inputFile = fopen(FILENAME, "rt"); //文件指针
	while(fscanf(inputFile, "%s %d:%d %d:%d",&number,&up_hour,&up_minute,&down_hour,&dowm_minute) != EOF) {//将文件中数据格式化读取
		strcpy(li[i].number,number);
		li[i].up_hour = up_hour;
		li[i].up_minute = up_minute;
		li[i].down_hour = down_hour;
		li[i].dowm_minute = dowm_minute;
		i++;
	}
	do 
	{
		printf("*****欢迎进入航班查询系统*****\n");
		printf("1.航班信息显示\n");
		printf("2.查询最近的航班信息\n");
		printf("3.退出\n");
		printf("请输入你要进行的选项：");
		scanf("%d",&i);
		switch(i)
		{
		case 1: input_info(li);//输出文本文件中信息
			   break;
		case 2:
			printf("请输入一个时间（用24小时的时分表示,如:08:05）\n");
			scanf("%d:%d",&hour,&minute);
			query_info(li,hour,minute);
			   break;
		case 3:i=-1;
			printf("谢谢使用！\n");
			break;
		}
		} while (i!=-1);
    system("pause");
	return 0;
}
