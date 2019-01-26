#include"acllib.h"
#include"main.h"
#include"Model.h"
#include"View.h"
#include<math.h>


ACL_Image startImg;
ACL_Image bkImg;

int GameInit()
{
	beginPaint();
	loadImage("WARbk.bmp", &bkImg);
	loadImage("timg.bmp", &startImg);
	putImageScale(&startImg, 0, 0, WND_LENGTH, WND_WIDTH);
	//ÅÚÌ¨
	setPenColor(RGB(120, 111, 22));
	setPenWidth(8);
	line(WND_LENGTH / 2 - BATTERY_WIDTH / 2, WND_WIDTH - 1, WND_LENGTH / 2 + BATTERY_WIDTH / 2, WND_WIDTH - 1);
	line(WND_LENGTH / 2 - BATTERY_WIDTH / 2, WND_WIDTH - BATTERY_HEIGHT, WND_LENGTH / 2 + BATTERY_WIDTH / 2, WND_WIDTH - BATTERY_HEIGHT);
	line(WND_LENGTH / 2 - BATTERY_WIDTH / 2, WND_WIDTH - BATTERY_HEIGHT, WND_LENGTH / 2 - BATTERY_WIDTH / 2, WND_WIDTH);
	line(WND_LENGTH / 2 + BATTERY_WIDTH / 2, WND_WIDTH - BATTERY_HEIGHT, WND_LENGTH / 2 + BATTERY_WIDTH / 2, WND_WIDTH);

	//ÅÚ¼Ü
	setPenWidth(5);
	setPenColor(RGB(0, 0, 0));
	setBrushColor(RGB(255, 255, 255));
	ellipse(WND_LENGTH / 2 - GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT- GunWidth, WND_LENGTH / 2 + GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT);
	//ÅÚ
	setPenWidth(5);
	setPenColor(RGB(255, 0, 0));
	line(WND_LENGTH / 2 - GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunWidth / 2, WND_LENGTH / 2 - GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunLength - GunWidth / 2);
	line(WND_LENGTH / 2 + GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunWidth / 2, WND_LENGTH / 2 + GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunLength - GunWidth / 2);
	line(WND_LENGTH / 2 - GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunLength - GunWidth / 2, WND_LENGTH / 2 + GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunLength - GunWidth / 2);
	line(WND_LENGTH / 2 - GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunWidth / 2, WND_LENGTH / 2 + GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunWidth / 2);
	endPaint();
	return 0;
}

//Ö»»­ÅÚÌ¨ºÍÅÚ¼Ü
int PaintBattery()
{
	beginPaint();
	setPenColor(RGB(120, 111, 22));
	setPenWidth(8);
	putImageScale(&bkImg, 0, 0, WND_LENGTH, WND_WIDTH);
	line(WND_LENGTH / 2 - BATTERY_WIDTH / 2, WND_WIDTH - 1, WND_LENGTH / 2 + BATTERY_WIDTH / 2, WND_WIDTH - 1);
	line(WND_LENGTH / 2 - BATTERY_WIDTH / 2, WND_WIDTH - BATTERY_HEIGHT, WND_LENGTH / 2 + BATTERY_WIDTH / 2, WND_WIDTH - BATTERY_HEIGHT);
	line(WND_LENGTH / 2 - BATTERY_WIDTH / 2, WND_WIDTH - BATTERY_HEIGHT, WND_LENGTH / 2 - BATTERY_WIDTH / 2, WND_WIDTH);
	line(WND_LENGTH / 2 + BATTERY_WIDTH / 2, WND_WIDTH - BATTERY_HEIGHT, WND_LENGTH / 2 + BATTERY_WIDTH / 2, WND_WIDTH);
	//ÅÚ¼Ü
	setPenWidth(5);
	setPenColor(RGB(0, 0, 0));
	setBrushColor(RGB(255, 255, 255));
	ellipse(WND_LENGTH / 2 - GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT - GunWidth, WND_LENGTH / 2 + GunWidth / 2, WND_WIDTH - BATTERY_HEIGHT);
	endPaint();
	return 0;
}

//Ö»»­ÅÚ
int PaintGun()
{
	beginPaint();
	setPenColor(RGB(255, 0, 0));
	setPenWidth(5);
	line(q1, w1, e1, r1);
	line(q2, w2, e2, r2);
	line(q3, w3, e3, r3);
	line(q4, w4, e4, r4);
	endPaint();

	return 0;
}


//»­ÅÚµ¯
int PaintShells(int XONE,int YONE,int XTWO,int YTWO)
{
	beginPaint();
	setPenColor(RGB(230, 255, 0));
	setPenWidth(5);
	setBrushColor(RGB(230,255,0));
	ellipse(XONE, YONE, XTWO, YTWO);
	endPaint();
	return 0;
}

//³õÊ¼»¯Ò»¼Ü·É»ú
int AirPlane(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5)
{
	beginPaint();
	setPenColor(RGB(0, 255, 0));
	setPenWidth(5);
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x4, y4);
	line(x4, y4, x5, y5);
	line(x5, y5, x1, y1);
	endPaint();
	return 0;
}