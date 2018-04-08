#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*Verificar si la n es un numero posible de representar
por dos numeros triangular que son k(k+1)/2 (puede ser numeros iguales)
codeforces.com problemset 192A
*/
long n;
long *A;
int funky(int max, int i);
int main(){
	long max,i;
	int res=0,count=0;
	scanf("%d",&n);
	max = (sqrt(2*n));
	A=(long *)malloc(sizeof(long)*(max+1));
	for(i=0; i<=max; i++){
		A[i]=(i*(i+1))/2;
	}
	res=funky(max,1);
	if(res==1){
		printf("YES");
	}else{
		printf("NO");
	}
	free(A);
	return 0;
}

int funky(int max,int i){
    if(i>max)
        return 0;
    if(A[i]+A[max]==n)
        return 1;
    if(A[i]+A[max]<n)
        return funky(max,i+1);
        return funky(max-1,i);
}
