#include <stdio.h>
#include <math.h>
int main()
{
    int i, set[44751], n, k;
    scanf("%d", &n);
    int limit=sqrt(2*n);
    //printf("%d\n", limit);
    for(i=0; i<limit; i++)
        set[i]=(i*(i+1))/2;
    
    for(i=1; i<limit; i++)
    {
        if(set[i]>n)
            break;
        int j=n-set[i];
        //printf("j=%d\n", j);
        for(k=1; k<limit; k++)
        {
            //printf("set[k]=%d\n", set[k]);
            if(j==set[k])
            {
                printf("YES\n");
                return 0;
            }
            if(j<set[k])
                break;
        }
    }
    printf("NO\n");
    return 0;
}