#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 100
#define MAX_SPECIALIZATION_LENGTH 100

typedef struct Doctor {
    char name[MAX_NAME_LENGTH];
    int phoneNumber;
    char specialization[MAX_SPECIALIZATION_LENGTH];
    struct Doctor* next;
} Doctor;

Doctor* head = NULL;

void addDoctor() {
    char name[MAX_NAME_LENGTH];
    int phoneNumber;
    char specialization[MAX_SPECIALIZATION_LENGTH];

    printf("Enter doctor's name: ");
    fgets(name, sizeof(name), stdin);

    // Remove the trailing newline character
    if (name[strlen(name) - 1] == '\n') {
        name[strlen(name) - 1] = '\0';
    }

    printf("Enter doctor's phone number: ");
    scanf("%d", &phoneNumber);
    getchar();  // Consume the newline character from the previous input

    printf("Enter doctor's specialization: ");
    fgets(specialization, sizeof(specialization), stdin);

    // Remove the trailing newline character
    if (specialization[strlen(specialization) - 1] == '\n') {
        specialization[strlen(specialization) - 1] = '\0';
    }

    Doctor* newDoctor = (Doctor*)malloc(sizeof(Doctor));
    if (newDoctor == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    // Copy the name
    for (size_t i = 0; i < sizeof(name); i++) {
        newDoctor->name[i] = name[i];
        if (name[i] == '\0') {
            break;
        }
    }

    newDoctor->phoneNumber = phoneNumber;

    // Copy the specialization
    for (size_t i = 0; i < sizeof(specialization); i++) {
        newDoctor->specialization[i] = specialization[i];
        if (specialization[i] == '\0') {
            break;
        }
    }

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

int compareStrings(const char* str1, const char* str2) {
    size_t i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    }

    return 0;
}

void searchDoctor(const char name[]) {
    Doctor* current = head;
    while (current != NULL) {
        if (compareStrings(current->name, name)) {
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
    char name[MAX_NAME_LENGTH];

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

                // Remove the trailing newline character
                if (name[strlen(name) - 1] == '\n') {
                    name[strlen(name) - 1] = '\0';
                }

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

