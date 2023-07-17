#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
}*head,*tail,*temp,*newnode;

void insertbeg()
{
	newnode=(struct node*)malloc(sizeof(struct node ));
	printf("enter data \n");
	scanf("%d",newnode->data);
	newnode->next=0;
	if(head==0)
	{
		head=temp=tail=newnode;
		tail->next=head;
	}
	else
	{
		newnode->next=tail->next;
		tail->next=newnode;
		
	}
	
}
void insertend()
{
	newnode=(struct node*)malloc(sizeof(struct node ));
	printf("enter data \n");
	scanf("%d",newnode->data);
	newnode->next=0;
	if(tail==0)
	{
		tail=newnode;
		tail->next=newnode;
		
	}
	else{
	
	newnode->next=tail->next;
	tail->next=newnode;
	tail=newnode;
	
}
	
	
}

void insertpos()
{
	newnode=(struct node*)malloc(sizeof(struct node ));
	printf("enter data \n");
	scanf("%d",newnode->data);
	newnode->next=0;
	int pos,count=0;
	printf("enter pos\n");
	scanf("%d",&pos);
	temp=tail->next;
	while(count<pos)
	{
		temp=temp->next;
		count++;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void deletebeg()
{
	temp=tail->next;
	tail->next=temp->next;
	free(temp);
}
void deleteend()
{
	temp=tail->next;
	struct node *prev;
	while(temp->next!=tail->next)
	{
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
	tail=prev;
}
void deletepos()
{
	struct node *nextnode;
	int pos ,count=0;
	printf("enter pos\n");
	scanf("%d",&pos);
	temp=tail->next;
	while(count<pos)
	{
		temp=temp->next;
		count++;
	}
	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
}
void display()
{
	temp=tail->next;
	while(temp->next!=tail->next)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}
main()
{
	insertbeg();
	insertend();
	insertbeg();
	insertpos();
	display();
}
