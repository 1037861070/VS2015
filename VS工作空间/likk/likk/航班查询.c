#include<stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNING

#define FILENAME "resourse.txt"

typedef struct plan_info{
	char number[20];  //航班号
	int up_hour;   //起飞小时
	int up_minute;  //起飞分钟
	int down_hour;   //到达小时
	int dowm_minute;  //到达分钟
}plane;

void input_info(plane *li);//输出文本中航班信息
void query_info(plane *kui,int hour,int minute);//查询航班信息

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



void input_info(plane *li){ 
    int i = 0;
	printf("航班号\t\t起飞时间\t抵达时间\n");
	for (i=0;i<8;i++)
	{
		//变换输出格式
		if (li[i].up_hour<10&&li[i].up_minute<10)
		{
			if (li[i].down_hour<10&&li[i].dowm_minute<0)
			{
				printf("%s\t\t0%d:0%d\t\t0%d:0%d\n",li[i].number,li[i].up_hour,
					li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else if (li[i].down_hour<10&&li[i].dowm_minute>10)
			{	printf("%s\t\t0%d:0%d\t\t0%d:%2d\n",li[i].number,li[i].up_hour,
			li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else if (li[i].down_hour>10&&li[i].dowm_minute<10)
			{
				printf("%s\t\t0%d:0%d\t\t%2d:0%d\n",li[i].number,li[i].up_hour,
					li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else
				printf("%s\t\t0%d:0%d\t\t%2d:%2d\n",li[i].number,li[i].up_hour,
				li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
		}
		else if (li[i].up_hour<10&&li[i].up_minute>10)
		{
			if (li[i].down_hour<10&&li[i].dowm_minute<0)
			{
				printf("%s\t\t0%d:%2d\t\t0%d:0%d\n",li[i].number,li[i].up_hour,
				li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else if (li[i].down_hour<10&&li[i].dowm_minute>10)
			{	
				printf("%s\t\t0%d:%2d\t\t0%d:%2d\n",li[i].number,li[i].up_hour,
			    li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else if (li[i].down_hour>10&&li[i].dowm_minute<10)
			{
				printf("%s\t\t0%d:%2d\t\t%2d:0%d\n",li[i].number,li[i].up_hour,
				li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else
				printf("%s\t\t0%d:%2d\t\t%2d:%2d\n",li[i].number,li[i].up_hour,
				li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
		}
		else if (li[i].up_hour>10&&li[i].up_minute<10)
		{
			if (li[i].down_hour<10&&li[i].dowm_minute<0)
			{
				printf("%s\t\t%2d:0%d\t\t0%d:0%d\n",li[i].number,li[i].up_hour,
					li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else if (li[i].down_hour<10&&li[i].dowm_minute>10)
			{	printf("%s\t\t%2d:0%d\t\t0%d:%2d\n",li[i].number,li[i].up_hour,
			li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else if (li[i].down_hour>10&&li[i].dowm_minute<10)
			{
				printf("%s\t\t%2d:0%d\t\t%2d:0%d\n",li[i].number,li[i].up_hour,
					li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else
				printf("%s\t\t%2d:0%d\t\t%2d:%2d\n",li[i].number,li[i].up_hour,
				li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
		}
		else
			if (li[i].down_hour<10&&li[i].dowm_minute<0)
			{
				printf("%s\t\t%2d:%2d\t\t0%d:0%d\n",li[i].number,li[i].up_hour,
					li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else if (li[i].down_hour<10&&li[i].dowm_minute>10)
			{	printf("%s\t\t%2d:%2d\t\t0%d:%2d\n",li[i].number,li[i].up_hour,
			li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else if (li[i].down_hour>10&&li[i].dowm_minute<10)
			{
				printf("%s\t\t%2d:%2d\t\t%2d:0%d\n",li[i].number,li[i].up_hour,
					li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
			}
			else
				printf("%s\t\t%2d:%2d\t\t%2d:%2d\n",li[i].number,li[i].up_hour,
				li[i].up_minute,li[i].down_hour,li[i].dowm_minute);
	}
	
}

void query_info(plane *kui,int hour,int minute){//查询函数
	int i=1,time,ncount=0,distance,Min;
	plane likui[8];
	time=hour*60+minute;//得到换算后给出的时间总秒数
	distance=kui[0].up_hour*60+kui[0].up_minute-time;//得到换算后给出的时间总秒数与第一个航班信息之差
	Min=abs(distance);//绝对值
	//找到最少的那个时间，得到它在数组中位置
	while (i!=8)
	{
		distance=kui[i].up_hour*60+kui[i].up_minute-time;
		if (Min>abs(distance))
		{
			Min=abs(distance);
			ncount=i;
		}
		i++;
	}
	printf("*******离此时间最近的航班信息如下所示*******\n");
	printf("航班号\t\t起飞时间\t抵达时间\n");
	
	//变换输出格式
	if (kui[ncount].up_hour<10&&kui[ncount].up_minute<10)
	{
		if (kui[ncount].down_hour<10&&kui[ncount].dowm_minute<0)
		{
			printf("%s\t\t0%d:0%d\t\t0%d:0%d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else if (kui[ncount].down_hour<10&&kui[ncount].dowm_minute>10)
		{	
			printf("%s\t\t0%d:0%d\t\t0%d:%2d\n",kui[ncount].number,kui[ncount].up_hour,
		    kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else if (kui[ncount].down_hour>10&&kui[ncount].dowm_minute<10)
		{
			printf("%s\t\t0%d:0%d\t\t%2d:0%d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else
			printf("%s\t\t0%d:0%d\t\t%2d:%2d\n",kui[ncount].number,kui[ncount].up_hour,
			kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
	}
	else if (kui[ncount].up_hour<10&&kui[ncount].up_minute>10)
	{
		if (kui[ncount].down_hour<10&&kui[ncount].dowm_minute<0)
		{
			printf("%s\t\t0%d:%2d\t\t0%d:0%d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else if (kui[ncount].down_hour<10&&kui[ncount].dowm_minute>10)
		{	
			printf("%s\t\t0%d:%2d\t\t0%d:%2d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else if (kui[ncount].down_hour>10&&kui[ncount].dowm_minute<10)
		{
			printf("%s\t\t0%d:%2d\t\t%2d:0%d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else
			printf("%s\t\t0%d:%2d\t\t%2d:%2d\n",kui[ncount].number,kui[ncount].up_hour,
			kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
	}
	else if (kui[ncount].up_hour>10&&kui[ncount].up_minute<10)
	{
		if (kui[ncount].down_hour<10&&kui[ncount].dowm_minute<0)
		{
			printf("%s\t\t%2d:0%d\t\t0%d:0%d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else if (kui[ncount].down_hour<10&&kui[ncount].dowm_minute>10)
		{	printf("%s\t\t%2d:0%d\t\t0%d:%2d\n",kui[ncount].number,kui[ncount].up_hour,
		kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else if (kui[ncount].down_hour>10&&kui[ncount].dowm_minute<10)
		{
			printf("%s\t\t%2d:0%d\t\t%2d:0%d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else
			printf("%s\t\t%2d:0%d\t\t%2d:%2d\n",kui[ncount].number,kui[ncount].up_hour,
			kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
	}
	else
		{if (kui[ncount].down_hour<10&&kui[ncount].dowm_minute<0)
		{
			printf("%s\t\t%2d:%2d\t\t0%d:0%d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else if (kui[ncount].down_hour<10&&kui[ncount].dowm_minute>10)
		{	printf("%s\t\t%2d:%2d\t\t0%d:%2d\n",kui[ncount].number,kui[ncount].up_hour,
		kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else if (kui[ncount].down_hour>10&&kui[ncount].dowm_minute<10)
		{
			printf("%s\t\t%2d:%2d\t\t%2d:0%d\n",kui[ncount].number,kui[ncount].up_hour,
				kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
		}
		else
			printf("%s\t\t%2d:%2d\t\t%2d:%2d\n",kui[ncount].number,kui[ncount].up_hour,
			kui[ncount].up_minute,kui[ncount].down_hour,kui[ncount].dowm_minute);
}
	printf("\n");
}