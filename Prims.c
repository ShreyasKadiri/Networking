#include<stdio.h>
#define INFINITY 999
//int prim (int,int,int);
void main()
{
int a [10][10],n,i,j,m, source;
printf("enter the number of vertices");
scanf("%d",&n);
printf("\n enter the cost matrix %d for no edge\n",INFINITY);
for(i=1;i<=n;i++)
for(j=1; j<=n;j++)
scanf("%d",&a[i][j]);
printf("\n enter the source");
scanf ("%d", & source);
m = prim(a, source,n);
printf("\n\n cost = %d\n",m);

}


int prim( int cost [10][10], int source, int n)
{
int i,j,sum=0,visited[10], cmp[10],vertex[10];
int min,u,v;
for(i=1;i<=n;i++)
{
vertex[i]= source;
visited[i]=0;
cmp[i] =cost[source][i];
}


visited [source] =1;
for(i=1;i<=n-1;i++)
{
min=INFINITY;
for(j=1;j<=n;j++)
if(! visited [j] && cmp[j]<min)
{
min =cmp[j];
u=j;
}

visited[u]=1;
sum= sum+cmp[u];
printf("\n %d -> %d sum = %d", vertex[u],u,sum);
for(v=1; v<=n;v++)
if(!visited[v] && cost[u][v] < cmp[v])
{
cmp[v] = cost [u][v];
vertex[v]= u;
}
}
return sum;
}

