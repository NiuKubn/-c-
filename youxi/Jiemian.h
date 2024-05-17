#pragma once
#include<easyx.h>
#include"pngÌùÍ¼2.h"
bool Kaishi() {
	IMAGE KS,PL;
	ExMessage m;
	loadimage(&KS, L"kaishi.png");
	loadimage(&PL, L"PLAY.png");
	transparentimage1(NULL, 0, 0, &KS);
	transparentimage1(NULL, 213, 480, &PL);
	while (1) {
		if (peekmessage(&m, EX_MOUSE))
			switch (m.message) {
			case WM_LBUTTONDOWN:
				if (m.lbutton && m.x >= 213&& m.x <= 213+226 && m.y <= 480+70 && m.y >= 480) {
					cleardevice();
					return 1;
				}
				break;
			default:
				break;
			}
	}
}