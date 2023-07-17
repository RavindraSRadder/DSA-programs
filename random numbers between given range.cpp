#include<stdio.h>
#include<stdlib.h>
main()
{
	
	
	FILE *fptr;
	int b;
	int a[100];
	int n,i,p,q;
	printf("enter num\n");
     scanf("%d",&n);
	printf("enter range between p & q\n");
	scanf("%d%d",&p,&q);
	fptr=fopen("number.txt","w");
    
	for (i=0;i<n;i++)
	{ 	
	 
	       
	b=(rand()%(p-q+1)+p);
		   
	a[i]=b;
	   
	    
	}
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	fprintf(fptr,"%d\n",a[i]);
    }
    fclose(fptr);
}
