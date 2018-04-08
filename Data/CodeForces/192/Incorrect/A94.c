#include <stdio.h>
#include <math.h>
int a [40000];
int main (void)
{
    int i;
    int flag=0;
    int n;
    scanf("%d",&n);
    if(n%2==1){
        printf("NO");
        return 0;
    }
    double k = pow(n,0.5);
    int d = k+10;
    int j;
    for(i=1;i<d;i++)
        a[i]=i*(i+1)/2;
    for(i=1;i<d;i++)
        for(j=1;j<d;j++)
        {
            if(a[i]+a[j]==n)
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