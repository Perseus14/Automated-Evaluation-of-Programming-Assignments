#include <stdio.h>
int main()
{
    int min,i,a,b,c,sum,t,num,k,y;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        sum=a*c;
        t=sum/b;
        if(b*t<sum)
        t++;
        num=t*b;
        y=num;
        k=t;
        while(y>=a)
        {
            k++;y=y-a+b;
        }
        while(y+b>=a)
        {
            k++;y=y-a+b;
        }
        while(k*b>=sum)
        {
            t--;
            num-=b;
            y=num;
            k=t;
            while(y>=a)
            {
                k++;y=y-a+b;
            }
            while(y+b>=a)
            {
                k++;y=y-a+b;
            }
        }
        printf("%d\n",++t);
    }
    return 0;
}
