#include<stdio.h>
#include<stdlib.h>



struct node {
	
int data;
struct node *next;
}*head,*temp;


void create(int p,int q)
{
struct node *newnode;
head=0;

 newnode=(struct node*)malloc(sizeof(struct node));

 newnode->data=(rand() % (q - p + 1)) + p;
 

 newnode->next=0;
 if(head==NULL)
 {
 head=temp=newnode;
 }
 else
 {
     temp=head;
     while(temp->next!=NULL)
    {
    temp=temp->next;

   temp->next=newnode;
    }
 }
 void insertend(int p, int q)  
 {
 
 
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	
 newnode->data=(rand() % (q- p + 1)) + p;
	
	newnode->next=0;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}


 main()
{
	FILE *fptr;
	fptr=fopen("output.txt","w");
	int n,p,q;
	printf("enter num\n");
	scanf("%d",&n);
	printf("range\n");
	scanf("%d%d",&p,&q);
	int i;
	create(p,q);
	for(i=0;i<n;i++)
	{
	insertend(p,q);	
	}
	fclose(fptr);
return 0;
}

