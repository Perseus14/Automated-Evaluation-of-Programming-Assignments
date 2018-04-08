#include <stdio.h>
#include <math.h>
int main()
{
    long long int i,j,k,n,t;
    scanf("%lld",&n);
    t = sqrt(2*n);
    for(i=1;i<=t;i++)
    {
        for(j=t;j>i;j--)
        {
            if( (i*i) +(j*j) == 2*t -i -j )
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}