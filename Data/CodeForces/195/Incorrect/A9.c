#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,t;
    scanf ("%d",&a);
    scanf ("%d",&b);
    scanf ("%d",&c);
    t= c*a/(a-b+c);
    printf("%d",t);

    return 0;
}