#include <stdio.h>
#include <gd.h>
#include <math.h>

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

void drawCircle(const char *outputFile) {
    gdImagePtr im;
    FILE *pngout;
    int whiteIndex;

    im = gdImageCreate(WIDTH, HEIGHT);
    pngout = fopen(outputFile, "wb");

    // Allocate color
    whiteIndex = gdImageColorAllocate(im, 255, 255, 255);

    // Draw circle
    gdImageFilledEllipse(im, WIDTH / 2, HEIGHT / 2, WIDTH / 2, HEIGHT / 2, whiteIndex);

    // Save image
    gdImagePng(im, pngout);
    fclose(pngout);
    gdImageDestroy(im);
}

void drawSineWave(const char *outputFile) {
    gdImagePtr im;
    FILE *pngout;
    int redIndex;

    im = gdImageCreate(WIDTH, HEIGHT);
    pngout = fopen(outputFile, "wb");

    // Allocate color
    redIndex = gdImageColorAllocate(im, 255, 0, 0);

    // Draw sine wave
    for (int x = 0; x < WIDTH; x++) {
        int y = HEIGHT / 2 + HEIGHT / 4 * sin(2 * M_PI * x / WIDTH);
        gdImageSetPixel(im, x, y, redIndex);
    }

    // Save image
    gdImagePng(im, pngout);
    fclose(pngout);
    gdImageDestroy(im);
}

int main() {
    drawUkraineFlag("ukraine_flag.png");
    drawCircle("circle.png");
    drawSineWave("sine_wave.png");
    return 0;
}
