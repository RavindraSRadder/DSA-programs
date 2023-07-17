#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int rollNumber;
    int attendance;
    int score;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int rollNumber, int attendance, int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->rollNumber = rollNumber;
    newNode->attendance = attendance;
    newNode->score = score;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int rollNumber, int attendance, int score) {
    if (root == NULL) {
        return createNode(rollNumber, attendance, score);
    }

    if (score > root->score) {
        root->right = insertNode(root->right, rollNumber, attendance, score);
    } else {
        root->left = insertNode(root->left, rollNumber, attendance, score);
    }

    return root;
}

int calculateBalance(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = calculateBalance(root->left);
    int rightHeight = calculateBalance(root->right);

    return leftHeight - rightHeight;
}

Node* rotateRight(Node* root) {
    Node* newRoot = root->left;
    Node* temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    return newRoot;
}

Node* rotateLeft(Node* root) {
    Node* newRoot = root->right;
    Node* temp = newRoot->left;

    newRoot->left = root;
    root->right = temp;

    return newRoot;
}

Node* balanceTree(Node* root) {
    int balanceFactor = calculateBalance(root);

    if (balanceFactor > 1) {
        if (calculateBalance(root->left) < 0) {
            root->left = rotateLeft(root->left);
        }
        root = rotateRight(root);
    } else if (balanceFactor < -1) {
        if (calculateBalance(root->right) > 0) {
            root->right = rotateRight(root->right);
        }
        root = rotateLeft(root);
    }

    return root;
}

void checkEligibility(Node* root, FILE* outputFile) {
    if (root == NULL) {
        return;
    }

    if (root->attendance >= 75 || root->score > 40) {
        fprintf(outputFile, "Roll Number: %d\n", root->rollNumber);
        fprintf(outputFile, "Attendance: %d\n", root->attendance);
        fprintf(outputFile, "Score: %d\n\n", root->score);
    }

    checkEligibility(root->left, outputFile);
    checkEligibility(root->right, outputFile);
}

int main() {
    FILE* inputFile;
    FILE* outputFile;
    Node* root = NULL;
    int rollNumber, attendance, score;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Failed to open the input file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Failed to open the output file.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d %d %d", &rollNumber, &attendance, &score) != EOF) {
        root = insertNode(root, rollNumber, attendance, score);
        root = balanceTree(root);
    }

    checkEligibility(root, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

