void drawPolandFlag(int width, int height, const char *outputPath) {
    // 建立目標目錄及上層目錄
    createDestinationDirectory(outputPath);

    // 構建目標文件的路徑
    char destinationPath[256];
    snprintf(destinationPath, sizeof(destinationPath), "%s/poland_flag.png", outputPath);

    // 將圖像保存為PNG文件
    gdImagePtr img;
    FILE *pngout;
    pngout = fopen(destinationPath, "wb");

    if (pngout == NULL) {
        fprintf(stderr, "Error opening the output file.\n");
        exit(EXIT_FAILURE);
    }

    img = gdImageCreateTrueColor(width, height);

    // 設置顏色
    int white = gdImageColorAllocate(img, 255, 255, 255);
    int red = gdImageColorAllocate(img, 255, 0, 0);

    // 繪製白色背景
    gdImageFilledRectangle(img, 0, 0, width - 1, height - 1, white);

    // 計算紅條的高度
    int stripeHeight = height / 2;

    // 繪製兩個紅條
    gdImageFilledRectangle(img, 0, 0, width - 1, stripeHeight - 1, red);
    gdImageFilledRectangle(img, 0, height / 2, width - 1, height - 1, red);

    // 將圖像保存為PNG文件
    gdImagePng(img, pngout);
    fclose(pngout);

    // 釋放內存
    gdImageDestroy(img);

    printf("國旗已成功繪製並搬移到目標目錄：%s\n", destinationPath);
}
