#include <stdio.h>
#include <math.h>
int main (void)
{
    int i;
    int flag=0;
    int n;
    scanf("%d",&n);
    int j;
    for(i=1;(i*(i+1))/2<n;i++)
        for(j=1;j<=i;j++)
        {
            if((i*(i+1)+j*(j+1))/2==n)
            {
                flag=1;
                break;
            }
        }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
    
}