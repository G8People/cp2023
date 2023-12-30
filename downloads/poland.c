#include <stdio.h>
#include <gd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

void createDestinationDirectory(const char *path) {
    struct stat st = {0};

    // 檢查目錄是否存在
    if (stat(path, &st) == -1) {
        // 如果目錄不存在，則創建目錄
        int status = mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

        if (status == 0) {
            printf("目錄已成功建立：%s\n", path);
        } else {
            fprintf(stderr, "建立目錄時發生錯誤：%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else {
        printf("目錄已存在：%s\n", path);
    }
}

void drawPolandFlag(int width, int height, const char *outputPath) {
    // 建立目標目錄及上層目錄
    createDestinationDirectory(outputPath);

    // 構建目標文件的路徑
    char destinationPath[256];
    snprintf(destinationPath, sizeof(destinationPath), "%s/poland_flag.png", outputPath);

    // 將圖像保存為PNG文件
    FILE *pngout;
    pngout = fopen(destinationPath, "wb");

    if (pngout == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        exit(EXIT_FAILURE);
    }

    gdImagePtr img;
    img = gdImageCreateTrueColor(width, height);

    // 設置顏色
    int white = gdImageColorAllocate(img, 255, 255, 255);
    int red = gdImageColorAllocate(img, 255, 0, 0);

    // 繪製白色背景
    gdImageFilledRectangle(img, 0, 0, width - 1, height - 1, white);

    // 計算紅條的高度
    int stripeHeight = height / 2;

    // 繪製紅色條紋
    gdImageFilledRectangle(img, 0, stripeHeight, width - 1, height - 1, red);

    // 將圖像保存為PNG文件
    gdImagePng(img, pngout);
    fclose(pngout);

    // 釋放內存
    gdImageDestroy(img);

    printf("波蘭國旗已成功繪製並搬移到目標目錄：%s\n", destinationPath);
}

int main() {
    int width = 16;   // 設置寬度
    int height = 10;  // 設置高度

    // 替換成實際的目錄路徑
    const char *outputPath = "./../images/";

    // 繪製國旗
    drawPolandFlag(width, height, outputPath);

    return 0;
}
