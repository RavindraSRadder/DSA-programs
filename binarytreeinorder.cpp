#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
	
};

struct node *newnode (int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->right=NULL;
	node->left=NULL;
	return (node);
}

void printinorder(struct node *node)
{
	FILE *fptr;
	fptr=fopen("inorder.txt","w");
	if(node==NULL)
	{
		return;
	}
	printinorder(node->left);
	fprintf(fptr,"%d  ",node->data);
	printf("%d  ",node->data);
	printinorder(node->right);
	fclose(fptr);
	
	
}
void printpreorder(struct node *node)
{
	FILE *fptr;
	fptr=fopen("preoder.txt","w");
	if(node==NULL)
	{
		return;
	}
	fprintf(fptr,"%d  ",node->data);
	printf("%d  ",node->data);
	printinorder(node->left);
	printinorder(node->right);
	fclose(fptr);
}



void printpostorder(struct node *node)
{
	FILE *fptr;
	fptr=fopen("preoder.txt","w");
	if(node==NULL)
	{
		return;
	}

	printinorder(node->left);
	printinorder(node->right);
		fprintf(fptr,"%d  ",node->data);
	printf("%d  ",node->data);
	fclose(fptr);
}




	
int main()
{
	    struct node* root;
	 int n,i,datal,datar,rootn;
	 printf("how many numbers\n");
	 scanf("%d",&n);
	 printf("enter root\n");
	 scanf("%d", &rootn);
	 root = newnode(rootn);
	 for(i=0;i<n;i++)
	 {
	 	printf("enter left\n");
	 	scanf("%d",&datal);
	 	    root->left = newnode(datal);
	 	printf("enter right \n");
	 	scanf("%d",&datar);
	    root->right = newnode(datar);	
	    root->left=root->left->left;
	    root->right=root->right->right;
	 }
	
   /* root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
	 
   */
	
	
    // Function call
    printf("Inorder traversal of binary tree is \n");
    printinorder(root);
    
    printf("\npreorder\n");
    printpreorder(root);
    
    
    printf("\npostorder\n");
    printpostorder(root);
    
    
 
    getchar();
    return 0;
}
