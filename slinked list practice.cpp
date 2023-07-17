#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to insert a node at a specified position in the linked list
void insertAtPosition(Node** head, int data, int position) {
    if (position <= 0) {
        insertAtBeginning(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* current = *head;
    int count = 1;

    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position. Insertion at the end.\n");
        insertAtEnd(head, data);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete the first node in the linked list
void deleteAtBeginning(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete the last node in the linked list
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Function to delete a node at a specified position in the linked list
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty. Unable to delete.\n");
        return;
    }

    if (position <= 0) {
        deleteAtBeginning(head);
        return;
    }

    Node* current = *head;
    Node* previous = NULL;
    int count = 1;

    while (current != NULL && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Invalid position. Unable to delete.\n");
        return;
    }

    if (previous == NULL) {
        *head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
}

// Function to count the occurrences of a data value in the linked list
int countData(Node* head, int data) {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            count++;
        }
        current = current->next;
    }

    return count;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a position\n");
        printf("7. Count data occurrences\n");
        printf("8. Print the linked list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                printf("Node inserted at the beginning.\n");
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("Node inserted at the end.\n");
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                printf("Node inserted at position %d.\n", position);
                break;
            case 4:
                deleteAtBeginning(&head);
                printf("Node deleted from the beginning.\n");
                break;
            case 5:
                deleteAtEnd(&head);
                printf("Node deleted from the end.\n");
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                printf("Node deleted from position %d.\n", position);
                break;
            case 7:
                printf("Enter data to count occurrences: ");
                scanf("%d", &data);
                printf("Count of %d: %d\n", data, countData(head, data));
                break;
            case 8:
                printf("Linked List: ");
                printLinkedList(head);
                break;
            case 9:
                freeLinkedList(head);
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

