#include <stdio.h>
#include <stdlib.h>

int main()
{
long long n,k;
scanf("%lld %lld",&n ,&k);
long long dip,cer,not;
dip=n/2/(k+1);
cer=dip*k;
not=n-(cer+dip);
printf("%lld %lld %lld",dip,cer,not);


    return 0;
}
