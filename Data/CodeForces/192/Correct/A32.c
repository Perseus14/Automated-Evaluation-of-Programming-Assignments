#include <stdio.h>
#include <math.h>
int main()
{
    long int i=0,j=0,k=0,n=0,t=0,d=0,g=0;
    scanf("%ld",&n);
    d=2*n;
    t = sqrt(d);
    for(i=1;i<=t;i++)
    {
        g=i*i  ;
        k=sqrt( d - g );
        for(j=k;j>=i;j--)
        {
            
            if( g + i + (j*j) + j  == d  )
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}