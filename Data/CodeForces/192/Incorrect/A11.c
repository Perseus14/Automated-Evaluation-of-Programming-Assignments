#include<stdio.h>
#include<math.h>

int shotti(double t)
{
    t = 1 + 4*t;
    double c = sqrt(t);
    if((double)((int)c) == c)
    {
        return 1;
    }
    return 0;

}

int main()
{
    int n, i, j, t;
    scanf("%d", &n);
    if(n == 1)
    {
        printf("YES");
        return 0;
    }

    n = n*2;
    j = sqrt(n);
    for(i = 1; i <= j; i++)
    {
        t = n - i*i - i;
        if(shotti((double)t))
        {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
