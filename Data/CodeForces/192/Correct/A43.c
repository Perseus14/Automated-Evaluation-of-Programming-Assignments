#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;(i*(i+1))<2*n;i++)
	{
		for(j=i;(j*(j+1))<2*n;j++)
		{
			if(i*(i+1)+j*(j+1)==2*n)
			{
			printf("YES");
			return 0;}
			if(j*(j+1)+i*(i+1)>2*n)
			break;
			
		}
	}
	printf("NO");
	return 0;
}
