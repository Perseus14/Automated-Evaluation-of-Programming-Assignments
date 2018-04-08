#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,j,k,t;
	scanf("%d",&n);
	t=sqrt(2*n);
	for(i=1;i<t;i++)
	{
		for(j=1;j<t;j++)
		{
			if(i*(i+1)/2+j*(j+1)/2==n)
			{
				k=1;
				break;
			}
		}
		if(k==1)
		break;
	}
	if(k==1)
	printf("YES");
	else
	printf("NO");
}