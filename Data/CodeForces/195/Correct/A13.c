#include<stdio.h>
int main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d",&a,&b,&c);
    d=a*c;
    if(d%b==0)
    e=d/b;
    else
    e=d/b+1;
    f=e-c;
    printf("%d\n",f);
    return 0;
}
