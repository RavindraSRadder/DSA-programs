#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct Node {
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};

int max(int a, int b);


int height(struct Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}


struct Node *newNode(int key) {
  struct Node *node = (struct Node *)
    malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}


struct Node *rotateRight(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}


struct Node *rotateLeft(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}


int getBalance(struct Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

struct Node *insertNode(struct Node *node, int key) {

  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;


  node->height = 1 + max(height(node->left),
               height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rotateRight(node);

  if (balance < -1 && key > node->right->key)
    return rotateLeft(node);

  if (balance > 1 && key > node->left->key) {
    node->left = rotateLeft(node->left);
    return rotateRight(node);
  }

  if (balance < -1 && key < node->right->key) {
    node->right = rotateRight(node->right);
    return rotateLeft(node);
  }

  return node;
}

struct Node *minValueNode(struct Node *node) {
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
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rotateRight(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = rotateLeft(root->left);
    return rotateRight(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return rotateLeft(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rotateRight(root->right);
    return rotateLeft(root);
  }

  return root;
}

void printPreOrder(struct Node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}
void printpostOrder(struct Node *root) {
  if (root != NULL) {
   
    printpostOrder(root->left);
    printpostOrder(root->right);
     printf("%d ", root->key);
  }
}

void printinOrder(struct Node *root) {
  if (root != NULL) {
  
    printinOrder(root->left);
      printf("%d ", root->key);
    printinOrder(root->right);
  }
}
int main() {

  struct Node *root = NULL;
  int num;

  FILE *fp;

  fp = fopen("input.txt", "w"); 

  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  int number;
  printf("How many random numbers do you want to generate? ");
  scanf("%d", &number);


  srand(time(NULL)); 
  for (int i = 0; i < number; i++) {
    num = rand() % 100;
    fprintf(fp, "%d\n", num); 
  }

  fclose(fp); // Close the file
  fp = fopen("input.txt", "r");

  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  while (fscanf(fp, "%d", &num) == 1) {
    root = insertNode(root, num);
  }

  fclose(fp);

  printf("Original Tree: ");
  printPreOrder(root);
  printf("\n");
  printinOrder(root);
  printf("\n");
  printpostOrder(root);
  printf("\n");

  int n, deletion;
  printf("How many numbers do you want to delete? ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter the number to delete: ");
    scanf("%d", &deletion);
    root = deleteNode(root, deletion);
  }

  printf("After deletion: ");
  printPreOrder(root);
  printf("\n");

  printf("rotation\n");

  root = rotateLeft(root);
  printf("Tree after rotateLeft: ");
  printPreOrder(root);
  printf("\n");

  root = rotateRight(root);
  printf("Tree after rotateRight: ");
  printPreOrder(root);
  printf("\n");

  return 0;
}


