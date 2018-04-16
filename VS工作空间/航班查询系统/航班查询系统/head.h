#ifndef HEAD

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

void input_info(plane *li);
void query_info(plane *kui,int hour,int minute);

#endif


