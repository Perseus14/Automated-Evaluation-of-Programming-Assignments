#include<stdio.h>
int main()
{
	long long int num=44720,a;
	long long int A[num+1],i,j;
	for(i=1;i<=num;i++)
	A[i]=(i*(i+1))/2;
	//for(i=1;i<=22;i++)
	//printf("%lld\n",A[i]);
	long long int n;
	scanf("%lld",&n);
	for(i=1;i<=num;i++)
	{
		a=n-A[i];
		if(a<=0)
		{
			printf("NO");
			return 0;
		}
		long long int first=0;;
		long long int last=num;
		long long int middle=(first+last)/2;
		while(first<=last)
		{
			if(A[middle]<a)
			first=middle+1;
			else if(A[middle]>a)
			last=middle-1;
			else if(A[middle]==a)
			{
				printf("YES");
				return 0;
			}
			middle=(first+last)/2;
		}
	}
//	printf("%lld %lld",i,j);
	printf("NO");
	return 0;
}