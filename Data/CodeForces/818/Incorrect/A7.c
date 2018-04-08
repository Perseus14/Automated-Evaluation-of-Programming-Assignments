#include <stdio.h>

int main(){

unsigned long int n=0,k=0;
unsigned long int dp=0,cer=0,wi=0;


scanf("%ld %ld",&n,&k);
      //ganadores como maximo la mitad de los alumnos
dp = n/(2*k+2);  //reciben diploma un maximo de  los alumnos  ganadores entre k+1
cer = k*dp;   //los alumnos con certificados son k veces  mas valor

printf("%ld %ld %ld\n",dp,cer,n-cer-dp);

return 0;
}