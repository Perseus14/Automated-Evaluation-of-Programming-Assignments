#include<stdio.h>
#include<math.h>
int main()
{
	long long n,i,j,k=0,t;
	scanf("%lld",&n);
	t=sqrt(2*n);
	for(i=1;i<=t/2+1;i++)
	{
		for(j=t;j>=t/2+1;j--)
		{
			if(i*(i+1)/2+j*(j+1)/2==n)
			{
				k=1;
			}
			if(k==1)
			break;
		}
		if(k==1)
		break;
	}
	if(k==1)
	printf("YES");
	else
	printf("NO");
}