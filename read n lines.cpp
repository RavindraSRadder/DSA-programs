#include<stdio.h>

int main()
{
FILE *fptr;
fptr=fopen("file.txt","r");
char c;
while(c!=EOF)
{
 
 c=fgetc(fptr);
 printf("%c", c);
 }
  fclose(fptr);
  
}
