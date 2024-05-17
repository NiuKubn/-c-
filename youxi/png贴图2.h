#pragma once
#include <graphics.h>	
#include <conio.h>
#pragma comment( lib, "MSIMG32.LIB")
void transparentimage1(IMAGE* dstimg, int x, int y, IMAGE* srcimg) //ÐÂ°æpng
{
    HDC dstDC = GetImageHDC(dstimg);
    HDC srcDC = GetImageHDC(srcimg);
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
    AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}