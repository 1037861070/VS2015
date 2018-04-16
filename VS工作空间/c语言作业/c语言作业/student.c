#include<stdio.h>


typedef struct StudentMessage{
	char  StudentNum[6];
	char StudentName[10];
	int Grade1;
	int Grade2;
	int Grade3;
}student;

void Inputstudent(student *student1,int N);
void PrintStudent(student *student1,int N);

int main()
{
	student stu[20];
	int N,i;
	scanf("%d",&N);
	Inputstudent(stu,N);
	PrintStudent(stu,N);
	system("pause");
	return 0;
}
void Inputstudent(student *student1,int N)
{
	int i;
	for (i=0;i<N;i++)
	{
		scanf("%s %s %d %d %d",&student1[i].StudentNum,&student1[i].StudentName,
			&student1[i].Grade1,&student1[i].Grade2,&student1[i].Grade3);
	
	}
}
void PrintStudent(student *student1,int N)
{
	int i,Max,ncount;
	Max=student1[0].Grade1+student1[0].Grade2+student1[0].Grade3;
	ncount=0;
	for (i=1;i<N;i++)
	{
		int temp = student1[i].Grade1+student1[i].Grade2+student1[i].Grade3;
		if (temp > Max)
		{
			Max=temp;
			ncount = i;
		}
	}
	printf("%s %s %d",student1[ncount].StudentName,student1[ncount].StudentNum,Max);
}