#include<stdio.h>
int main()
{
	int a,b,c,i,j,s=0,cnt=0,k=0;
	scanf("%d %d %d",&a,&b,&c);
	for(i=1;i<=a*c;i++)
	{
		if(i*b+b>=a)
		{
			s=i*b+b;
			for(j=2;j<=c;j++)
			{
				if(s+b>=a*j)
				{
					cnt++;
					s+=b;
				}
				else
				{
					s=0;
					cnt=0;
					break;
				}
			}
			if(cnt==c-1)
			{
				k++;
				printf("%d",i);
				break;
			}
		}
		if(k==1)
			break;
	}
	return(0);
}
