#include "Duixiang.h"
#include"Zhandou.h"
#include"png贴图.h"
#include<time.h>
Renwu::Renwu(int x1,int y1,int h1) {
	x = x1, y = y1;
	HP = h1;
	HPx = h1;
	flag = 1;
	loadimage(&Ren_wu_d, L"./renwu/renwu 正.png");
	loadimage(&Ren_wu_l, L"./renwu/renwu 左.png");
	loadimage(&Ren_wu_r, L"./renwu/renwu 右.png");
	loadimage(&Ren_wu_u, L"./renwu/renwu 后.png");
	loadimage(&Ren_wu_d1, L"./renwu/renwu 正1.png");
	loadimage(&Ren_wu_l1, L"./renwu/renwu 左1.png");
	loadimage(&Ren_wu_r1, L"./renwu/renwu 右1.png");
	loadimage(&Ren_wu_u1, L"./renwu/renwu 后1.png");
	loadimage(&Ren_wu_d2, L"./renwu/renwu 正2.png");
	loadimage(&Ren_wu_l2, L"./renwu/renwu 左2.png");
	loadimage(&Ren_wu_r2, L"./renwu/renwu 右2.png");
	loadimage(&Ren_wu_u2, L"./renwu/renwu 后2.png");
	
	
	loadimage(&ZD_1, L"./renwu/pika/ZD1.png");
	loadimage(&ZD_2, L"./renwu/pika/ZD2.png");
	loadimage(&ZD_3, L"./renwu/pika/ZD3.png");
	loadimage(&ZD_4, L"./renwu/pika/ZD4.png");
	dir = 's';
}
void Renwu::Show() {
	switch (dir){
	case 's':
		if (flag == 1||flag2==0)
			transparentimage3(NULL, x, y, &Ren_wu_d);
		else if (flag == 2)
			transparentimage3(NULL, x, y, &Ren_wu_d1);
		else if (flag == 3)
			transparentimage3(NULL, x, y, &Ren_wu_d);
		else if (flag == 4)
			transparentimage3(NULL, x, y, &Ren_wu_d2);
		if (flag >= 4)
			flag = 1;
		else
			flag++;
		break;
	case 'w':
		if (flag == 1 || flag2 == 0)
			transparentimage3(NULL, x, y, &Ren_wu_u);
		else if (flag == 2)
			transparentimage3(NULL, x, y, &Ren_wu_u1);
		else if (flag == 3)
			transparentimage3(NULL, x, y, &Ren_wu_u);
		else if (flag == 4)
			transparentimage3(NULL, x, y, &Ren_wu_u2);
		if (flag >= 4)
			flag = 1;
		else
			flag++;
		break;
	case 'a':
		if (flag == 1 || flag2 == 0)
			transparentimage3(NULL, x, y, &Ren_wu_l);
		else if (flag == 2)
			transparentimage3(NULL, x, y, &Ren_wu_l1);
		else if (flag == 3)
			transparentimage3(NULL, x, y, &Ren_wu_l);
		else if (flag == 4)
			transparentimage3(NULL, x, y, &Ren_wu_l2);
		if (flag >= 4)
			flag = 1;
		else
			flag++;
		break;
	case 'd':
		if (flag == 1 || flag2 == 0)
			transparentimage3(NULL, x, y, &Ren_wu_r);
		else if (flag == 2)
			transparentimage3(NULL, x, y, &Ren_wu_r1);
		else if (flag == 3)
			transparentimage3(NULL, x, y, &Ren_wu_r);
		else if (flag == 4)
			transparentimage3(NULL, x, y, &Ren_wu_r2);
		if (flag >= 4)
			flag = 1;
		else
			flag++;
		break;
	}
	flag2 = 0;
}
void Renwu::ZDShow(int i) {
	Xue_tiao();
	switch (flag / 160) {
	case 0:
		transparentimage3(NULL, 42+i, 280, &ZD_1);
		break;
	case 1:
		transparentimage3(NULL, 42+i, 280, &ZD_2);
		break;
	case 2:
		transparentimage3(NULL, 42+i, 280, &ZD_3);
		break;
	case 3:
		transparentimage3(NULL, 42+i, 280, &ZD_4);
		break;
	case 4:
		transparentimage3(NULL, 42+i, 280, &ZD_3);
		break;
	}
	flag++;
	if (flag >= 800)
		flag = 0;
}
void Renwu::KeyControl(int i) {
	if (GetAsyncKeyState(VK_UP) & 0X8000) {
		if (peng(x, y - 10, i)) {
			y -= 10;
			dir = 'w';
			flag2 = 1;
		}
	}
	if (GetAsyncKeyState(VK_DOWN) & 0X8000) {
		if (peng(x, y + 10, i)) {
			y += 10;
			dir = 's';
			flag2 = 1;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) & 0X8000) {
		if (peng(x - 10, y, i)) {
			x -= 10;
			dir = 'a';
			flag2 = 1;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0X8000) {
		if (peng(x + 10, y, i)) {
			x += 10;
			dir = 'd';
			flag2 = 1;
		}
	}
}
bool Renwu::peng(int x, int y, int ditu) {
	if (ditu == 1)   /*HOUSE1*/ {
		if ((x <= 150 || x >= 130 + 300) || (y <= 200 || y >= 150 + 235))
			return 0;    //地图范围
		if ((x >= 150 + 50 && x <= 150 + 50 + 90) && (y >= 200 + 40 && y <= 200 + 40 + 65))
			return 0;   //中间桌子
		if ((x >= 130 + 280 && y >= 150 + 235 - 60) || (x >= 130 + 250 && y <= 210))
			return 0;   //右上，右下盆栽
	}
	if (ditu == 2)   /*HOUSE2*/ {
		if ((x <= 120 || x >= 100 + 380) || (y <= 200 || y >= 150 + 250))
			return 0;   //地图范围
		if ((x >= 100 + 290 && x <= 100 + 380) && (y >= 150 + 150 && y <= 150 + 250))
			return 0;   //右下桌子

		if ((x <= 320 && x >= 320 - 40) && (y <= 240 + 1 && y >= 240 - 11))
			Huixue(gety());     //回满血


		if ((x <= 100 + 300 && x >= 120) && (y <= 200 + 40 && y >= 200))
			return 0;   //柜台
	}
	if (ditu == 11)  /*Bei_jing1*/ {
		if (x <= 0 || y <= 0 || y >= 600)
			return 0;        //地图范围
		if ((y <= 600 - 75 && y >= 600 - 200) && (x >= 600 - 180))
			return 0;        //右下房子
		if ((x >= 600 - 110 && y >= 600 - 70) || (x >= 600 - 40 && y >= 600 - 245))
			return 0;        //右下树
		if ((x <= 115 && y >= 600 - 110) || (x <= 60 && y >= 600 - 120 - 115))
			return 0;        //左下树
		if ((y <= 600 - 80 && y >= 600 - 60 - 140) && (x >= 140 && x <= 150 + 135))
			return 0;        //左下房子
		if ((y <= 600 - 235 - 50 && x <= 50) || (y <= 50 && x <= 240) || (y <= 60 + 50 && x <= 60 + 50))
			return 0;        //左上树
		if ((x >= 50 + 50 && x <= 250) && (y >= 60 + 50 && y <= 60 + 50 + 130))
			return 0;        //左上房子

		if ((x >= 250 + 80 && x <= 300 + 70) && (y >= 250 + 20 && y <= 250 + 60)) {
			{
				Renwulan(1);    //任务栏
			}
		}


		if ((x >= 250 + 80 && x <= 300 + 70) && (y >= 250 + 20 && y <= 250 + 60))
			return 0;        //中间牌子
		if ((y <= 600 - 235 - 120 && x >= 600 - 40) || (y <= 50 && x >= 600 - 240) || (y <= 60 + 50 && x >= 600 - 110))
			return 0;        //右上树
		if ((x <= 600 - 70 && x >= 360 + 30) && (y >= 50 + 40 && y <= 60 + 140))
			return 0;       //右上房子
	}
	if (ditu == 12)     /*Bei_jing2*/ {
		if (y <= 0 || y >= 600 || x >= 600)
			return 0;        //地图范围
		if ((x >= 250 + 50 && x <= 300 + 40) && (y >= 240 && y <= 240 + 40))
		{
			Renwulan(0);
			return 0;        //中间牌子
		}
		if ((y >= 580 && x >= 0) || (x >= 40 && y >= 520) || (x >= 260 + 40 && y >= 520 - 60) || (x >= 300 + 130 && y >= 460 - 60) || (x >= 270 + 290 && y >= 400 - 70))
			return 0;       //右下树
		if ((y <= 520 - 190 && y >= 520 - 250 && x <= 170) || (y <= 520 - 120 && y >= 400 - 60 && x <= 170 && x >= 50) || (y <= 270 && x <= 140) || (x <= 170 && y <= 90))
			return 0;       //左上树
		if ((y <= 20) || (y <= 300 - 30 && x >= 560) || (x >= 500 && y <= 270 - 70) || (x >= 300 && y <= 180))
			return 0;      //上池塘，右上树
	}
	return 1;
}
int Renwu::getx() {
	return x;
}
int Renwu::gety() {
	return y;
}
char Renwu::getdir() {
	return dir;
}
void Renwu::ChangeX(int i) {
	x = i;
}
void Renwu::ChangeY(int i) {
	y = i;
}
void Renwu::Huixue(int i) {
	IMAGE ZL;
	loadimage(&ZL, L"zhiliao.png");
	transparentimage3(NULL, 120, 200, &ZL);
	if (Xuan_ze()) {
		HPx = HP;
	}
	ChangeY(i + 10);
}
void Renwu::Renwulan(int i) {
	if(i)
	{
		IMAGE XZ;
		loadimage(&XZ, L"pai1.png");
		transparentimage3(NULL, 130, 200, &XZ);
		Sleep(3000);
	}
	else
	{
		IMAGE XZ;
		loadimage(&XZ, L"pai2.png");
		transparentimage3(NULL, 130, 200, &XZ);
		Sleep(3000);
	}
}
int Renwu::getHP() {
	return HP;
}
void Renwu::ChangeHP(int i) {
	HP = i;
}
int Renwu::Gongji1() {
	CD = 3;
	return 200 + GJL * 10;
}
int Renwu::Gongji2() {
	return 100 + GJL * 2;
}
void Renwu::ChangeGJL(int i) {
	GJL += i;
}
int Renwu::getCD() {
	return CD;
}
void Renwu::ChangeCD() {
	CD -= 1;
}
void Renwu::Huifu() {
	if (HPx + 200 >= HP) {
		HPx = HP;
	}
	else {
		HPx += 200+GJL*4;
	}
}
void Renwu::ChangeHPx(int i) {
	if (i < 0)
		HPx = 0;
	else
	HPx = i;
}
int Renwu::getHPx() {
	return HPx;
}
void Renwu::Xue_tiao() {
	IMAGE BK;
	loadimage(&BK, L"./electric kuang.png");
	transparentimage3(NULL, 345, 330, &BK);
	Xue_liang();
}
void Renwu::Xue_liang() {
	IMAGE XT;
	loadimage(&XT, L"./xt.png");
	int i = (HPx * 100) / HP;
	int x = 194 * i / 100;
	wchar_t num1[20],num2[20];
	_itow_s(HPx, num1, 10);
	_itow_s(HP, num2, 10);
	outtextxy(490, 374, num1);
	outtextxy(515, 374, L"/");
	outtextxy(525, 374, num2);
	putimage(384, 347, x, 20, &XT, 0, 0);
}
void Renwu::Jiesuan(int i) {
	IMAGE WIN, LOOSE;
	loadimage(&WIN, L"胜利.png");
	loadimage(&LOOSE, L"失败.png");
	if(i)
		transparentimage3(NULL, 120, 200, &WIN);
	else
		transparentimage3(NULL, 120, 200, &LOOSE);
	if (dir == 'a' || dir == 'd')
		ChangeY(y - 11);
	else if (getx() <= x)
		ChangeX(x - 11);
	else
		ChangeX(x + 11);
	Sleep(2000);
}
void Renwu::Taopao(int i) {
	if(i){
		IMAGE TPCG;
	    loadimage(&TPCG, L"taopao cg.png");
	     transparentimage3(NULL, 120, 200, &TPCG);
		 if (dir == 'a' || dir == 'd')
			 ChangeY(y - 11);
		 else if (getx() <= x)
			 ChangeX(x - 11);
		 else
			 ChangeX(x + 11);
	}
	else
	{
		IMAGE TPSB;
		loadimage(&TPSB, L"taopao sb.png");
		transparentimage3(NULL, 120, 200, &TPSB);
	}
}

Jingling::Jingling(int i, int j,int k,int l, int  xu, char di) {
	x = i;
	y = j;
	ZD_x = k;
    ZD_y = l;
	dir = di;
	HP = xu;
	HPx = xu;
}
void Jingling::Show() {
	switch (dir) {
	case 's':
		if (flag == 1 || flag2 == 0)
			transparentimage3(NULL, x, y, &JL_d);
		else if (flag == 2)
			transparentimage3(NULL, x, y, &JL_d1);
		else if (flag == 3)
			transparentimage3(NULL, x, y, &JL_d);
		else if (flag == 4)
			transparentimage3(NULL, x, y, &JL_d2);
		if (flag >= 4)
			flag = 1;
		else
			flag++;
		break;
	case 'w':
		if (flag == 1 || flag2 == 0)
			transparentimage3(NULL, x, y, &JL_u);
		else if (flag == 2)
			transparentimage3(NULL, x, y, &JL_u1);
		else if (flag == 3)
			transparentimage3(NULL, x, y, &JL_u);
		else if (flag == 4)
			transparentimage3(NULL, x, y, &JL_u2);
		if (flag >= 4)
			flag = 1;
		else
			flag++;
		break;
	case 'a':
		if (flag == 1 || flag2 == 0)
			transparentimage3(NULL, x, y, &JL_l);
		else if (flag == 2)
			transparentimage3(NULL, x, y, &JL_l1);
		else if (flag == 3)
			transparentimage3(NULL, x, y, &JL_l);
		else if (flag == 4)
			transparentimage3(NULL, x, y, &JL_l2);
		if (flag >= 4)
			flag = 1;
		else
			flag++;
		break;
	case 'd':
		if (flag == 1 || flag2 == 0)
			transparentimage3(NULL, x, y, &JL_r);
		else if (flag == 2)
			transparentimage3(NULL, x, y, &JL_r1);
		else if (flag == 3)
			transparentimage3(NULL, x, y, &JL_r);
		else if (flag == 4)
			transparentimage3(NULL, x, y, &JL_r2);
		if (flag >= 4)
			flag = 1;
		else
			flag++;
		break;
	}
	flag2 = 0;
}
int Jingling::getx() {
	return x;
}
int Jingling::gety() {
	return y;
}
void Jingling::Hu_dong(Renwu* a) {
	IMAGE XZ;
	loadimage(&XZ, L"xuanze.png");
	if (a->getx() >= (x - 10) && a->getx() <= (x + 10))
		if (a->gety() >= (y - 10) && a->gety() <= (y + 10)) {
			transparentimage3(NULL, 130, 200, &XZ);
			if (Xuan_ze()) {
				cleardevice();
				Zhandou(this, a);
			}
			else {
				if (dir == 'a'||dir=='d')
					a->ChangeY(y-11);
				else if ( a->getx() <= x )
					a->ChangeX(x - 11);
				else 
					a->ChangeX(x + 11);
			}
		}
}
void Jingling::ZDShow(int i) {
	Xue_tiao();
	switch (flag / 160) {
	case 0:
		transparentimage3(NULL, ZD_x+i, ZD_y, &ZD_1);
		break;
	case 1:
		transparentimage3(NULL, ZD_x+i, ZD_y, &ZD_2);
		break;
	case 2:
		transparentimage3(NULL, ZD_x+i, ZD_y, &ZD_3);
		break;
	case 3:
		transparentimage3(NULL, ZD_x+i, ZD_y, &ZD_4);
		break;
	case 4:
		transparentimage3(NULL, ZD_x+i, ZD_y, &ZD_5);
		break;
	}
	flag++;
	if (flag >= 800)
		flag = 0;
}
int Jingling::getHP() {
	return HP;
}
void Jingling::ChangeHPx(int i) {
	HPx = i;
}
int Jingling::getHPx() {
	return HPx;
}
int Jingling::Gongji() {
	return 0;
}


Miao::Miao(int i, int j,int k,int l, int x, char di) :Jingling(i, j, k,l,x, di) {

	loadimage(&JL_d, L"./miaowa/miaowa 正.png");
	loadimage(&JL_l, L"./miaowa/miaowa 左.png");
	loadimage(&JL_r, L"./miaowa/miaowa 右.png");
	loadimage(&JL_u, L"./miaowa/miaowa 后.png");
	loadimage(&JL_d1, L"./miaowa/miaowa 正1.png");
	loadimage(&JL_l1, L"./miaowa/miaowa 左1.png");
	loadimage(&JL_r1, L"./miaowa/miaowa 右1.png");
	loadimage(&JL_u1, L"./miaowa/miaowa 后1.png");
	loadimage(&JL_d2, L"./miaowa/miaowa 正2.png");
	loadimage(&JL_l2, L"./miaowa/miaowa 左2.png");
	loadimage(&JL_r2, L"./miaowa/miaowa 右2.png");
	loadimage(&JL_u2, L"./miaowa/miaowa 后2.png");

	loadimage(&ZD_1, L"./miaowa/ZD/1.png");
	loadimage(&ZD_2, L"./miaowa/ZD/2.png");
	loadimage(&ZD_3, L"./miaowa/ZD/3.png");
	loadimage(&ZD_4, L"./miaowa/ZD/4.png");
	loadimage(&ZD_5, L"./miaowa/ZD/5.png");
}
void Miao::Move() {
	switch (n/30) {
	case 0:
		y+=5;
		dir = 's';
		flag2 = 1;
		break;
	case 2:
		y-=5;
		dir = 'w';
		flag2 = 1;
		break;
	}
	n++;
	if (n == 120)
		n = 0;
}
int Miao::Gongji() {
	if (HPx > HP/2) {
		return 50;
	}
	else {
		return 80;
	}
}
void Miao::Xue_tiao() {
	IMAGE BK;
	loadimage(&BK, L"./grass kuang.png");
	transparentimage3(NULL, 50, 160, &BK);
	Xue_liang();
}
void Miao::Xue_liang() {
	IMAGE XT;
	loadimage(&XT, L"./xt1.png");
	int i = (HPx * 100) / HP;
	int x = 194 * i / 100;
	putimage(89, 177, x, 20, &XT, 0, 0);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(15, 0, _T("华文彩云 常规"));
	wchar_t num1[20], num2[20];
	_itow_s(HPx, num1, 10);
	_itow_s(HP, num2, 10);
	outtextxy(190, 205, num1);
	outtextxy(215, 205, L"/");
	outtextxy(225, 205, num2);
}

Jie::Jie(int i, int j, int k, int l,int x, char di) : Jingling(i, j,k,l, x, di) {

	loadimage(&JL_d, L"./jieni/正.png");
	loadimage(&JL_l, L"./jieni/左.png");
	loadimage(&JL_r, L"./jieni/右.png");
	loadimage(&JL_u, L"./jieni/后.png");
	loadimage(&JL_d1, L"./jieni/正1.png");
	loadimage(&JL_l1, L"./jieni/左1.png");
	loadimage(&JL_r1, L"./jieni/右1.png");
	loadimage(&JL_u1, L"./jieni/后1.png");
	loadimage(&JL_d2, L"./jieni/正2.png");
	loadimage(&JL_l2, L"./jieni/左2.png");
	loadimage(&JL_r2, L"./jieni/右2.png");
	loadimage(&JL_u2, L"./jieni/后2.png");

	loadimage(&ZD_1, L"./jieni/ZD/1.png");
	loadimage(&ZD_2, L"./jieni/ZD/2.png");
	loadimage(&ZD_3, L"./jieni/ZD/3.png");
	loadimage(&ZD_4, L"./jieni/ZD/4.png");
	loadimage(&ZD_5, L"./jieni/ZD/5.png");
}
void Jie::Move() {
	switch (n / 40) {
	case 0:
		x += 3;
		dir = 'd';
		flag2 = 1;
		break;
	case 2:
		x -= 3;
		dir = 'a';
		flag2 = 1;
		break;
	}
	n++;
	if (n == 160)
		n = 0;
}
int Jie::Gongji() {
	if (HPx > (HP * 3 / 4) ){
		srand((unsigned int)time(NULL));
		if ((rand() % 100 + 1) <= 90)
		return 150;
		ChangeHPx(getHPx() + 200);
		return 0;
	}
	else if (HPx > HP / 4) {
		srand((unsigned int)time(NULL));
		if ((rand() % 100 + 1) <= 80)
		return 250;
		ChangeHPx(getHPx() + 350);
		return 0;
	}
	else {
		srand((unsigned int)time(NULL));
		if ((rand() % 100 + 1) <= 70)
		return 500;
		ChangeHPx(getHPx() + 650);
		return 0;
	}
}
void Jie::Xue_tiao() {
	IMAGE  BK;
	loadimage(&BK, L"./water kuang.png");
	transparentimage3(NULL, 50, 160, &BK);
	Xue_liang();
}
void Jie::Xue_liang() {
	IMAGE XT;
	loadimage(&XT, L"./xt2.png");
	int i = (HPx * 100) / HP;
	int x = 194 * i / 100;
	putimage(89, 177, x, 20, &XT, 0, 0);
	wchar_t num1[20], num2[20];
	_itow_s(HPx, num1, 10);
	_itow_s(HP, num2, 10);
	outtextxy(180, 205, num1);
	outtextxy(215, 205, L"/");
	outtextxy(225, 205, num2);
}