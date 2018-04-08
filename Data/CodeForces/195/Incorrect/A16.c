#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,p=1,ans,x=0;
    scanf("%d %d %d",&a,&b,&c);
    d=c*a;
    e=d/b;
    f=e-c;
    while(p)
    {
        if(x<=f)
            x++;
        else
        {
            p=0;

        }

    }

    printf("%d",x);
    return 0;
}
