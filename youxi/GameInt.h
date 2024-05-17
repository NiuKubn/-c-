#pragma once
#include<iostream>
#include<easyx.h>
#include<mmsystem.h>//多媒体设备接口
#include"Duixiang.h"
#pragma comment(lib,"winmm.lib")
using namespace std;
Renwu a(400,300, 300);
Miao b(160 ,115,428,178,300,'s');
Jie c(405, 380,418,138, 4000, 's');
IMAGE Bei_jing1,Bei_jing2,HOUSE1,HOUSE2;
void PlayBGM()
{
	mciSendString(L"open bgm.mp3 repeat", 0, 0, 0);
	mciSendString(L"play bgm.mp3", 0, 0, 0);
	//mciSendString(L"close bgm.mp3", 0, 0, 0);
}
void GameInt(){
	initgraph(628, 628);
	loadimage(&Bei_jing1, L"background.png");
	loadimage(&Bei_jing2, L"background2.png");
	loadimage(&HOUSE1, L"House1.png");
	loadimage(&HOUSE2,L"House2.png");
}
void Gamedraw() {
	BeginBatchDraw();
	putimage(0, 0, &Bei_jing1);
	a.Show();
	EndBatchDraw();
}
void Gamedraw2() {
	BeginBatchDraw();
	putimage(0, 0, &Bei_jing2);
	b.Show();
	a.Show();
	c.Show();
	EndBatchDraw();
}
void House1() {
	BeginBatchDraw();
	putimage(150, 150, &HOUSE1);
	a.Show();
	EndBatchDraw();
}
void House2() {
	BeginBatchDraw();
	putimage(100, 150, &HOUSE2);
	a.Show();
	EndBatchDraw();
}


