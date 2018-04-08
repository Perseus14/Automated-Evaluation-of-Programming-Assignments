#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
    int n, flag=0;
    clock_t s,e;
    s=clock();
    scanf("%d", &n);
    int a=1, b=1, i, j;
    for(i=1; i<n; i+=a)
    {
        a++;
        for(j=1; j<n; j+=b)
        {
            b++;
            if(i+j==n)
            {
                printf("YES\n");
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
        printf("NO\n");
    e=clock();
    //printf("Time=%f\n", (float)(e-s)/CLOCKS_PER_SEC);
    return 0;
}