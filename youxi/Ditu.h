#pragma once
#include<iostream>
#include<easyx.h>//easyX нд╪Ч
#include"Chu_Ru.h"
#include"Duixiang.h"
#include"GameInt.h"
#include"Jiemian.h"
void Ditu() {
	if(Kaishi())
		while (1) {
			a.KeyControl(1);
			House1();
			Sleep(80);
			if (Chu_kou1(&a))
				break;
		}
	while (1) {
		a.KeyControl(11);
		Gamedraw();
		Sleep(80);
		if (Ru_kou1(&a)) {
			cleardevice();
			while (1) {
				a.KeyControl(1);
				House1();
				Sleep(80);
				if (Chu_kou1(&a)) {
					break;
				}
			}
		}
		if (Ru_kou2(&a)) {
			cleardevice();
			while (1) {
				a.KeyControl(12);
				Gamedraw2();
				b.Move();
				b.Hu_dong(&a);
				c.Move();
				c.Hu_dong(&a);
				Sleep(80);
				if (Chu_kou2(&a)) {
					break;
				}
			}
		}
		if (Ru_kou3(&a)) {
			cleardevice();
			while (1) {
				a.KeyControl(2);
				House2();
				Sleep(80);
				if (Chu_kou3(&a)) {
					break;
				}
			}
		}
	}
}
