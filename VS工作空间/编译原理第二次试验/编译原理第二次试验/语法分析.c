#include<stdio.h>
#include<math.h>
#include<stdlib.h>


char token[16];//与关键字数组进行比较，得出它们所代表序号
char prog[256];//用于接受字符
char * keyword[6] = { "begin","if","then","while","do" ,"end"};	//关键字表
int p = 0;	//缓冲区流
int syn;	//标识符
double sum = 0;
char ch;//接受到的一个字符

int isSignal = 0;	//是否带正负号(0:不带 1:负号 2:正号)

int isDecimal = 0;  //是否小数(0 是 1 不是)
double decimal = 0; //小数
double temp = 0;
int temp2 = 0;
int isError = 0;

void T();
void F();
void E();

//判断是否为数字
void IsNum()
{
	int count = 0;
	while ((ch >= '0') && (ch <= '9'))
	{
		sum = sum * 10 + ch - '0';
		ch = prog[p++];
	}

	//小数计算
	if (ch == '.')
	{
		isDecimal = 1;
		ch = prog[p++];
		
		while ((ch >= '0') && (ch <= '9'))
		{
			//pow(x,y)计算x的y次幂
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
	if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))	//是字母
	{

		while ((ch>=65 && ch<=90) || (ch>=97 && ch<=122) || (ch>=48 && ch<=57))	//是数字或者字母
		{//判断接下来是否为数字，
			token[i++] = ch;
			ch = prog[p++];
		}
		token[i++] = '\0';
		p--;
		syn = 10;

		for ( j = 0; j < 6; j++)
		{
			if (strcmp(keyword[j], token) == 0)//输入与关键字相匹配
			{
				syn = j + 1;//给出关键字代表的序号
				break;
			}
		}
	}
	else
	{
		if ((ch >= 48 && ch <= 57))				//是数字
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
					syn = 21; //<>对应21
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
					IsNum();		//转到数字的识别
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

//项的判断
void E()
{
	T();
	while ((syn == 13) || (syn == 14))
	{
		scanner();
		T();
	}
}

//因子的判断
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
			printf("()没有匹配!\n");
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
			 printf("begin与end没有匹配!\n" );
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
	} while (ch != '#');//接受输入的字符
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

