#include <stdio.h>
#include <stdlib.h>

int main()
{
    // TODO Auto-generated method stub
    int num;
    scanf("%d",&num);
    int k1 = 0, ans = 0;
    int i,j;
    for (i = 1 ; i <= num / 2 ; i = (k1 * (k1 + 1)) / 2)
    {
        int k2 = k1;
        k1++;
        for ( j = i; j <= num - i; j = (k2 * (k2 + 1)) / 2)
        {
            k2++;
            ans = j + i;
            if (ans == num)
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");


    return 0;
}
