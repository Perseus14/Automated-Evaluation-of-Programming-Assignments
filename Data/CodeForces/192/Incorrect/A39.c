#include<stdio.h>
int main()
{
    int n,i,j,a=0,b=0,sum;
    scanf("%d", &n);
        for(i=1; i<n; i++)
    {
        for(j=1; j<n; j++)
        {
            a=(j*j+1)/2;
            b=(i*i+1)/2;
            sum=a+b;
            if(sum==n)
            {
                printf("YES\n");
                return 0;
            }
            else
            {

            }

        }
    }
    printf("NO\n");
    return 0;
}
