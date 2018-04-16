#include<stdio.h>
#include<math.h>
#include<stdlib.h>


char token[16];//��ؼ���������бȽϣ��ó��������������
char prog[256];//���ڽ����ַ�
char * keyword[6] = { "begin","if","then","while","do" ,"end"};	//�ؼ��ֱ�
int p = 0;	//��������
int syn;	//��ʶ��
double sum = 0;
char ch;//���ܵ���һ���ַ�

int isSignal = 0;	//�Ƿ��������(0:���� 1:���� 2:����)

int isDecimal = 0;  //�Ƿ�С��(0 �� 1 ����)
double decimal = 0; //С��
double temp = 0;
int temp2 = 0;
int isError = 0;

void T();
void F();
void E();

//�ж��Ƿ�Ϊ����
void IsNum()
{
	int count = 0;
	while ((ch >= '0') && (ch <= '9'))
	{
		sum = sum * 10 + ch - '0';
		ch = prog[p++];
	}

	//С������
	if (ch == '.')
	{
		isDecimal = 1;
		ch = prog[p++];
		
		while ((ch >= '0') && (ch <= '9'))
		{
			//pow(x,y)����x��y����
			temp = (ch - '0')*pow(0.1, ++count);
			decimal = decimal + temp;
			ch = prog[p++];
		}
		sum = sum + decimal;
	}

	if (isSignal == 1)
	{
		sum = -sum;
		isSignal = 0;
	}
	p--;
	syn = 11;
}

void scanner()
{
	int i=0,j = 0;
	sum = 0;
	decimal = 0;
	
	ch = prog[p++];
	while (ch == ' ')
		ch = prog[p++];
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))	//����ĸ
	{

		while ((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || (ch>=48 && ch<=57))	//�����ֻ�����ĸ
		{//�жϽ������Ƿ�Ϊ���֣�
			token[i++] = ch;
			ch = prog[p++];
		}
		token[i++] = '\0';
		p--;
		syn = 10;

		for ( j = 0; j < 6; j++)
		{
			if (strcmp(keyword[j], token) == 0)//������ؼ�����ƥ��
			{
				syn = j + 1;//�����ؼ��ִ�������
				break;
			}
		}
	}
	else
	{
		if ((ch >= 48 && ch <= 57))				//������
		{
			IsNum();
		}
		else
		{
			switch (ch)
			{
			case '<':
				i = 0;
				token[i++] = ch;
				ch = prog[p++];
				if (ch == '>')
				{
					syn = 21; //<>��Ӧ21
					token[i++] = ch;
				}
				else if (ch == '=')
				{
					syn = 22;
					token[i++] = ch;
				}
				else
				{
					syn = 20;
					p--;
				}
				break;

			case '>':
				i = 0;
				token[i++] = ch;
				ch = prog[p++];
				if (ch == '=')
				{
					syn = 24;
					token[i++] = ch;
				}
				else
				{
					syn = 23;
					p--;
				}
				break;

			case ':':
				i = 0;
				token[i++] = ch;
				ch = prog[p++];
				if (ch == '=')
				{
					syn = 18;
					token[i++] = ch;
				}
				else
				{
					syn = 17;
					p--;
				}
				break;

			case '+':
				temp2 = prog[p];
				if ((temp2 >= '0') && (temp2 <= '9'))
				{
					isSignal = 2;
					ch = prog[p++];
					IsNum();
				}
				syn = 13;
				token[i++] = ch;
				break;
			case '-':
				temp2 = prog[p];
				if ((temp2 >= '0') && (temp2 <= '9'))
				{
					isSignal = 1;
					ch = prog[p++];
					IsNum();		//ת�����ֵ�ʶ��
				}
				syn = 14;
				token[i++] = ch;
				break;
			case '*':
				syn = 15;
				token[i++] = ch;
				break;
			case '/':
				syn = 16;
				token[i++] = ch;
				break;
			case '=':
				syn = 25;
				token[i++] = ch;
				break;
			case ';':
				syn = 26;
				token[i++] = ch;
				break;
			case '(':
				syn = 27;
				token[i++] = ch;
				break;
			case ')':
				syn = 28;
				token[i++] = ch;
				break;
			case'#':
				syn = 0;
				token[i++] = ch;
				break;
			default:
				syn = -1;
			}

		}
	}
}

//begin end
void G()
{
	while (syn == 10)
	{
		scanner();
		while ((syn == 18) || (syn == 26) || (syn == 25))
		{
			scanner();
			E();
		}
	}
}

//����ж�
void E()
{
	T();
	while ((syn == 13) || (syn == 14))
	{
		scanner();
		T();
	}
}

//���ӵ��ж�
void T()
{
	F();
	while ((syn == 15) || (syn == 16))
	{
		scanner();
		F();
	}
}

//()
void F()
{
	if ((syn == 11) || (syn == 10))
		scanner();
	else if (syn == 27)
	{
		scanner();
		E();
		if (syn == 28)
		{
			scanner();
		}
		else
		{
			printf("()û��ƥ��!\n");
			isError = 1;
		}
	}

	else if (syn == 1)
	{
		scanner();
		G();
		if (syn == 6)
		{
			scanner();
		}
		else
		{
			 printf("begin��endû��ƥ��!\n" );
			isError = 1;
		}
	}
}

int main()
{
	p = 0;

	printf("please input the source string:\n");
	do {
		ch = getchar();
		prog[p++] = ch;
	} while (ch != '#');//����������ַ�
	p = 0;
	isError = 0;
	scanner();
	if (syn == 1)
	{
		scanner();
		G();
	}
	scanner();
	if ((ch == '#') && (isError == 0))
		printf("success\n");
	else
		printf("error\n");

	system("pause");
	return 0;
}

