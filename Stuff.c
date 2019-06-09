#include<stdio.h>
#include<string.h>
void main()
{
char in[100]={'\0'},out[100]={'\0'},f1[8]="DLE STX";
char f2[8]="DLE ETX", des[100]={'\0'};
int i , j, inlen, outlen, k ;
	
printf("enter the data to be character stuffed: \n");
gets(in);
	
inlen = strlen(in);
strcpy(out,f1);
	
for(i=0,j=7;i<inlen;i++)
{
if((in[i]=='D' && in[i+1]=='L' && in[i+2]=='E')||(in[i]=='d' && in[i+1]=='l' && in[i+2]=='e'))
{
strcat(out,"DLEDLE");
i=i+3;
j=j+6;
}
out[j++]=in[i];
}

out[j]='\0';
strcat(out,f2);
printf("the char stuffed data is: %s \n", out);
outlen=strlen(out);
	
for(k=0,j=7;j<(outlen-7);j++)
{
if(out[j]=='D' && out[j+1]=='L' && out[j+2]=='E')
{
des[k]=out[j+3];
j=j+3;
}
des[k++]=out[j];
}
des[k]='\0';
printf ("The destuffed frame is: %s \n", des);
}

