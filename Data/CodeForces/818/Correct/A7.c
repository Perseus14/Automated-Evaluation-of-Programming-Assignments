#include <stdio.h>

typedef long long int INT64;

int main(void) {
    INT64 n = 0, k = 0;
    INT64 win = 0;
    scanf("%lld %lld", &n, &k);
    
    win = n / (2 * (k + 1));
    
    printf("%lld %lld %lld\n", win, k * win, n - ((k + 1) * win));
    
    return 0;
}