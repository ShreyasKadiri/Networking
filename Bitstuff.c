#include<stdio.h>
#include<string.h>
void main()
{
char in[100],out[100],des[100],flag[9]="01111110";
int inlen, i, j, count=0,k,outlen,len;


printf("Enter the data to be bit stuffed:\n");
gets(in);
inlen=strlen(in);                     
strcpy(out,flag);                                          
	
for(i=0,j=8;i<inlen;i++)
{
if(in[i]=='1')
count++;
else
count = 0;
out[j++]=in[i];
if(count == 5)
{
out[j++] = '0';
count = 0;
}
}
	
out[j] = '\0';
strcat( out, flag);
printf("The bit stuffed frame is:\n %s",out);
outlen=strlen(out);
len=(outlen-8);
count=0;
	
for(k=0,j=8;j<(outlen-8);j++)
{
if(out[j]=='1')
count++;
else
count=0;
des[k++]=out[j];
if(count == 5)
{
des[k]=out[j++];
count=0;
}
}
	
des[k]='\0';
printf("\nThe destuffed frame is: %s \n",des);
}

