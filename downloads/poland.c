FILE *outputFile = fopen("./../images/japan_flag.png", "wb");
if (outputFile == NULL) {
    fprintf(stderr, "Error opening the output file.\n");
    return 1;
}