#include <stdio.h>
#include <stdlib.h>
#define int long long int

signed main() 
{
    int n,k;
    int w,d;
    scanf("%lld%lld",&n,&k);
    
    w=n/2;
    d=((w/k) - 1);
    if(d <=0 )
    {
	d=0;
	w=0;
    }	
 	
	
    printf("%lld %lld %lld",d,k*d,n-w);
    
    

	return 0;
}
