#include<stdio.h>

int main()
{
    long long int n, k, c, d;
    scanf("%lld%lld", &n, &k);
    if((k+1)>n/2)
        printf("0 0 %lld", n);
    else
    {
        d = n/(2*(k+1));
        c = k*d;
        printf("%lld %lld %lld", d, c, n-(c+d));
    }
    return 0;
}
