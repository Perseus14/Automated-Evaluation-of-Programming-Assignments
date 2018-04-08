#include <stdio.h>
#include <math.h>


int main()
{
    int n,x,z;

    scanf("%d",&n);

    x=sqrt(n*2);
    x=x*(x+1);
    z=n*2-x;
    z=sqrt(z);
    z=z*(z+1);

    if((z/2+x/2)==n)
        printf("YES\n");
    else
        printf("NO\n");



    return 0;
}
