#include<stdio.h>
#include<math.h>

int main()
{
    double a,b,c,d;
    scanf("%lf",&a);
    b = 0.5 * sqrt(8*a + 1) - .5;
    c = (b*(b+1))/2;
    if(c == a) printf("YES\n");
    else printf("NO\n");

    return 0;
}

 	 			      	  	     		 	