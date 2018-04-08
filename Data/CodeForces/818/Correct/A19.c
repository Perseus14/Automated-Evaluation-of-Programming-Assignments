#include<stdio.h>
int main()
{
    long long n,k,t,u;
    while(scanf("%I64d%I64d",&n,&k)==2)
    {
        t=(n/2)/(k+1);
        u=k*t;
        printf("%I64d %I64d %I64d\n",t,u,n-t-u);
    }
}
