#include"acllib.h"
#include"main.h"
#include"Ctrl.h"
#include"View.h"
#include"Model.h"


#include<stdio.h>

ACL_Sound bksnd;
int cnt = 0;//计时器苏醒次数
int AirCnt;

int Setup()
{
	initWindow("Air War", WND_LO_X, WND_LO_Y, WND_LENGTH, WND_WIDTH);
	srand((unsigned int)time(NULL));
	initConsole();

	loadSound("Redfoo - Juicy Wiggle.WAV", &bksnd);
	playSound(bksnd,1);
	GameInit();
	
	registerKeyboardEvent(kBoardListener);
	
	registerTimerEvent(TimerListener);
	startTimer(0, 50);
	startTimer(1, 24000);
	
	return 0;
}


void TimerListener(int id)
{
	int i;
	if (start)
	{
		if (id == 0)
		{
			cnt++;
			AirCnt++;
			//if (cnt==5)
			//	cancelTimer(0);
			beginPaint();
			clearDevice();
			endPaint();

			PaintBattery();

			GunCoord();
			PaintGun();

			if (nPlane)
			{
				for (i = 0; i < nPlane; i++)
				{
					PlaneLocation(i);
				}
			}

			if (shellflag)
			{
				FairShell();
				PaintShells(Shell[NowShells].x1, Shell[NowShells].y1, Shell[NowShells].x2, Shell[NowShells].y2);
				printf("画炮弹\n");
				shellflag = 0;
			}
			if (NowShells)
			{

				for (i = 1; i <= NowShells; i++)
				{
					ShellProc(i);
					PaintShells(Shell[i].x1, Shell[i].y1, Shell[i].x2, Shell[i].y2);
				}
			}
		}
		else if (id == 1)
		{
			AirCnt = 0;
			for (i = 0; i < nPlane; i++)
			{
				x[i] = 0;
				y[i] = 0;
			}
			do {
				nPlane = rand() % NUM_PLANE + 1;
			} while (nPlane< MIN_PLANE);
			printf("%d\n", id);
		}
	}
}