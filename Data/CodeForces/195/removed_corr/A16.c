#include <stdio.h>

int main()
{
    int a,i,n,b,c,ans=0;
    scanf("%d %d %d",&a,&b,&c);
    a-=b;
    a*=c;
    for(i=0;i<a;i+=b)
    {
        ans++;
    }
    printf("%d",ans);
    return 0;


}
