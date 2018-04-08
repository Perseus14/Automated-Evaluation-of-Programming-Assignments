#include <stdio.h>
#include <math.h>

int main ()
{
    int n, i, flag=0,res2, res5;
    double res3;
    while(scanf("%d", &n)!=EOF)
    {
        i=1;
        res2= n;
        while(i<res2)
        {
            res2= n-(i*(i+1)/2);
            if(res2<0)
                break;
            res3= (-1+sqrt(1+8*res2))/2;
            res5=res3;
            if(res5*(res5+1)==2*res2)
            {
                flag=1;
                break;
            }
            i++;
        }
        if(flag==0)
            printf("NO\n");
        else
            printf("YES\n");
        flag=0;
    }
    return 0;
}

 	 		   			 			  	  				 	   	