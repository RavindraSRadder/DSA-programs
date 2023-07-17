#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Doctor {
    char name[100];
    int phoneNumber;
    char specialization[100];
    struct Doctor* next;
} Doctor;

Doctor* head = NULL;

void addDoctor() {
    char name[100];
    int phoneNumber;
    char specialization[100];

    printf("Enter doctor's name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the trailing newline character

    printf("Enter doctor's phone number: ");
    scanf("%d", &phoneNumber);
    getchar();  // Consume the newline character from the previous input

    printf("Enter doctor's specialization: ");
    fgets(specialization, sizeof(specialization), stdin);
    specialization[strcspn(specialization, "\n")] = '\0';  // Remove the trailing newline character

    Doctor* newDoctor = (Doctor*)malloc(sizeof(Doctor));
    if (newDoctor == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newDoctor->name, name);
    newDoctor->phoneNumber = phoneNumber;
    strcpy(newDoctor->specialization, specialization);
    newDoctor->next = NULL;

    if (head == NULL) {
        head = newDoctor;
        return;
    }

    Doctor* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newDoctor;
}

void searchDoctor(const char name[]) {
    Doctor* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Doctor Information:\n");
            printf("Name: %s\n", current->name);
            printf("Phone Number: %d\n", current->phoneNumber);
            printf("Specialization: %s\n", current->specialization);
            return;
        }
        current = current->next;
    }
    printf("Doctor not found.\n");
}

void displayDoctors() {
    if (head == NULL) {
        printf("No doctors available.\n");
        return;
    }

    printf("Doctor List:\n");
    Doctor* current = head;
    while (current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Phone Number: %d\n", current->phoneNumber);
        printf("Specialization: %s\n", current->specialization);
        printf("--------------------\n");
        current = current->next;
    }
}

void clearDoctors() {
    Doctor* current = head;
    while (current != NULL) {
        Doctor* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice;
    char name[100];

    while (1) {
        printf("1. Add doctor\n");
        printf("2. Search doctor\n");
        printf("3. Display all doctors\n");
        printf("4. Clear all doctors\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Consume the newline character from the previous input

        switch (choice) {
            case 1:
                addDoctor();
                break;
            case 2:
                printf("Enter doctor's name to search: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';  // Remove the trailing newline character
                searchDoctor(name);
                break;
            case 3:
                displayDoctors();
                break;
            case 4:
                clearDoctors();
                printf("All doctors cleared.\n");
                break;
            case 5:
                clearDoctors();
                printf("Exiting...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}

