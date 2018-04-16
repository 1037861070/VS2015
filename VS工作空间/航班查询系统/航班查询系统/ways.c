#include <stdio.h>
#include "head.h"

void input_info(plane *li){ 
    int i = 0;
	printf("航班号\t\t起飞时间\t抵达时间\n");
	for (i=0;i<8;i++)
	{
		//输出格式
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

void query_info(plane *kui,int hour,int minute){
	int i=1,time,ncount=0,distance,Min;
	plane likui[8];
	time=hour*60+minute;
	distance=kui[0].up_hour*60+kui[0].up_minute-time;
	Min=abs(distance);
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
	/*printf("%s\t\t%2d:%2d\t\t%2d:%2d\n",kui[ncount].number,kui[ncount].up_hour,kui[ncount].up_minute,
		kui[ncount].down_hour,kui[ncount].dowm_minute);*/
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