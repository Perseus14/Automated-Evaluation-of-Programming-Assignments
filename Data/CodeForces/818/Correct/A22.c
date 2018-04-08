#include <stdio.h>

int main()
{
	long long n, k;
	long long a;
	scanf("%lld %lld", &n, &k);
	a = (n / 2) / (k + 1);
	if (n / 2 - a - a*k < 0)
		a--;

	printf("%lld %lld %lld", a, k*a, n - a - k*a);
}