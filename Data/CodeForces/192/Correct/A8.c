#include<stdio.h>
int main()
{
	int n,k,l,x,y;
	scanf("%d",&n);
	x=1;
	for(k=1;x<n;k++,x=x+k)
	{
		y=1;
		for(l=1;y<=n-x;l++,y=y+l)
		{

			if(x+y==n)
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}
