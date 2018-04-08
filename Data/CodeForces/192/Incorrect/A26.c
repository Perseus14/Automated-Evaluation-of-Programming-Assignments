#include<stdio.h>

int main()
{
    int k, j, lala;
    long long int p[141420], i, n;

    scanf("%I64d", &n);

    lala = (-1+sqrt(1+8*n))/2;

    for(i = 1;i <= lala; i++)
    {
        p[i-1] = i*(i+1)/2;
    }
    for(k = 0; k < lala; k++)
    {
        for(j = lala; j >= 0; j--)
        {
            if((p[k]+p[j]) == n)
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;

}
