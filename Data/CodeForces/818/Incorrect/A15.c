#include <stdio.h>
#include <math.h>

int main(){

unsigned long int n,k;
unsigned long int dp,cer,wi;



scanf("%ld %ld",&n,&k);

wi= n/2;
dp = wi/(k+1);
cer = k*dp;

printf("%ld %ld %ld\n",dp,cer,n-dp-cer);

return 0;
}


