#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 50
 
void insert();
void deletef();
void display(FILE *fptr);
int queue_array[CAPACITY];
int rear = - 1;
int front = - 1;
 int main()
{
	FILE *fptr;
  fptr=fopen("output.txt","w");
    int choice;
    while (1)
    {
        printf("1.Enter 1 to insert element to queue \n");
        printf("2.Enter 2 to delete element from queue \n");
        printf("3.Enter 3 to display all elements of queue \n");
        printf("4.Enter 4 to quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            deletef();
            break;
            case 3:
            display(fptr);
            break;
            case 4:
            exit(1);
            default:
            printf("Wrong choice \n");
        } 
    } 
    fclose(fptr);
} 
 
void insert()
{
    int element;
    if (rear == CAPACITY - 1)
    printf("Queue is full\n");
    else
    {
        if (front == - 1)
        
        front = 0;
        printf("Enter element which is to be inserted ");
        scanf("%d", &element);
        rear = rear + 1;
        queue_array[rear] = element;
    }
} /* End of insert() */
 
void deletef()
{
    if (front == - 1 || front > rear)
    {
        printf("Queue is empty we cannot delete an element  \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", queue_array[front]);
        front = front + 1;
    }
} /* End of delete() */
 
void display(FILE *fptr)
{    
  
    int i;
    if (front==-1 || front > rear)
        printf("Queue is empty \n");
    else
    {
        printf("Elements of Queue are: \n");
        for (i = front; i <= rear; i++){
		
            printf("%d ", queue_array[i]);
            fprintf(fptr,"%d ",queue_array[i]);
        printf("\n");
    }
}
}

