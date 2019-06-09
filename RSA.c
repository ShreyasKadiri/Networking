#include<stdio.h>
#include<math.h>
int gcd(int a, int h)
{
int temp;
while(1)
{
temp = a%h;
if(temp==0)
return h;
a = h;
h = temp;
}
}

void  main()
{
double p = 3;
double q = 7;
double d;
double k=2;
double msg=12;
double n=p*q;
double count;
double c;
double m;
double totient = (p-1)*(q-1);
double e=2;

while(e<totient)
{
count = gcd(e,totient);
if(count==1)
break;
else
e++;
}

//choosing d such that it satisfies d*e = 1 + k * totient
d = (1 + (k*totient))/e;
c = pow(msg,e);
m = pow(c,d);
c=fmod(c,n);
m=fmod(m,n);

printf("Message data = %lf",msg);
printf("\np = %lf",p);
printf("\nq = %lf",q);
printf("\nn = pq = %lf",n);
printf("\ntotient = %lf",totient);
printf("\ne = %lf",e);
printf("\nd = %lf",d);
printf("\nEncrypted data = %lf",c);
printf("\nOriginal Message Sent = %lf",m);
}

