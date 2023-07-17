#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

 void push(int val)
{
    //create new node
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;

    //make the new node points to the head node
    newNode->next = head;

    //make the new node as head node
    //so that head will always point the last inserted data
    head = newNode;
    
}

void pop()
{
    //temp is used to free the head node
    struct node *temp;

    if(head == NULL)
        printf("Stack is Empty\n");
    else
    {
        printf("Poped element = %d\n", head->data);

        //backup the head node
        temp = head;

        //make the head node points to the next node.
        //logically removing the node
        head = head->next;

        //free the poped element's memory
        free(temp);
    }
}

//print the linked list
void display(FILE *fptr)
{
    struct node *temp = head;

    //iterate the entire linked list and print the data
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         fprintf(fptr,"%d\n",temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
     FILE *fptr;
   fptr=fopen("output.txt","w");
   int val, choice;
   
   while(1){
      printf("\n\n***** MENU *****\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d",&val);
		 push(val);
		 break;
	 case 2: pop();
		 break;
	 case 3: display(fptr);
		 break;
	 case 4: return 0;
	 default: printf("\nWrong selection!!! Try again!!!");
      }
   }
   fclose(fptr);

}
