#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the correct position in the linked list
void insertInOrder(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && data > current->next->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the linked list
void display(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));

    // Create an empty linked list
    Node* head = NULL;

    int n;
    printf("Enter the number of random numbers: ");
    scanf("%d", &n);

    // Read n random numbers from the user and insert them in ascending order
    printf("Enter %d random numbers:\n", n);
    for (int i = 0; i < n; i++) {
        int randomNumber;
        scanf("%d", &randomNumber);
        insertInOrder(&head, randomNumber);
    }

    // Display the linked list in ascending order
    printf("Linked list in ascending order: ");
    display(head);

    return 0;
}

