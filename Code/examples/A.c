#include<stdio.h>

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int c = 0;
	int i = 0;
	int j = 0;
	for(i=0;i<n;i++)
		c+=m;
	for(i=0;i<n;i++)
	 for(j=0;j<m;j++)
		c+=1;
	printf("%d",c);
	
}
