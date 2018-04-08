#include<stdio.h>

int main(void)
{
	long long int n,k,i,n1;
	scanf("%I64d %I64d",&n,&k);
	if(k>=n) {
		printf("0 0 %I64d",n);
		return 0;
	}
	n1=n/2;
	printf("%I64d\n",n1);
	for(i=n1; ;i--) {
		if(i%(k+1)==0) {
			printf("%I64d %I64d %I64d",i/(k+1),(i/(k+1))*k,n-i);
			return 0;
		}
	}
	
	return 0;
}