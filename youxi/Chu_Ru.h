#pragma once
#include"Duixiang.h"
bool Ru_kou1(Renwu* b) {
	if (b->getx() >= 180 && b->getx() <= 200)
	{
		if (b->gety() >= 520 && b->gety() <= 531) {
			if (b->getdir() == 'w')
			{
				int k1 = 260, k2 = 375;
				b->ChangeX(k1);
				b->ChangeY(k2);
				return true;
			}
		}
	}
	return false;
}
bool Chu_kou1(Renwu* b) {
	if (b->getx() >= 245 && b->getx() <= 275)
	{
		if (b->gety() >= 370 && b->gety() <= 380) {
			if (b->getdir() == 's')
			{
				int k1 = 190, k2 = 540;
				b->ChangeX(k1);
				b->ChangeY(k2);
				return true;
			}
		}
	}
	return false;
}

bool Ru_kou3(Renwu* b) {
	if (b->getx() >= 435 && b->getx() <= 455)
	{
		if (b->gety() >= 200 && b->gety() <= 210) {
			if (b->getdir() == 'w')
			{
				int k1 = 300, k2 = 380;
				b->ChangeX(k1);
				b->ChangeY(k2);
				return true;
			}
		}
	}
	return false;
}
bool Chu_kou3(Renwu* b) {
	if (b->getx() >= 290 && b->getx() <= 310)
	{
		if (b->gety() >= 375 && b->gety() <= 385) {
			if (b->getdir() == 's')
			{
				int k1 = 445, k2 = 195;
				b->ChangeX(k1);
				b->ChangeY(k2);
				return true;
			}
		}
	}
	return false;
}

bool Ru_kou2(Renwu* b) {
	if (b->getx() >= 628)
	{
		int k1 = 0, k2 = 520;
		b->ChangeX(k1);
		b->ChangeY(k2);
		return true;
	}
	return false;
}
bool Chu_kou2(Renwu* b) {
	if (b->getx() <= 0)
	{
		int k1 = 628;
		int k2 = 320;
		b->ChangeX(k1);
		b->ChangeY(k2);
		return true;
	}
	return false;
}
