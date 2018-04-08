#include<stdio.h>
#include<math.h>
int main()
{
    int n,d,s,w,c;
    scanf("%d %d %d",&n,&d,&s);
    c=n*s-d*s;
    w=ceil(1.0*c/d);
    printf("%d",w);
    return 0;
}
