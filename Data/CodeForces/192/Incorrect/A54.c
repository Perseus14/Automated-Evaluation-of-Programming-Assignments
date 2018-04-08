#include <stdio.h>
#include <math.h>

int main ()
{
    int n, i, flag=0,res2, j, res5, res6;
    double res3, res4;
    while(scanf("%d", &n)!=EOF)
    {
        i=1;
        res2= n;
        while(i<res2)
        {
            res2= n-(i*(i+1)/2);
            res3= (-1+sqrt(1+8*res2))/2;
            res5=res3;
            res4= (-1-sqrt(1+8*res2))/2;
            res6= res4;
            if(res3-res5==0 || res4-res6==0)
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

			   					 						  				 				 	