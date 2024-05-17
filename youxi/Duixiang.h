#pragma once
#include<easyx.h>
class Renwu
{private:
	int x, y;//зјБъ
	char dir;
	int flag;
	int flag2=0;
	int HP;
	int HPx;
	int GJL = 0;
	int CD = 0;
	IMAGE Ren_wu_d, Ren_wu_u, Ren_wu_l, Ren_wu_r;
	IMAGE Ren_wu_d1, Ren_wu_u1, Ren_wu_l1, Ren_wu_r1;
	IMAGE Ren_wu_d2, Ren_wu_u2, Ren_wu_l2, Ren_wu_r2;
	IMAGE ZD_1, ZD_2, ZD_3, ZD_4;
public:
	Renwu(int,int,int);
	void KeyControl(int i); 
	void ZDShow(int i);
	void Show();
	void Xue_tiao();
	void Xue_liang();
	bool peng(int x, int y, int ditu);
	int getx();
	int gety();
	char getdir();
	int getHP();
	void ChangeHP(int i);
	void ChangeX(int);
	void ChangeY(int);
	void Huixue(int i);
	void Renwulan(int i);
	int Gongji1();
	int Gongji2();
	void Huifu();
	void ChangeHPx(int i);
	int getHPx();
	void Jiesuan(int);
	void ChangeGJL(int i);
	int getCD();
	void ChangeCD();
	void Taopao(int);
};

class Jingling
{
protected:
	int flag=1, flag2=0;
	int n=0;
	int x, y;
	int ZD_x, ZD_y;
	char dir;
	int HP;
	int HPx;
	IMAGE JL_d, JL_l, JL_r, JL_u;
	IMAGE JL_d1, JL_l1, JL_r1, JL_u1;
	IMAGE JL_d2, JL_l2, JL_r2, JL_u2;
	IMAGE ZD_1, ZD_2, ZD_3, ZD_4, ZD_5;
public:
	Jingling(int, int, int,int ,int, char);
	void Show();
	void ZDShow(int i);
	void Hu_dong(Renwu*);
	virtual void Xue_tiao() = 0 {};
	virtual void Xue_liang() = 0 {};
	int getx();
	int gety();
	int getHP();
	int getHPx();
	void ChangeHPx(int i);
	virtual int Gongji();
};

class Miao :public Jingling {
public:
	Miao(int, int, int,int ,int, char di);
	void Move();
	void Xue_tiao();
	void Xue_liang();
	int Gongji();
};

class Jie :public Jingling {
public:
	Jie(int, int, int ,int,int, char di);
	void Move();
	void Xue_tiao();
	void Xue_liang();
	int Gongji();
};