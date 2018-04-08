#include <stdio.h>

int main () {

    int num, i, j, square=0;

    scanf("%d", &num);

    for (i=1;i<=num/4; i++) {
        for (j=1; j<=num/4; j++) {
            square= (((i*(i+1))/2) + (((j*(j+1))/2)));
                if (square==num) {
                    printf ("YES");
                    break;
                }
                else if (i==num) {
                    printf ("NO");
                    break;
                }
            }
            if (square==num) break;
        }
    return 0;
    }




 	  	   	 				 				 	 	 							