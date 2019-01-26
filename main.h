#pragma once
#include<time.h>
#include<stdlib.h>

#define WND_LO_X 100		//窗口位置横坐标       location   位置
#define WND_LO_Y 100		//窗口位置纵坐标
#define WND_LENGTH 1280		//窗口长
#define WND_WIDTH 800		//窗口宽

extern int cnt;
extern int AirCnt;
void TimerListener(int id);
