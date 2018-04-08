#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
long long unsigned a,b,c,low=0,high=1e12+100,mid;
bool ok(long long mid)
{
    if (b*mid+b*c>=a*(c)) return 1;
    else return 0;
}
int main()
{
    scanf("%llu %llu %llu",&a,&b,&c);
    while (low < high)
       {
        mid=low+(high-low)/2;
        if (ok(mid))
         high = mid;
        else
         low = mid+1;
       }
    printf("%llu",high);
    return 0;
}

