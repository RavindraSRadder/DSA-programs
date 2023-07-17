#include<stdio.h>
#include<conio.h>

#define SIZE 10

void push(int);
void pop();
void display(FILE *fptr);

int stack[SIZE], top = 0;

int main()
{  FILE *fptr;
   fptr=fopen("output.txt","w");
   int value, choice;
   
   while(1){
      printf("\n\n***** MENU *****\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit");
      printf("\nEnter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d",&value);
		 push(value);
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
void push(int value){
   if(top == SIZE-1)
      printf("\nStack is Full!!! Insertion is not possible!!!");
   else{
      top++;
      stack[top] = value;
      printf("\nInsertion success!!!");
   }
}
void pop(){
   if(top == 0)
      printf("\nStack is Empty!!! Deletion is not possible!!!");
   else{
      printf("\nDeleted : %d", stack[top]);
      top--;
   }
}
void display(FILE *fptr){
   if(top == 0)
      printf("\nStack is Empty!!!");
   else{
      int i;
      printf("\nStack elements are:\n");
      for(i=top; i>=0; i--){
	  
	 printf("%d\n",stack[i]);
	 fprintf(fptr,"%d\n",stack[i]);
}
   }
}
