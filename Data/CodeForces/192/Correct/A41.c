#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int i,k=0,l,j,ans=0;
    for(i=1;i<=n/2;i=(k*(k+1))/2)
    {
        k++;
        l=k-1;
        for(j=i;j<=n-i;j=(l*(l+1))/2)
        {
            l++;
            ans=j+i;
            if(ans==n) break;
        }
        if (ans==n) break;
    }
    if(ans==n) printf("YES");
    else printf("NO");
    return 0;
}
