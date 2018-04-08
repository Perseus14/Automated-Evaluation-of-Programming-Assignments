#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n =0  ;
    int i =0 ,j=0 ;
    scanf("%d",&n);

        for (i = 1; i <=sqrt(n*2); i++) {

              j = sqrt(2*n-i*(i+1));
                if (j &&(i * (i + 1) + j * (j + 1))== 2 * n) {
                    printf("YES");
                    return 0 ;
                }



        }

        printf("NO");

    return 0;
}
