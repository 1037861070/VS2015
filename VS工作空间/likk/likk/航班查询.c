#include<stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNING

#define FILENAME "resourse.txt"

typedef struct plan_info{
	char number[20];  //�����
	int up_hour;   //���Сʱ
	int up_minute;  //��ɷ���
	int down_hour;   //����Сʱ
	int dowm_minute;  //�������
}plane;

void input_info(plane *li);//����ı��к�����Ϣ
void query_info(plane *kui,int hour,int minute);//��ѯ������Ϣ

int main()
{
	int i=0;
	int hour,minute;
	char number[20];
	char ch;
	int up_hour, up_minute, down_hour, dowm_minute;
	plane li[8];
	FILE* inputFile = fopen(FILENAME, "rt"); //�ļ�ָ��
	while(fscanf(inputFile, "%s %d:%d %d:%d",&number,&up_hour,&up_minute,&down_hour,&dowm_minute) != EOF) {//���ļ������ݸ�ʽ����ȡ
		strcpy(li[i].number,number);
		li[i].up_hour = up_hour;
		li[i].up_minute = up_minute;
		li[i].down_hour = down_hour;
		li[i].dowm_minute = dowm_minute;
		i++;
	}
	do 
	{
		printf("*****��ӭ���뺽���ѯϵͳ*****\n");
		printf("1.������Ϣ��ʾ\n");
		printf("2.��ѯ����ĺ�����Ϣ\n");
		printf("3.�˳�\n");
		printf("��������Ҫ���е�ѡ�");
		scanf("%d",&i);
		switch(i)
		{
		case 1: input_info(li);//����ı��ļ�����Ϣ
			break;
		case 2:
			printf("������һ��ʱ�䣨��24Сʱ��ʱ�ֱ�ʾ,��:08:05��\n");
			scanf("%d:%d",&hour,&minute);
			query_info(li,hour,minute);
			break;
		case 3:i=-1;
			printf("ллʹ�ã�\n");
			break;
		}
	} while (i!=-1);
	system("pause");
	return 0;
}



void input_info(plane *li){ 
    int i = 0;
	printf("�����\t\t���ʱ��\t�ִ�ʱ��\n");
	for (i=0;i<8;i++)
	{
		//�任�����ʽ
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

void query_info(plane *kui,int hour,int minute){//��ѯ����
	int i=1,time,ncount=0,distance,Min;
	plane likui[8];
	time=hour*60+minute;//�õ�����������ʱ��������
	distance=kui[0].up_hour*60+kui[0].up_minute-time;//�õ�����������ʱ�����������һ��������Ϣ֮��
	Min=abs(distance);//����ֵ
	//�ҵ����ٵ��Ǹ�ʱ�䣬�õ�����������λ��
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
	printf("*******���ʱ������ĺ�����Ϣ������ʾ*******\n");
	printf("�����\t\t���ʱ��\t�ִ�ʱ��\n");
	
	//�任�����ʽ
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