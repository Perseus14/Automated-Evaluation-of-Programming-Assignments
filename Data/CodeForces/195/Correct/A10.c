#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a = 0 , b=0 , c=0 ,  x =0  , first = 0 , last = 0 , mid = 0 , answer=0 ;
    scanf("%d %d %d", &a  , &b , &c);
    answer = ceil( (float) (a*c)/b)-c;

    printf("%d", answer);
    return 0;
}
