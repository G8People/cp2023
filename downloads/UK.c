#include <stdio.h>
#include <gd.h>

#define WIDTH 600
#define HEIGHT 400

#define YELLOW 0xFFD100 // Yellow color
#define BLUE 0x0057A6   // Blue color

void drawUkraineFlag(const char *outputFile) {
    gdImagePtr im;
    FILE *pngout;
    int yellowIndex, blueIndex;

    im = gdImageCreate(WIDTH, HEIGHT);
    pngout = fopen(outputFile, "wb");

    // Allocate colors
    yellowIndex = gdImageColorAllocate(im, (YELLOW >> 16) & 0xFF, (YELLOW >> 8) & 0xFF, YELLOW & 0xFF);
    blueIndex = gdImageColorAllocate(im, (BLUE >> 16) & 0xFF, (BLUE >> 8) & 0xFF, BLUE & 0xFF);

    // Draw flag
    gdImageFilledRectangle(im, 0, 0, WIDTH, HEIGHT, yellowIndex);
    gdImageFilledRectangle(im, 0, HEIGHT / 2, WIDTH, HEIGHT, blueIndex);

    // Save image
    gdImagePng(im, pngout);
    fclose(pngout);
    gdImageDestroy(im);
}

int main() {
    drawUkraineFlag("ukraine_flag.png");
    return 0;
}
