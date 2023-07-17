#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    
    return stack->data[stack->top--];
}

void writeNumbersToFile(const char* filename, Stack* stack) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    
    while (!isEmpty(stack)) {
        int number = pop(stack);
        fprintf(file, "%d\n", number);
    }
    
    fclose(file);
}

void readNumbersFromFile(const char* filename, Stack* stack) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return;
    }
    
    int number;
    while (fscanf(file, "%d", &number) == 1) {
        push(stack, number);
    }
    
    fclose(file);
}

int main() {
    Stack stack;
    initialize(&stack);
    
    // Read numbers from input file and push them onto the stack
    readNumbersFromFile("input.txt", &stack);
    
    // Write numbers from stack into output file
    writeNumbersToFile("output.txt", &stack);
    
    printf("Numbers read from file and pushed to stack.\n");
    printf("Numbers popped from stack and written to file.\n");
    
    return 0;
}

