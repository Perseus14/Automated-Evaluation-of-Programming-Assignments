#include <stdio.h>
#include <math.h>
int main () {

    int num, i, j, square=0,c;

    scanf("%d", &num);
    c=sqrt(num);
    for (i=1;i<=c; i++) {
        for (j=1; j<=c; j++) {
            square= (((i*(i+1))/2) + (((j*(j+1))/2)));
                if (square==num) {
                    printf ("YES");
                    break;
                }
                else if (i==c) {
                    printf ("NO");
                    break;
                }
            }
            if (square==num) break;
        }
    return 0;
    }

 			  			 	  			   	 		  	  		