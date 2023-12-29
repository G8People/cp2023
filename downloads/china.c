#include <stdio.h>
#include <gd.h>

void drawPolishFlag(int width, int height, const char *outputFileName) {
    gdImagePtr im;
    FILE *pngout;

    // Create a new image with the specified width and height
    im = gdImageCreateTrueColor(width, height);

    // Allocate the colors for white and red
    int white = gdImageColorAllocate(im, 255, 255, 255);
    int red = gdImageColorAllocate(im, 255, 0, 0);

    // Draw the white rectangle (top half)
    gdImageFilledRectangle(im, 0, 0, width - 1, height / 2 - 1, white);

    // Draw the red rectangle (bottom half)
    gdImageFilledRectangle(im, 0, height / 2, width - 1, height - 1, red);

    // Save the image to a file
    pngout = fopen(outputFileName, "wb");
    gdImagePng(im, pngout);
    fclose(pngout);

    // Free up memory
    gdImageDestroy(im);
}

int main() {
    int width = 600;
    int height = 400;
    const char *outputFileName = "poland_flag.png";

    drawPolishFlag(width, height, outputFileName);

    printf("Poland flag has been created and saved as %s.\n", outputFileName);

    return 0;
}