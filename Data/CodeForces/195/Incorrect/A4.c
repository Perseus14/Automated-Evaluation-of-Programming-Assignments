#include<stdio.h>
int main()
{
int i,n,a,b,j,c,count=1,m;
scanf("%d%d%d",&a,&b,&c);
for(i=1;i<=a;i++)
{
    n=i;
    m=i*b;
    for(j=1;j<=c+m;j++)
    {
        if((m+b*j)<(a*j))
        {
            count=-1;
        }
    }
    if(count>0)
    {
    printf("%d",i);
    break;
    }
}
}
