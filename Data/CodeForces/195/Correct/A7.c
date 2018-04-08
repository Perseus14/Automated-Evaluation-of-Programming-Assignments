#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,x;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        x=ceil((1.0*a/b)*c-c);
        printf("%d\n",x);
    }
    return 0;
}
