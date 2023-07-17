#include <stdio.h>

#define MAX_NUMBERS 10
#define MAX_STRING_LENGTH 100

int main() {
    FILE *inputFile;
    FILE *outputFile;
    char string[MAX_STRING_LENGTH];
    int numbers[MAX_NUMBERS];
    int numCount;
    int i, j;

    // Open the input file in read mode
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    // Open the output file in write mode
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read and process each set of numbers
    for (i = 0; i < 10; i++) {
        // Read the string from the input file
        fscanf(inputFile, "%s", string);

        // Read the numbers from the input file and store them in the array
        numCount = 0;
        for (j = 0; j < MAX_NUMBERS; j++) {
            if (fscanf(inputFile, "%d", &numbers[j]) != 1)
                break;
            numCount++;
        }

        // Print the string to the output file
        fprintf(outputFile, "String %d: %s\n", i+1, string);

        // Print the numbers to the output file
        fprintf(outputFile, "Numbers %d:\n", i+1);
        for (j = 0; j < numCount; j++) {
            fprintf(outputFile, "%d\n", numbers[j]);
        }
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Data has been read from the input file and written to the output file.\n");

    return 0;
}

