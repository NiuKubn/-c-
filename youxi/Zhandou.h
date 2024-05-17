#pragma once
#include"Duixiang.h"
#include<time.h>
#include<easyx.h>
#include<mmsystem.h>//多媒体设备接口
#include <cstdio>
#pragma comment(lib,"winmm.lib")

bool Win(Jingling* a, Renwu* b) {
	if (b->getHPx() <= 0) {
		b->Jiesuan(0);
		b->ChangeHPx(0);
		a->ChangeHPx(a->getHP());
		return 0;
	}
	if (a->getHPx() <= 0) {
		b->Jiesuan(1);
		b->ChangeGJL(5);
		b->ChangeHP(b->getHP() + 100);
		a->ChangeHPx(a->getHP());
		return 0;
	}
	return 1;
}

void Zhandou(Jingling * a,Renwu * b) {
	IMAGE ZD_b,LAN,LAN2;
	loadimage(&ZD_b, L"zhandou.png");
	loadimage(&LAN, L"zd lan.png");
	loadimage(&LAN2, L"zd lan2.png");
	BeginBatchDraw();
	while (Win(a,b)) {
		BeginBatchDraw();
		putimage(0, 70, &ZD_b);
		a->ZDShow(0);
		b->ZDShow(0);
		if (b->getCD() == 0)
			putimage(3, 420, &LAN);
		else
			putimage(3, 420, &LAN2);
		EndBatchDraw();
		ExMessage m;
		if (peekmessage(&m, EX_MOUSE))
			switch (m.message) {
			case WM_LBUTTONDOWN:
				if (m.lbutton && m.x >= 18 && m.x <= 18 + 150 && m.y <= 435 + 63 && m.y >= 435&& b->getCD() == 0) {
					a->ChangeHPx(a->getHPx() - b->Gongji1());
					cleardevice();
					putimage(0, 70, &ZD_b);
					b->ZDShow(20);
					a->ZDShow(0);
					if (b->getCD() == 0)
						putimage(3, 420, &LAN);
					else
						putimage(3, 420, &LAN2);
					Sleep(1000);
					if (a->getHPx() <= 0)
						break;
					b->ChangeHPx(b->getHPx() - a->Gongji());
					cleardevice();
					putimage(0, 70, &ZD_b);
					a->ZDShow(-20);
					b->ZDShow(0);
					if (b->getCD() == 0)
						putimage(3, 420, &LAN);
					else
						putimage(3, 420, &LAN2);
					Sleep(1000);
				}
				if (m.lbutton && m.x >= 178 && m.x <= 178 + 150 && m.y <= 435 + 63 && m.y >= 435) {
					a->ChangeHPx(a->getHPx() - b->Gongji2());
					cleardevice();
					putimage(0, 70, &ZD_b);
					b->ZDShow(20);
					a->ZDShow(0);
					if (b->getCD() == 0)
						putimage(3, 420, &LAN);
					else
						putimage(3, 420, &LAN2);
					Sleep(1000);
					if (b->getCD() != 0)
					b->ChangeCD();
					if (a->getHPx() <= 0)
						break;
					b->ChangeHPx(b->getHPx() - a->Gongji());
					cleardevice();
					putimage(0, 70, &ZD_b);
					a->ZDShow(-20);
					b->ZDShow(0);
					if (b->getCD() == 0)
						putimage(3, 420, &LAN);
					else
						putimage(3, 420, &LAN2);
					Sleep(1000);
				}
				if (m.lbutton && m.x >= 336 && m.x <= 336 + 150 && m.y <= 435 + 63 && m.y >= 435) {
					b->Huifu();
					cleardevice();
					putimage(0, 70, &ZD_b);
					a->ZDShow(0);
					b->ZDShow(0);
					if (b->getCD() == 0)
						putimage(3, 420, &LAN);
					else
						putimage(3, 420, &LAN2);
					Sleep(1000);
					if (b->getCD() != 0)
						b->ChangeCD();
					b->ChangeHPx(b->getHPx() - a->Gongji());
					putimage(0, 70, &ZD_b);
					a->ZDShow(-20);
					b->ZDShow(0);
					if (b->getCD() == 0)
						putimage(3, 420, &LAN);
					else
						putimage(3, 420, &LAN2);
					Sleep(1000);
				}
				if (m.lbutton && m.x >= 521 && m.x <= 521+77 && m.y <= 435 + 63 && m.y >= 435) {
					int i = 0;
					srand((unsigned int)time(NULL));
					if ((rand() % 100 + 1) <= 50) {
						b->Taopao(1);
						Sleep(1000);
						goto loop;
					}
					else{
					b->Taopao(0);
					Sleep(1000);
					b->ChangeHPx(b->getHPx() - a->Gongji());
					putimage(0, 70, &ZD_b);
					a->ZDShow(-20);
					b->ZDShow(0);
					if (b->getCD() != 0)
						b->ChangeCD();
					if (b->getCD() == 0)
						putimage(3, 420, &LAN);
					else
						putimage(3, 420, &LAN2);
					}
				}
				break;
			default:
				break;
			}
	}
loop:
		EndBatchDraw();
}

bool Xuan_ze() {
	while (1) {
		if (GetAsyncKeyState('Y' & 0x59)) {
			return 1;
		}
		if (GetAsyncKeyState('N' & 0x4E)) {
			return 0;
		}
	}
}
