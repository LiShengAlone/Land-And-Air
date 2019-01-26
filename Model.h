#pragma once

#define SHELLS 5555//最大炮弹数加1
#define NUM_PLANE 10//最多飞机数
#define MIN_PLANE 3//最少飞机数

extern int NowShells;//当前炮弹个数
extern int GunAngle;//炮的角度
extern int q1, w1, e1, r1;//画炮的线1的坐标
extern int q2, w2, e2, r2;//画炮的线2的坐标
extern int q3, w3, e3, r3;//画炮的线3的坐标
extern int q4, w4, e4, r4;//画炮的线4的坐标

extern int _X_;//飞机偏移量
extern int nPlane;//飞机个数
extern int x[], y[];
extern int x[], y[];

extern struct shells {
	int x1;
	int y1;
	int x2;
	int y2;
}Shell[];//每一个炮的坐标

int GunCoord();//计算炮的坐标
int Angle();//角度计算
int FairShell();//炮弹的发射初始化
int ShellProc(int i);//炮弹发射过程
int AirFly(int x, int y);//飞机飞行过程
int PlaneLocation(int i);//飞机坐标记录及初始化