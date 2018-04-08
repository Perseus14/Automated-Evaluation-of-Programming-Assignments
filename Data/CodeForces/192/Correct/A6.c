#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    long n=0; 
    scanf("%ld", &n);
    long upperBound = sqrt(2 * n);
    long *funky = (long *)malloc(sizeof(long)*(upperBound+1));
    for(long k = 0; k <= upperBound; k++){funky[k] = k * (k + 1) / 2;}

    int band=0;
    int bajo=1, alto=upperBound;
    
    while(bajo <= alto){
        if(funky[bajo] + funky[alto] == n){
            band = 1; break;
        }
        else if(funky[bajo] + funky[alto] < n){
            ++bajo;
        }
        else if(funky[bajo] + funky[alto] > n){
            --alto;
        }
    }

    if(band){
        printf("YES");
    } else{
        printf("NO");
    }
    return 0;
}