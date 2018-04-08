#include<stdio.h>
#include<math.h>
int main()
{
    long n,i,k1;
    double k;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        k=(sqrt(1+4*(2*n-i*(i+1)))-1)/2;
        k1=k;
        k=k-k1;
        if(k==0)
        {
            printf("YES");
            break;
        }
    }
    if(k!=0)
        printf("NO");
    return 0;
}
