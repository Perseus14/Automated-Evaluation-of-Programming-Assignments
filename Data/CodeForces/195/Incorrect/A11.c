#include<stdio.h>
int main()
{
	int k,a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	k=(a*c)/b;
	if(k==1)
	printf("%d",k);
	else
	printf("%d",k-1);
	return 0;
}
