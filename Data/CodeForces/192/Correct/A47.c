#include<stdio.h>
int f(int x)
{
    int n=x*(x+1)/2;
    return n;
}
int main()
{
    int m,i,j=0,k;
    long n;
    while(~scanf("%ld",&n))
    {
        m=0;
        for(i=1;f(i)+f(j)<=n;i++)
        {
            for(j=i;f(i)+f(j)<=n;j++)
        {
            if(f(i)+f(j)==n)
            {
                printf("YES\n");
               return 0;
            }

        }
j=0;
        }
       printf("NO\n");
    }
    return 0;
}

		  			 				  	 	  	   	  	   	