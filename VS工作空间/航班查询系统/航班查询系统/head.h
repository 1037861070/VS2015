#ifndef HEAD

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

void input_info(plane *li);
void query_info(plane *kui,int hour,int minute);

#endif


