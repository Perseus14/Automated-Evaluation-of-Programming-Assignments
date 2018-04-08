#include<stdio.h>

int a,b,c;


int main()
{
    scanf("%d%d%d",&a,&b,&c);
    int l = 0, r = a*c/b+1;
	while (r>l)
    {
        int m=(l+r)/2;
        if(a*c<=(m+c)*b)
            r=m;
        else
            l=m+1;
    }
 
    long ans=l;
    printf("%ld",ans);
    return 0;
}
