#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long digit (long long n)
{
    long long     sum= 0 ;
    while (n!= 0)
    {
        sum+= n%10;
        n /= 10;
    }
    return sum ;
}

int main()
{
    int found = 0  ;
    long long  n  , answer= -1 , i=1;

    scanf("%I64d",&n);
    if (sqrt(n)-1000 >1)
        i =sqrt(n)-1000 ;
    for (i ; i<= sqrt(n) ; i++)
    {
        if (i*i + digit(i)*i==n)
        {
            answer = i ;
            found = 1 ;
        }

    }
    if (!found)
        answer = -1;
    printf("%I64d",answer);



    return 0;
}
