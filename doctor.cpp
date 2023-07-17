#include<stdio.h>
#include<stdlib.h>

#include <string.h>


typedef struct node {
    char name[100];
    char specialization[100];
    char medicine[100];
    struct Doctor* prev;
    struct Doctor* next;
} Dr;


Dr* createDr(char* name, char* specialization, char* medicine) {
    Dr* newDr = (Dr*)malloc(sizeof(Dr));
    strcpy(newDr->name, name);
    strcpy(newDr->specialization, specialization);
    strcpy(newDr->medicine, medicine);
    newDr->prev = NULL;
    newDr->next = NULL;
    return newDr;
}

void insertDr(Dr** head, char* name, char* specialization, char* medicine) {
    Dr* newDr = createDr(name, specialization, medicine);
    if (*head == NULL) {
        *head = newDr;
    } else {
        Dr* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newDr;
        newDr->prev = temp;
    }
}

void searchandrecommendMedicine(Dr* head, char* specialization, char* newMedicine) {
    Dr* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->specialization, specialization) == 0) {
            printf("doctor Name=%s\n", temp->name);
            printf("specialization=%s\n", temp->specialization);
            printf("prescribed medicine=%s\n", temp->medicine);
            strcpy(temp->medicine, newMedicine);
            printf("recommending new medicine= %s\n", temp->medicine);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("no doctors\n");
    }
}


void displayDoctors(Dr* head) {
    Dr* temp = head;
    while (temp != NULL) {
        printf("Doctor Name= %s\n", temp->name);
        printf("Specialization= %s\n", temp->specialization);
        printf("Prescribed Medicine=%s\n", temp->medicine);
        printf("\n\n");
        temp = temp->next;
    }
}

// Main function
int main() {
    Dr* head = NULL;
    int numDrs;
    char name[100], specialization[100], medicine[100];

    printf("Enter the number of doctors: ");
    scanf("%d", &numDrs);

    for (int i = 0; i < numDrs; i++) {
        printf("\nDoctor %d\n", i + 1);
        printf("Enter Doctor Name= ");
        scanf("%s", name);
        printf("Enter Specialization=");
        scanf("%s", specialization);
        printf("Enter Prescribed Medicine= ");
        scanf("%s", medicine);
        insertDr(&head, name, specialization, medicine);
    }

    printf("\nList of Doctors:\n");
    displayDoctors(head);

    printf("Enter Specialization for search new recomedation\n ");
    scanf("%s", specialization);
    printf("Enter New Medicine to recommend: ");
    scanf("%s", medicine);
    printf("\n");

    searchandrecommendMedicine(head, specialization, medicine);

    return 0;
}
