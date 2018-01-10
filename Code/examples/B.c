#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int c = 0;
	int i = 0;
	for(i=0;i<n;i++)
		c+=m;
	printf("%d",c);
	
}
