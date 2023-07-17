#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int key) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node *insertNode(struct Node *node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);

    return node;
}

struct Node *findMinValueNode(struct Node *node) {
    struct Node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMinValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inOrderTraversal(struct Node *node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->key);
        inOrderTraversal(node->right);
    }
}

void convertToBinaryTree(struct Node *node) {
    if (node == NULL)
        return;

    convertToBinaryTree(node->left);
    convertToBinaryTree(node->right);

    if (node->left != NULL) {
        struct Node *temp = node->left;
        while (temp->right != NULL)
            temp = temp->right;
        temp->right = node->right;
        node->right = node->left;
        node->left = NULL;
    }
}

int main() {
    struct Node *root = NULL;
    int num;

    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(fp, "%d", &num) == 1) {
        root = insertNode(root, num);
    }

    fclose(fp);

    printf("Original AVL Tree: ");
    inOrderTraversal(root);
    printf("\n");

    int n, deletion;
    printf("How many numbers do you want to delete? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the number to delete: ");
        scanf("%d", &deletion);
        root = deleteNode(root, deletion);
    }

    printf("Binary Tree: ");
    inOrderTraversal(root);
    printf("\n");

    convertToBinaryTree(root);

    printf("Converted Binary Tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}

