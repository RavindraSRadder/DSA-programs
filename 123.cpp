#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int empId;
    char name[50];
    float salary;
};

void readFromFileAndWriteToFile() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return;
    }

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        fclose(inputFile);
        return;
    }

    printf("Reading data from input file...\n");

    struct Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    while (fscanf(inputFile, "%d,%s,%f\n", &employees[numEmployees].empId, employees[numEmployees].name, &employees[numEmployees].salary) != EOF) {
        numEmployees++;
        if (numEmployees >= MAX_EMPLOYEES) {
            printf("Maximum number of employees reached.\n");
            break;
        }
    }

    fprintf(outputFile, "Employee ID\tName\t\tSalary\n");
    fprintf(outputFile, "--------------------------------\n");

    for (int i = 0; i < numEmployees; i++) {
        fprintf(outputFile, "%d\t\t%s\t\t%.2f\n", employees[i].empId, employees[i].name, employees[i].salary);
    }

    printf("Data successfully written to output file.\n");

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    readFromFileAndWriteToFile();

    return 0;
}

