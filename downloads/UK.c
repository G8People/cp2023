#include <stdio.h>
#include <gd.h>

int main() {
    // 定义图像宽度和高度
    int width = 600;
    int height = 400;

    // 创建图像
    gdImagePtr im = gdImageCreateTrueColor(width, height);

    // 定义颜色
    int white = gdImageColorAllocate(im, 255, 255, 255);
    int red = gdImageColorAllocate(im, 255, 0, 0);
    int blue = gdImageColorAllocate(im, 0, 0, 255);

    // 绘制白色背景
    gdImageFilledRectangle(im, 0, 0, width - 1, height - 1, white);

    // 绘制红色横条
    gdImageFilledRectangle(im, 0, height / 3, width - 1, 2 * height / 3, red);

    // 绘制红色竖条
    gdImageFilledRectangle(im, width / 3, 0, 2 * width / 3, height - 1, red);

    // 绘制蓝色斜条
    int points[8] = {
        width / 6, height / 6,
        5 * width / 6, height / 6,
        width / 6, 5 * height / 6,
        5 * width / 6, 5 * height / 6
    };
    gdImageFilledPolygon(im, points, 4, blue);

    // 保存图像到指定输出文件
    FILE *outputFile = fopen("UK_flag.png", "wb");
    if (outputFile == NULL) {
        fprintf(stderr, "打开输出文件时出错。\n");
        return 1;
    }

    // 以PNG格式保存图像
    gdImagePng(im, outputFile);

    // 关闭输出文件
    fclose(outputFile);

    // 释放图像内存
    gdImageDestroy(im);

    return 0;
}
