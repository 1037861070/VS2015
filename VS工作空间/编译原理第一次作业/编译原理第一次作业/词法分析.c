#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

//ͷ�ļ���


char TOKEN[30];
char *table[7]={" ","begin","if","then","while","do","end"};
//����ؼ���
extern int lookup(char*);
extern void out(int,char*);
extern void report_error(void);
//������ȫ�ֱ�������
/*extern�����ڱ������ߺ���ǰ���Ա�ʾ�������ߺ����Ķ����ڱ���ļ��У���ʾ�����������˱����ͺ���ʱ������ģ����Ѱ���䶨�塣���⣬externҲ��������������ָ��*/

int lookup(char *TOKEN)
{
	int m,i;
	for(i=1;i<6;i++)
	{
		if((m=strcmp(TOKEN,table[i]))==0)
			//table�йؼ���ƥ��
			return i;
	}
	return 0;
}
//�ؼ���ƥ�亯�������عؼ����ڱ��е�λ��,�ճ��ո�

void out(int c,char *TOKEN)
{
	printf("(%d,%s)\n",c,TOKEN);
}
//����ڱ���λ�úͶ�ȡ���ַ�

void report_error()
{
	printf("error! there is a identifier error!\n");
	
}
//���û�п��ǵ����

void scanner(FILE *fp)
{
	char TOKEN[30]={'\0'};
	char ch;
	int i,c;
	ch=fgetc(fp);
	//��ȡ�ַ���ָ��fp���Զ�ָ����һ���ַ�
	if(isalpha(ch))
		//�жϸ��ַ��Ƿ�����ĸ
	{
		TOKEN[0]=ch;
		ch=fgetc(fp);
		i=1;
		while(isalnum(ch))
			//�жϸ��ַ��Ƿ�����ĸ������
		{
			TOKEN[i]=ch;
			i++;
			ch=fgetc(fp);
		}
		TOKEN[i]='\0';
		fseek(fp,-1,1);
		//����һ���ַ�
		c=lookup(TOKEN);
		if(c==0)
			out(10,TOKEN);
		//�����ʶ����,�����Ϊ10
		else
			out(c,TOKEN);
		//������б�ź͹ؼ���
	}
	else if(isdigit(ch))
		//�ж��Ƿ�������
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
		//�ж��Ƿ�����������
		TOKEN[i]='\0';
		fseek(fp,0,1);
		out(11,TOKEN);
		//�������,�����Ϊ11
		
		


		}
	else//��ȡ�ĵ�һ���Ȳ�������Ҳ������ĸ
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
			//��ȡ��һ���ַ����ж�:,:=
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
			//��ȡ��һ���ַ����ж�<,<=,<>(�ձ�ǩ)
			if(ch=='=')
			{
				TOKEN[1]=ch;
				out(22,TOKEN);
			}
			//�ж�<=
			else if(ch=='>')
			{
				TOKEN[1]=ch;
				out(21,TOKEN);
			}
			//�ж�<>�ձ�ǩ
			else
			{
				fseek(fp,-1,1);
				out(20,TOKEN);
			}
			//�ж�С�ں�<
			break;
		case'=':out(25,TOKEN);
			break;
			//�ж�=,==
		case'>':ch=fgetc(fp);
			//��ȡ��һ���ַ����ж�>,>=
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
			//�ж�#(ͷ�ļ�)
		default:report_error();
			break;
		}
	}
}
//ɨ�躯��

int main(void)
{
	FILE *fp;
	char ch;
	if((fp=fopen(".\\111.txt","r"))==NULL)
		//ȡ��ǰĿ¼�µ�tk.txt�ļ��ĵ�һ���ַ�
	{
		fprintf(stderr,"error opening!\n");
		//��ʽ���������
		//�����ӡ����Ļ��By default, standard input is read from the keyboard, while standard output and //standard error are printed to the screen
		exit(1);
		//��0���������˳�
	}
	do
	{
		ch=fgetc(fp);
		if(ch=='#')
			break;
		//��Ϊ�ļ���β
		else if(ch==' ')
			scanner(fp);
		//�ո��Թ�

		else
		{
			fseek(fp,-1,1);
			scanner(fp);
		}
		//ɨ��
	}while(ch!='#');
	printf("(0,#)\n");
	system("pause");
	return 0;
}
