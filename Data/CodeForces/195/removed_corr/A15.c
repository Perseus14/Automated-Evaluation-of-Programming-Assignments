#include <stdio.h>

int main()
{
    int i,a,b,c,ans=0;
    scanf("%d %d %d",&a,&b,&c);
    a=(a-b)*c;
    for(i=0;i<a;i+=b,ans++);
    printf("%d",ans);
    return 0;
}
