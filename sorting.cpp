#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[MAX_SIZE];
    int n, i;

    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    // Read data from input file
    fscanf(input_file, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(input_file, "%d", &arr[i]);
    }

    fclose(input_file);

    // Sort data using different algorithms
    bubble_sort(arr, n);
    // selection_sort(arr, n);
    // insertion_sort(arr, n);

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Failed to open output file.\n");
        return 1;
    }

    // Write sorted data to output file
    fprintf(output_file, "%d\n", n);
    for (i = 0; i < n; i++) {
    	printf("%d  ",arr[i]);
        fprintf(output_file, "%d ", arr[i]);
    }

    fclose(output_file);

    return 0;
}
