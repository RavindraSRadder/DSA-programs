#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure to represent a car
typedef struct {
    char name[50];
    int price;
    float rating;
} Car;

// Structure to represent a stack
typedef struct {
    Car cars[MAX_SIZE];
    int top;
} CarStack;

// Function to initialize the stack
void initializeStack(CarStack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(CarStack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(CarStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(CarStack* stack, Car car) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push car %s\n", car.name);
    } else {
        stack->cars[++stack->top] = car;
        printf("Car %s pushed onto the stack\n", car.name);
    }
}

// Function to pop an element from the stack
Car pop(CarStack* stack) {
    Car emptyCar;
    strcpy(emptyCar.name, "");
    emptyCar.price = 0;
    emptyCar.rating = 0.0;

    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop car\n");
        return emptyCar;
    } else {
        Car poppedCar = stack->cars[stack->top--];
        printf("Car %s popped from the stack\n", poppedCar.name);
        return poppedCar;
    }
}

// Function to get the top element of the stack
Car top(CarStack* stack) {
    Car emptyCar;
    strcpy(emptyCar.name, "");
    emptyCar.price = 0;
    emptyCar.rating = 0.0;

    if (isEmpty(stack)) {
        printf("Stack is empty. No top car\n");
        return emptyCar;
    } else {
        return stack->cars[stack->top];
    }
}

// Main function
int main() {
    CarStack stack;
    initializeStack(&stack);

    // Input car details
    int numCars;
    printf("Enter the number of cars: ");
    scanf("%d", &numCars);

    for (int i = 0; i < numCars; i++) {
        Car newCar;
        printf("\nEnter details for Car %d:\n", i + 1);

        // Input car name
        printf("Enter car name: ");
        scanf("%s", newCar.name);

        // Input car price
        printf("Enter car price: ");
        scanf("%d", &newCar.price);

        // Input car rating
        printf("Enter car rating: ");
        scanf("%f", &newCar.rating);

        push(&stack, newCar);
    }

    // Set budget and select a car
    int budget;
    printf("\nEnter your budget: ");
    scanf("%d", &budget);

    Car selectedCar = top(&stack);
    if (selectedCar.price <= budget) {
        printf("\nSelected car: %s\nPrice: %d\nRating: %.2f\n", selectedCar.name, selectedCar.price, selectedCar.rating);
    } else {
        printf("\nNo car within your budget\n");
    }

    // Check if old car exchange is possible
    char exchangeOption;
    printf("\nDo you have an old car for exchange? (Y/N): ");
    scanf(" %c", &exchangeOption);

    if (exchangeOption == 'Y' || exchangeOption == 'y') {
        float discount = 0.10; // 10% discount for exchange
        int discountAmount = selectedCar.price * discount;
        int finalPrice = selectedCar.price - discountAmount;

        printf("\nCar %s is available for exchange with a discount of %.2f%%\n", selectedCar.name, discount * 100);
        printf("Final price after discount: %d\n", finalPrice);
    }

    return 0;
}

