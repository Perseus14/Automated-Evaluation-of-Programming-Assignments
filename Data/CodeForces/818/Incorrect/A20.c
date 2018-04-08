#include <stdio.h>
int main()
{
	long int n;
	int k,x;
	scanf("%d %d",&n,&k);
	long int m=n/2;
	x=m/(k+1);
	printf("%d %d %d",x,k*x,n-m);
	return 0;

}
