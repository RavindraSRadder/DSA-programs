#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    int data;
    char name[10];
    char addres[10];
    
    struct node* next;
};

struct node* head = NULL;
struct node* newnode = NULL;
struct node* temp = NULL;

void insertend(int x, char* a,char *b)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->data = x;
        strcpy(newnode->name, a);
        strcpy(newnode->addres,b);
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        newnode->data = x;
        strcpy(newnode->name, a);
         strcpy(newnode->addres,b);
        temp->next = newnode;
    }
}

void display()
{  
    temp = head;
  
    while (temp != NULL)
    {
        printf("%d %s %s\n", temp->data, temp->name,temp->addres);
        temp = temp->next;
    }

}
void deletepos(int y)
{ int i=1;
	temp=head;
	if (i==y)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	else{
	
		struct node*nextnode;
	while(i<y-1)
	{
		temp=temp->next;
		i++;
   }
 

	nextnode=temp->next;
	temp->next=nextnode->next;
	free(nextnode);
}
}
int  search(int x)
{
	int count=1;
	temp=head;
	while(temp->data!=x)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
int main()
{
    int x;
    char a[10];
    char b[10];
    

    FILE* fp1;
    fp1 = fopen("input.txt", "r");
   
    if (fp1 == NULL)
    {
        printf("File could not be opened.\n");
        return 1;
    }
    while (fscanf(fp1, "%d %s %s", &x, a,b) == 3)
    {
        insertend(x, a,b);
    }
    printf("data from file\n");
    display(  );
    
    printf("which element u want to delete\n");
    int y;
    scanf("%d",&y);
  int z=  search(y);
  deletepos(z);
    printf("after deleion\n");
    display( );
    fclose(fp1);

    return 0;
}

