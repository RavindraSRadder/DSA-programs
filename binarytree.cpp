#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void storePreorder(struct Node* node, FILE* fp) {
    if (node == NULL)
        return;
 FILE *f1;
 f1=fopen("preorder.txt","w");
    fprintf(fp, "%d ", node->data);
      fprintf(f1, "%d ", node->data);
 

    storePreorder(node->left, fp);
    storePreorder(node->right, fp);
       fclose(f1);
}

void storeInorder(struct Node* node, FILE* fp) {
    if (node == NULL)
        return;
 FILE *f1;
 f1=fopen("inorder.txt","w");
    storeInorder(node->left, fp);

    fprintf(fp, "%d ", node->data);
   fprintf(f1, "%d ", node->data);
    storeInorder(node->right, fp);
    fclose(f1);
}

void storePostorder(struct Node* node, FILE* fp) {
    if (node == NULL)
        return;
 FILE *f1;
 f1=fopen("postorder.txt","w");
    storePostorder(node->left, fp);
    storePostorder(node->right, fp);

    fprintf(fp, "%d ", node->data);
    
    fprintf(f1, "%d ", node->data);
    fclose(f1);
}

int main() {
    
    int n ;
    printf("how many random numbers u want\n");
    scanf("%d",&n);
	  
    int* numbers = (int*)malloc(n * sizeof(int));

    printf("Random numbers: ");
    for (int i = 0; i < n; i++) {
        numbers[i] = rand() % 100;  
        printf("%d ", numbers[i]);
    }
    printf("\n");


    struct Node* root = newNode(numbers[0]);
    for (int i = 1; i < n; i++) {
        struct Node* node = newNode(numbers[i]);
        struct Node* current = root;
        struct Node* parent = NULL;

        while (current != NULL) {
            parent = current;
            if (node->data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (node->data < parent->data)
            parent->left = node;
        else
            parent->right = node;
    }


    FILE* fp = fopen("binary_tree.txt", "w");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    fprintf(fp, "Pre-order traversal: ");
    storePreorder(root, fp);
    fprintf(fp, "\n");

    fprintf(fp, "In-order traversal: ");
    storeInorder(root, fp);
    fprintf(fp, "\n");

    fprintf(fp, "Post-order traversal: ");
    storePostorder(root, fp);
    fprintf(fp, "\n");

    
    fclose(fp);

    printf("Data stored in the file successfully.\n");


    free(numbers);

    return 0;
}

