#include <stdio.h>

int main()
{
    int i, set[44751], n, k;
    for(i=0; i<44750; i++)
        set[i]=(i*(i+1))/2;
    scanf("%d", &n);
    
    for(i=0; i<44750; i++)
    {
        if(set[i]>n)
            break;
        int j=n-set[i];
        //printf("j=%d\n", j);
        for(k=0; k<44750; k++)
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