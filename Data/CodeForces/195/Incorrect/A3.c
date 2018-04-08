#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int a , b ,c,r,m;
bool ok(int m){
    if (b*m+b*c>=a*c) return 1;
    else return 0;
}
int main()
{
    // a is l
    // b is f
    scanf("%i%i%i",&a,&b,&c);
    while(a>b){
        m=(b+a)/2;
        if(ok(m)) b=m;
        else    a=m-1;
        }
    printf("%i",b);
    return 0;
}

