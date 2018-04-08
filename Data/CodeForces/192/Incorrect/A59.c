#include <stdio.h>

int main ()
{
    int n, i, flag=0, res, res2, j, res3;
    while(scanf("%d", &n)!=EOF)
    {
        i=1;
        while(i<=10000)
        {
            res= (i*(i+1)/2);
            res2= n-res;
            for(j=1; j<=10000; j++)
            {
                res3= (j*(j+1))/2;
                if(res3==res2)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
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

	 				 		 	 			 	   	 		  	