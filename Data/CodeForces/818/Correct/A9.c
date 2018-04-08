#include<stdio.h>
int main(viod)
{
    long long int n,k,i,w,c,d;
    while(scanf("%I64d %I64d",&n,&k)==2)
    {
        d=n/(2*(k+1));
        c=k*d;

    printf("%I64d %I64d %I64d\n",d,c,n-d-c);
    }
    return 0;
}
