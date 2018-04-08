#include<stdio.h>
#include<math.h>

int main()
{
	long long int x,i,a,b,c,flag=0;

	scanf("%I64d",&x);
	
	for(i=1;i<=sqrt(x);i++)
	{
		a=(i*(i+1))/2;
		
		b=x-a;
		
		c=sqrt(2*b);
		
		if((c*(c+1))/2==b)
		{
			flag=1;
			break;
		}
		
	}
	
	if(flag==1)
		printf("YES");
	else
		printf("NO");
	
	return 0;
}