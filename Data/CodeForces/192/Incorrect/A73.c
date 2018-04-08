#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n =0  ;
    int i =1,j=0 ;
    scanf("%d",&n);
        if (sqrt(n*2)-100 >1)
        i =sqrt(n*2)-100 ;
       




        for (i; i <=sqrt(n*2); i++) {
            for (j=1 ; j<=i ;j++) {

                if ((i * (i + 1) + j * (j + 1))== 2 * n) {
                    printf("YES");
                    return 0 ;
                }

            }
            }


        printf("NO");

    return 0;
}
