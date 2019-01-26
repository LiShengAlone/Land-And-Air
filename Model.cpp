#include"Model.h"
#include"View.h"
#include"main.h"
#include<math.h>


int q1, w1, e1, r1;//画炮的线1的坐标
int q2, w2, e2, r2;//画炮的线2的坐标
int q3, w3, e3, r3;//画炮的线3的坐标
int q4, w4, e4, r4;//画炮的线4的坐标
double As, Ac, Gs, Gc;
int _Angle;
int NowShells = 0;//当前炮弹个数为
int LengthSpeed;//炮弹每过一个定时器的位移(像素)
struct shells Shell[SHELLS];
int ShellAngle[SHELLS];//每个子弹的角度记录
int x[NUM_PLANE] = { 0 }, y[NUM_PLANE] = { 0 };

int _X_=5;//飞机偏移量
int Px1, Py1, Px2, Py2, Px3, Py3, Px4, Py4, Px5, Py5;//飞机各点坐标
int nPlane;//飞机个数


//角度计算
int Angle()
{
	const double pi = acos(-1.0);
	_Angle = 90 - GunAngle;
	Gs = sin(GunAngle*pi / 180);
	Gc = cos(GunAngle*pi / 180);
	As = sin(_Angle*pi / 180);
	Ac = cos(_Angle*pi / 180);
	return 0;
}
//#include<stdio.h>

//计算炮筒的坐标
int GunCoord()
{
	Angle();
	q1 = WND_LENGTH / 2 - GunWidth / 2 * Ac;
	w1 = WND_WIDTH - BATTERY_HEIGHT - GunWidth / 2+ GunWidth / 2 * As;
	e1 = q1 - GunLength*Gc;
	r1 = w1 - GunLength*Gs;
	q2 = WND_LENGTH / 2 + GunWidth / 2 * Ac;
	w2 = WND_WIDTH - BATTERY_HEIGHT - GunWidth / 2 - GunWidth / 2 * As;
	e2 = q2- GunLength*Gc;
	r2 = w2- GunLength*Gs;
	q3 = q1;
	w3 = w1;
	e3 = q2;
	r3 = w2;
	q4 = e1;
	w4 = r1;
	e4 = e2;
	r4 = r2;
	return 1;
}

//炮弹的发射初始化
int FairShell()
{
	NowShells++;
	ShellAngle[NowShells] = GunAngle;
	Shell[NowShells].x1 = (e1 + e2) / 2 + GunWidth / 2;
	Shell[NowShells].y1 = (r1 + r2) / 2 + GunWidth / 2;
	Shell[NowShells].x2 = (e1 + e2) / 2 - GunWidth / 2;
	Shell[NowShells].y2 = (r1 + r2) / 2 - GunWidth / 2;
	return 0;
}

//发射后飞行过程
int ShellProc(int i)
{
	const double pi = acos(-1.0);
	double SS, SC;
	SS = sin(ShellAngle[i] *pi / 180);
	SC = cos(ShellAngle[i] *pi / 180);
	LengthSpeed = 20;
	Shell[i].x1 = Shell[i].x1- LengthSpeed*SC;
	Shell[i].y1 = Shell[i].y1- LengthSpeed*SS;
	Shell[i].x2 = Shell[i].x2- LengthSpeed*SC;
	Shell[i].y2 = Shell[i].y2- LengthSpeed*SS;
	return 0;
}


//飞机坐标记录及初始化
int PlaneLocation(int i)
{
	//int nPlane;//飞机个数
//	nPlane = rand() % NUM_PLANE;
	if (x[i] == 0)
		x[i] = rand() % (WND_LENGTH-100) +1;
	if (y[i] == 0)
		y[i] = rand() % (WND_WIDTH /2)+1;
	AirFly(x[i], y[i]);
	return 0;
}
//飞机移动
int AirFly(int x,int y)
{
	
	Px1 = 0 - x + _X_*AirCnt;//机尾坐标
	Px2 = 0 - x + _X_*AirCnt;
	Px3 = 100 - x + _X_*AirCnt;
	Px4 = 50 - x + _X_*AirCnt;
	Px5 = 70 - x + _X_*AirCnt;
	Py1 = (WND_WIDTH / 2)+20 - y;
	Py2 = (WND_WIDTH / 2)+30 - y;
	Py3 = (WND_WIDTH / 2)+30 - y;
	Py4 = (WND_WIDTH / 2) - y;
	Py5 = (WND_WIDTH / 2)+20 - y;
	AirPlane(Px1, Py1, Px2, Py2, Px3, Py3, Px4, Py4, Px5, Py5);
	return 0;
}