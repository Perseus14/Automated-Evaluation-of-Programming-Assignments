#include <stdio.h>
#include <stdint.h>

int main(){

int64_t n, k;


scanf("%I64d %I64d",&n,&k);
      //ganadores como maximo la mitad de los alumnos
int64_t dp = n/(2*k+2);  //reciben diploma un maximo de  los alumnos  ganadores entre k+
int64_t cer = k*dp;   //los alumnos con certificados son k veces  mas valor

printf("%I64d %I64d %I64d\n",dp,cer,n-cer-dp);

return 0;
}