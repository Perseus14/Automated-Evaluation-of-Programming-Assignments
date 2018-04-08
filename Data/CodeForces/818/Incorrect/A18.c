#include"stdio.h"
#include"string.h"
#include"math.h"
#include"stdlib.h"
#include"ctype.h"
#include"limits.h"
#include"time.h"
int cfc(const void *a, const void *b)
{
	if(*(long long*)a>*(long long*)b)
	return -1;
	else if(*(long long*)a<*(long long*)b)
	return 1;
	else
	return 0;
}

int main()
{
	clock_t lnh=clock();
	long long n,k,a;
	scanf("%lld%lld",&n,&k);
	a=(n/2)/(k+1);
	//int a[n],i;
	//for(i=0;i<n;scanf("%d",&a[i++]));
	//qsort(a,n,sizeof(int),cfc);
	printf("%lld %lld %lld\n",a,k*a,n-k*a);
	
	clock_t cls=clock();	//printf("%fms\n",(double)((cls-lnh)*1000)/CLOCKS_PER_SEC);
	return 0;
}