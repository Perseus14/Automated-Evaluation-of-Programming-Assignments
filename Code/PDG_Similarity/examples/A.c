#include<stdio.h>

int main()
{
	long long int n,m,a;
	scanf("%I64d %I64d %I64d",&n,&m,&a);
	long long int r = n/a + (n%a==0?0:1);
    long long int c = m/a + (m%a==0?0:1);
	printf("%I64d",r*c);
}
