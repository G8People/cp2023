#include <stdio.h>
#include <gd.h>

int main() {
    int width = 600;   // 設置寬度
    int height = 400;  // 設置高度

    gdImagePtr image = gdImageCreateTrueColor(width, height);

    // 設置顏色
    int white = gdImageColorAllocate(image, 255, 255, 255);
    int red = gdImageColorAllocate(image, 255, 0, 0);

    // 繪製白色背景
    gdImageFilledRectangle(image, 0, 0, width - 1, height - 1, white);

    // 計算紅條的高度（波蘭國旗有兩個紅條）
    int stripeHeight = height / 2;

    // 繪製兩個紅條
    gdImageFilledRectangle(image, 0, 0, width - 1, stripeHeight - 1, red);
    gdImageFilledRectangle(image, 0, height / 2, width - 1, height - 1, red);

    // 輸出圖像
    FILE *outputFile = fopen("poland_flag.png", "wb");
    gdImagePng(image, outputFile);
    fclose(outputFile);

    // 釋放內存
    gdImageDestroy(image);

    return 0;
}
