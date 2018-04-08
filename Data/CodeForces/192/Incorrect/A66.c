#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k=0,t;
	scanf("%d",&n);
	t=sqrt(2*n)+1;
	for(i=1;i<=t;i++)
	{
		for(j=t;j>t-i;j--)
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