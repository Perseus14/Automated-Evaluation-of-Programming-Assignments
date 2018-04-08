#include<stdio.h>
int main()
{
    long long int n,k,c;
    scanf("%lld %lld",&n,&k);
    c=n/2;
    c=c/(k+1);
    printf("%lld %lld %lld",c,c*k,n-(c+c*k));
    return 0;
}
