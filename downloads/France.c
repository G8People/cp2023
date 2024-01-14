#include <stdio.h>
#include <gd.h>

#define WIDTH 900
#define HEIGHT 600
#define BLUE 0x0055A4   // Blue color
#define WHITE 0xFFFFFF  // White color
#define RED 0xEF3340    // Red color

void drawFranceFlag(const char *outputFile) {
    gdImagePtr im;
    FILE *pngout;
    int blueIndex, whiteIndex, redIndex;

    im = gdImageCreateTrueColor(WIDTH, HEIGHT);
    pngout = fopen(outputFile, "wb");

    // Allocate colors
    blueIndex = gdImageColorAllocate(im, (BLUE >> 16) & 0xFF, (BLUE >> 8) & 0xFF, BLUE & 0xFF);
    whiteIndex = gdImageColorAllocate(im, (WHITE >> 16) & 0xFF, (WHITE >> 8) & 0xFF, WHITE & 0xFF);
    redIndex = gdImageColorAllocate(im, (RED >> 16) & 0xFF, (RED >> 8) & 0xFF, RED & 0xFF);

    // Draw flag
    int stripeWidth = WIDTH / 3;

    gdImageFilledRectangle(im, 0, 0, stripeWidth, HEIGHT, blueIndex);
    gdImageFilledRectangle(im, stripeWidth, 0, 2 * stripeWidth, HEIGHT, whiteIndex);
    gdImageFilledRectangle(im, 2 * stripeWidth, 0, WIDTH, HEIGHT, redIndex);

    // Save image
    gdImagePng(im, pngout);
    fclose(pngout);
    gdImageDestroy(im);
}

int main() {
    drawFranceFlag("france_flag.png");
    return 0;
}
