#pragma once
#include<easyx.h>
class Jingling
{
protected:
	int flag,flag2;
	int x, y;
	char dir;
	int Xue_liang;
	IMAGE JL_d, JL_l, JL_r, JL_u;
	IMAGE JL_d1, JL_l1, JL_r1, JL_u1;
	IMAGE JL_d2, JL_l2, JL_r2, JL_u2;
public:
	Jingling(int ,int,int , char);
	void Show();
	void Yi_dong();
	int getx();
	int gety();
};

class Miao:virtual public Jingling {
public:
	Miao(int i, int j,int x, char di);
};

