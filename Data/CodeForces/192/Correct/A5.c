#include <stdio.h>
#include <math.h>
int main()
{
	int a,n,i,j;
	scanf("%d",&n);
	n*=2;
	a=sqrt(n);
	if (a*(a+1)>n) a--;
	int sum[a+1];
	n/=2;
	for (i=1; i<=a; i++)
		sum[i]=(i*(i+1))/2;
	for (i=1; i<=a; i++)
		for (j=i; j<=a || sum[i]+sum[j]<=n ; j++)
			if (sum[i]+sum[j]==n)
			{
				printf("YES\n");
				return 0;
			}
	printf("NO\n");
	return 0;
}