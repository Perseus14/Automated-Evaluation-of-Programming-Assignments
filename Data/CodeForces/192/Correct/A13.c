#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long arr[1000001];

int func(const void *a, const void *b)
{
	return (*(int*)a-*(int*)b);
}
long long max(long long a, long long b)
{
	return (a>b)?a:b;
}
long long min(long long a, long long b)
{
	return (a>b)?b:a;
}
long long sum(long long n)
{
	return((n)*(n+1))/2;
}
long long bs(long long i, long long index1, long long j, long long n)
{
	long long mid=(index1+j)/2;
	if(index1==j)
	{
		if(arr[i]+arr[mid]==n)
			return 1;
		else
			return 0;
	}
	if(arr[i]+arr[mid]==n)
		return 1;
	if(arr[i]+arr[mid]<n)
		return bs(i,mid+1,j,n);
	if(arr[i]+arr[mid]>n)
		return bs(i,i,mid,n);
}
int main()
{
	long long int n, i, j, k, count=0, ans=0;
	long long flag=0;
	scanf("%lld", &n);
	long long upperbound=sqrt(2*n);
	for(i=1;i<=1000001;i++)
		arr[i]=sum(i);
	for(i=1;arr[i]<=n;i++)
		if(bs(i,i,upperbound,n))
			{flag=1;break;}
	if(flag)
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}
