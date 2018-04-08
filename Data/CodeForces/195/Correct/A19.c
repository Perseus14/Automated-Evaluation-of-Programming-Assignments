#include<stdio.h>
int main()
{
    int a,b,c,t,r,x;
    scanf("%d %d %d",&a,&b,&c);
    t=a*c;
    r=t-(b*c);
    x=ceil(1.0*r/b);
    printf("%d",x);
    return 0;


}
