#include<stdio.h>
#define MAX 100

void main()
{
int shift,i;
char plain [MAX],cipher[MAX],decipher[MAX];
printf("\nenter the plain text");
scanf ("%s",plain);
while(1)
{
printf("\nenter the  shift value for encryption");
scanf("%d",&shift);
if(shift<1 ||shift>25)
printf("\nenter the shift value in the range of 1 to 25");
else
break;

}

for (i=0; plain[i]!='\0';i++)
{
cipher[i]=( ((toupper(plain[i]) -'A')+ shift)%26)+'A';
}
cipher[i] ='\0';
printf("encrypted string is %s\n", cipher);

for (i=0;cipher[i]!='\0';i++)
decipher[i] = ((cipher[i]-'A')+ (26-shift))%26+'A';
decipher[i]='\0';
printf("the decrypted string is %s", decipher);
}
