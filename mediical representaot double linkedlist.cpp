#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing doctor information
typedef struct Doctor {
    char name[50];
    char specialization[50];
    char medicine[50];
    struct Doctor* next;
} Doctor;

// Function to create a new doctor node
Doctor* createDoctorNode(char* name, char* specialization, char* medicine) {
    Doctor* newNode = (Doctor*)malloc(sizeof(Doctor));
    strcpy(newNode->name, name);
    strcpy(newNode->specialization, specialization);
    strcpy(newNode->medicine, medicine);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a doctor at the end of the list
void insertDoctor(Doctor** head, char* name, char* specialization, char* medicine) {
    Doctor* newNode = createDoctorNode(name, specialization, medicine);

    if (*head == NULL) {
        *head = newNode;
    } else {
        Doctor* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to find a doctor by specialization and change the medicine
void changeMedicine(Doctor* head, char* specialization, char* newMedicine) {
    Doctor* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->specialization, specialization) == 0) {
            strcpy(temp->medicine, newMedicine);
            printf("Medicine changed for %s, specialization: %s\n", temp->name, temp->specialization);
            return;
        }
        temp = temp->next;
    }
    printf("Doctor with specialization %s not found\n", specialization);
}

// Function to display the linked list
void displayList(Doctor* head) {
    Doctor* temp = head;
    while (temp != NULL) {
        printf("Doctor: %s\nSpecialization: %s\nMedicine: %s\n\n", temp->name, temp->specialization, temp->medicine);
        temp = temp->next;
    }
}

// Main function
int main() {
    Doctor* head = NULL;

    int numDoctors;
    printf("Enter the number of doctors: ");
    scanf("%d", &numDoctors);
    getchar(); // Clear the newline character from the previous input

    // Input doctor information
    for (int i = 0; i < numDoctors; i++) {
        char name[50], specialization[50], medicine[50];
        printf("\nEnter details for Doctor %d:\n", i + 1);

        // Input doctor name
        printf("Enter name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline character

        // Input doctor specialization
        printf("Enter specialization: ");
        fgets(specialization, sizeof(specialization), stdin);
        specialization[strcspn(specialization, "\n")] = '\0'; // Remove newline character

        // Input doctor medicine
        printf("Enter medicine: ");
        fgets(medicine, sizeof(medicine), stdin);
        medicine[strcspn(medicine, "\n")] = '\0'; // Remove newline character

        insertDoctor(&head, name, specialization, medicine);
    }

    // Display the list of doctors
    printf("\nList of Doctors:\n");
    displayList(head);

    // Change medicine for a doctor with a specific specialization
    char specialization[50], newMedicine[50];
    printf("\nEnter specialization to change medicine: ");
    fgets(specialization, sizeof(specialization), stdin);
    specialization[strcspn(specialization, "\n")] = '\0'; // Remove newline character

    printf("Enter new medicine: ");
    fgets(newMedicine, sizeof(newMedicine), stdin);
    newMedicine[strcspn(newMedicine, "\n")] = '\0'; // Remove newline character

    changeMedicine(head, specialization, newMedicine);

    // Display the updated list
    printf("\nUpdated List:\n");
    displayList(head);

    return 0;
}

