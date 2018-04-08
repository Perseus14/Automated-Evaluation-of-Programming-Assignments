#include<stdio.h>
int main()
{
	int i,a,b,c,k,size;
	scanf("%d %d %d",&a,&b,&c);
	size=a*c/b;
	k=0;
	for(i=1;i<=size;i++)
	{
		k=a*c-b*i;
		if((b*c)>=k)
		break;
	}
	printf("%d",i);
	return 0;
}
	
