#include<stdio.h>

#define capacity 6

int queue[capacity];
int front = -1, rear = -1;

// Here we check if the Circular queue is full or not
int checkFull ()
{
  if ((front == rear + 1) || (front == 0 && rear == capacity - 1))
    {
      return 1;
    }
  return 0;
}

// Here we check if the Circular queue is empty or not
int checkEmpty ()
{
  if (front == -1)
    {
      return 1;
    }
  return 0;
}

// Addtion in the Circular Queue
void enqueue (int value)
{
  if (checkFull ())
    printf ("Overflow condition\n");

  else
    {
      if (front == -1)
	front = 0;

      rear = (rear + 1) % capacity;
      queue[rear] = value;
      printf ("%d was enqueued to circular queue\n", value);
    }
}

// Removal from the Circular Queue
int dequeue ()
{
  int variable;
  if (checkEmpty ())
    {
      printf ("Underflow condition\n");
      return -1;
    }
  else
    {
      variable = queue[front];
      if (front == rear)
	{
	  front = rear = -1;
	}
      else
	{
	  front = (front + 1) % capacity;
	}
      printf ("%d was dequeued from circular queue\n", variable);
      return 1;
    }
}

// Display the queue
void display (FILE *fptr)
{
	FILE *fptr;
	fptr=foepen("output.txt","w");
  int i;
  if (checkEmpty ())
    printf ("Nothing to dequeue\n");
  else
    {
      printf ("\nThe queue looks like: \n");
      for (i = front; i != rear; i = (i + 1) % capacity)
	{
	  printf ("%d ", queue[i]);
	}
      printf ("%d \n\n", queue[i]);

    }
    fclose(fptr);
}

int main ()
{
  int choice,item;
do
{
printf("1.Insertn");
printf("2.Deleten");
printf("3.Displayn");
printf("4.Quitn");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1 :
printf("Input the element for insertion in queue : ");
scanf("%d", &item);
enqueue(item);
break;
case 2 :
dequeue();
break;
case 3:
display();
break;
case 4:
break;
default:
printf("Wrong choicen");
}
}while(choice!=4);
return 0;
  return 0;
}
