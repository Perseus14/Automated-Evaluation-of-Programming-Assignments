#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int a , b ,c,high=1000,low=0,mid;
bool ok(int m){
    if (b*mid+b*c>=a*(c)) return 1;
    else return 0;
}
int main()
{
    scanf("%i%i%i",&a,&b,&c);
    while(low < high){
        mid=low+(high-low+1)/2;
        if(!ok(mid)) low=mid;
        else    high=mid-1;
        }
    printf("%i",high+1);
    return 0;
}

