#include<stdio.h>
int main()
{
    int n,i,j,s,h;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        h=i*i+i;
        for(j=i;(j*j+j)<2*n;j++)
        {
            s=h+j*j+j;
            if(s>2*n)
                break;
            else if(s<2*n)
                continue;
            else
            {
                printf("YES\n");
                return 0;
            }

        }
    }
    printf("NO\n");
    return 0;
}
