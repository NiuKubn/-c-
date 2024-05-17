#include "Jingling.h"
#include "png贴图.h"
Jingling::Jingling(int i,int j,int  xu,char di){
	x = i;
	y = j;
	dir = di;
	Xue_liang = xu;
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
		if (flag == 4)
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
		if (flag == 4)
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
		if (flag == 4)
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
		if (flag == 4)
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
void Jingling::Yi_dong() {

}

Miao::Miao(int i, int j,int x, char di) :Jingling(i, j, x, di) {
	loadimage(&JL_d, L"./renwu/renwu 正.png");
	loadimage(&JL_l, L"./renwu/renwu 左.png");
	loadimage(&JL_r, L"./renwu/renwu 右.png");
	loadimage(&JL_u, L"./renwu/renwu 后.png");
	loadimage(&JL_d1, L"./renwu/renwu 正1.png");
	loadimage(&JL_l1, L"./renwu/renwu 左1.png");
	loadimage(&JL_r1, L"./renwu/renwu 右1.png");
	loadimage(&JL_u1, L"./renwu/renwu 后1.png");
	loadimage(&JL_d2, L"./renwu/renwu 正2.png");
	loadimage(&JL_l2, L"./renwu/renwu 左2.png");
	loadimage(&JL_r2, L"./renwu/renwu 右2.png");
	loadimage(&JL_u2, L"./renwu/renwu 后2.png");
}