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
