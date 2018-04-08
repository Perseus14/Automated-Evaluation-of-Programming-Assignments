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
        b=1;
        for(j=1; j<=n-i; j+=b)
        {
            b++;
            if(i+j==n)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    e=clock();
    //printf("Time=%f\n", (float)(e-s)/CLOCKS_PER_SEC);
    return 0;
}