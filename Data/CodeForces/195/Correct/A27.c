#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a , b , c , t;
    scanf("%d%d%d",&a,&b,&c);
    t = ceil((double)(((double)(a * c) / b) - c));
    printf("%d",t);
    return 0;
}
