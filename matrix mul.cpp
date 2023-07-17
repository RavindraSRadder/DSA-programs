#include<stdio.h>

main()
{
	int a[20][20],b[20][20],mul[20][20],i,j,k,r1,c1,r2,c2;
	printf("enter number of rows 1\n");
	scanf("%d",&r1);
	printf("enter number of column 1\n");
	scanf("%d",&c1);
	printf("enter number of rows 2\n");
	scanf("%d",&r2);
	printf("enter number of column 2\n");
	scanf("%d",&c2);

	
	if(c1!=r2)
	{
	 printf("\n\nmultiplication is not possible\n");	
	}	
	else
	{
	
	
	printf("enter data of first matrix\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
		 scanf("%d",&a[i][j]);	
		}
	}
		
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
		 printf("%d\t",a[i][j]);	
		}
		printf("\n");
	}
	printf("\n");

	printf("enter elements of 2nd matrix\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
		 scanf("%d",&b[i][j]);	
		}
	}
		
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
		 printf("%d\t",b[i][j]);	
		}
		printf("\n");
	}
	printf("\n\n");
	
	printf("multipication of matrix is \n");
	
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			mul[i][j]=0;
			for(k=0;k<c1;k++)
			{
				mul[i][j]=mul[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("%d\t",mul[i][j]);
		}
		printf("\n");
	}
}
}
