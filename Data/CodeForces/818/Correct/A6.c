#include<stdio.h>
int main()
{
   long long int a,b,c,d,e;
    scanf("%I64d %I64d",&a,&b);
    d=(a/2)/(b+1);
    c=d*b;
    printf("%I64d %I64d %I64d",d,c,a-c-d);
    return 0;
}