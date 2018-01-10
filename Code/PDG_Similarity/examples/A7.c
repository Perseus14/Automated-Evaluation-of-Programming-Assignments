#include <stdio.h>
#include <stdlib.h>

int main (void) {

    long m , n , a ;
    scanf("%ld %ld %ld",&n,&m,&a);
    double number = 0;

    if (m==0 && n ==0){
      printf("0");
      return 0;
    }

    if(m%a == 0)
    {
        number = m/a;
    }
    else {
        number = m / a +1;
    }

    if(n%a == 0)
    {
        number *= n/a;
    }
    else {
        number *=   (n / a +1);
    }

    printf("%.0lf" , number);

}
