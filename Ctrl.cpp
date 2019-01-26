#include"Model.h"
#include"Ctrl.h"

#include"acllib.h"
#include"View.h"

#include<stdio.h>

int start=0;//游戏开始标志
int GunAngle = 90;//炮筒角度
int shellflag=0;//发射炮弹的标志
void kBoardListener(int key, int event)
{
	if (event == 0)
	{
		start = 1;
		switch (key)
		{
		case 37:
			if (GunAngle > 0)
				GunAngle -= 15;
			break;
		case 39:
			if (GunAngle < 180)
				GunAngle += 15;
			break;
		case 32:
		shellflag=1;//发射炮弹的标志
		printf("%d\n", key);
			break;
		default:
			break;
		}

	}
}