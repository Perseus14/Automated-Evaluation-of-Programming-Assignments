//http://codeforces.com/problemset/problem/192/A

#include <stdio.h>

long long f(int k)
{	
	return  ((long long)k*(k+1))/2;
}

int main()
{
	long long n;
	scanf("%lld",&n);
	int i;
	for(i =1;f(i)<=n;i++)
	{
		long long int src = n - f(i);
		//printf("%d %lld %lld\n",i,f(i),src );
		int l = 1;
		int r = 1000000ll;
		//printf("%d\n",n );
		int mid;
		while(l<=r)
		{

			mid = (l+r)/2;
			if(f(mid) == src)
			{
				printf("YES");
				return 0;
			}
			else if(f(mid) > src)
				r = mid-1;
			else if(f(mid) < src)
				l = mid+1;
		}
	}

	printf("NO\n");
	return 0;
}