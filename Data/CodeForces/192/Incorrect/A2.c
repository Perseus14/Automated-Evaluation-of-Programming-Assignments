#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%i",&n);
    if(n<1 || n>1000000000){
        printf("NO");
    }
    int i = 1;
    int j = 1;
    for (i = 1; i < n/2; i++){
        for (j = i; j < n/2; j++){
            if(((i*(i+1)) + (j*(j+1)))/2 == n){
                printf("YES");
                return 0;
            }
        }
    }
	printf("NO");
    return 0;
}

		  	 	  	 							 		    	 	 		