#include<stdio.h>
#include<ctype.h>
#include<string.h>
char m[50],g[50],r[50],q[50],temp[50];
void caltrans(int);
void crc(int);
void calrem();
void shiftl();
void main()
{
int n,i=0;
char ch;
printf("enter the frame bits:");
while((ch=getc(stdin))!='\n')
m[i++]=ch;
n=i;
for(i=0;i<16;i++)
m[n++]='0';
m[n]='\0';
printf("\n message after appending 16 zeros: %s:",m);
for(i=0;i<=16;i++)
g[i]='0';
g[0]=g[4]=g[11]=g[16]='1';
g[17]='\0';
printf("\n generator:%s",g);
crc(n);
printf("\n\n Quotient :%s",q);
caltrans(n);
printf("\n\n transmitted frame:%s",m);
}

void crc(int n)
{
int i,j;
for(i=0;i<n;i++)
temp[i]= m[i];
for(i=0;i<16;i++)
r[i]= m[i];
printf("\n intermediate remainder");
printf("\n\n *****************");
for(i=0;i<n-16;i++)
{
if(r[0]=='1')
{
q[i]='1';
calrem();
}
else
{
q[i]='0';
shiftl();
}
r[16]=m[17+i];
r[17]='\0';
printf("\n remainder %d: %s",i+1,r);
for(j=0;j<=17;j++)
temp[j]=r[j];
}
q[n-16]='\0';
}
void calrem()
{

int i,j;
for(i=1;i<=16;i++)
r[i-1] = ((int) temp[i]-48)^ ((int) g[i]-48)+48;
}

void shiftl()
{
int i;
for (i=1;i<=16;i++)
r[i-1] =r[i];
}

void caltrans(int n)
{
int i,k=0;
for(i=n-16;i<n;i++)
m[i]= ((int) m[i]-48)^((int) r[k++]-48)+48;
m[i]='\0';
}
