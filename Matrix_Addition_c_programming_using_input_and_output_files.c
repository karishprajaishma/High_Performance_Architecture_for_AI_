#include <stdio.h>

int main() {
    int a[2][3], b[2][3], c[2][3];
    FILE *inputFile1, *inputFile2, *outputFile;
    inputFile1 = fopen("input1.txt", "r");
    inputFile2 = fopen("input2.txt", "r");

    if (inputFile1 == NULL || inputFile2 == NULL) {
        printf("Error: Unable to open input files.\n");
        return 1;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(inputFile1, "%d", &a[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            fscanf(inputFile2, "%d", &b[i][j]);
        }
    }
    fclose(inputFile1);
    fclose(inputFile2);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error: Unable to open output file.\n");
        return 1;
    }

    fprintf(outputFile, "The resulting matrix after addition is:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            fprintf(outputFile, "%d\t", c[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    fclose(outputFile);

    printf("Matrix addition completed. Result written to output.txt.\n");
    return 0;
}
