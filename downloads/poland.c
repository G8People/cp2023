#include <stdio.h>
#include <gd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

void drawPolandFlag(int width, int height) {
    // ...（與之前的程式碼相同）
}

void createDestinationDirectory(const char *path) {
    struct stat st = {0};

    if (stat(path, &st) == -1) {
        // 如果目錄不存在，則創建目錄
        int status = mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

        if (status == 0) {
            printf("目錄已成功建立。\n");
        } else {
            fprintf(stderr, "建立目錄時發生錯誤：%s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    } else {
        printf("目錄已存在。\n");
    }
}

int main() {
    int width = 16;   // 設置寬度
    int height = 10;  // 設置高度

    // 建立目標目錄（請替換成實際的目錄路徑）
    createDestinationDirectory("/path/to/destination/");

    // 繪製國旗並搬移到目標目錄
    drawPolandFlag(width, height);
    int result = system("mv poland_flag.png /path/to/destination/");
    if (result != 0) {
        fprintf(stderr, "搬移文件時發生錯誤。\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
