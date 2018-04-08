#include<stdio.h>
int main()
{
    unsigned long long int n,k,d,c;
    scanf("%d %d",&n,&k);
    d=n/(2*(k+1));
    c=k*d;
    printf("%d %d %d",d,c,(n-d-c));
}
