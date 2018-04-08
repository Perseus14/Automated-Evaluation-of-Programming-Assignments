#include <stdio.h>
#include <stdbool.h>

int main()
{
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long diplomas = n/2/(1+k);
    printf("%lld %lld %lld\n", diplomas, k*diplomas, n-(1+k)*diplomas);
    return 0;
}
