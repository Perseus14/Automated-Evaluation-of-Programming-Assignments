#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, n;
    double d;
    scanf("%d %d %d", &a, &b, &c);
    d = ((a*c)/(1.0*b));
    n = ceil(d);
    printf("%d", n-c);

    return 0;
}

 	 				  	 			 		  				 		