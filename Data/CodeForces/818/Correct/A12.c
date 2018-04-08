#include<stdio.h>


 
 int main()
 {
     
     long long int  a=9,k=10,d;
    
     scanf("%lld %lld",&a,&k);
     
    
     
         d=(a/2)/(k+1);
     
     
     printf("%lld %lld %lld",d,d*k,a-(d+d*k));
     
     return 0;
 }


