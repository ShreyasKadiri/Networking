#include<stdio.h>
#include<string.h>
#define MAX 100
void main ()
{
char plain[MAX], cipher[MAX], key[MAX],ch;
int i,j,m,n,flag,l,k=0;
printf("\nenter the plain text");
gets(plain);

while(1)
{
printf("\nenter the key");
scanf ("%s", key);
j=strlen(key);
for(i=0; i<j; i++)
{
if(!isalpha(key[i]))
{
flag =0;
break;
}
else
flag =1;
}
for (i=0;i<j;i++)
{
for(m=i;m<j;m++)
{
if(key[i]==key[m+1])
flag=0;
}
}


if(flag==0)
continue;
else
break;
}
printf(" entered key is having all characters being alphabets and no repeatation of letters\n");
n= strlen(plain);
for (ch='A';ch<='Z';ch++)
{
for(i=0;i<j;i++)
if(toupper(key[i])==ch)
for(l=i;l<n;l=l+j)
cipher[k++] = plain[l];
}
cipher[k]='\0';

printf("encrypted message is %s", cipher);
k=0;
n=strlen (cipher);
for (ch='A'; ch<='Z';ch++)
{
for(i=0;i<j; i++)
if(toupper(key[i])==ch)
for(l=i;l<n;l=l+j)
plain[l]= cipher[k++];
}
printf("\ndecrypyted message is %s", plain);
}





