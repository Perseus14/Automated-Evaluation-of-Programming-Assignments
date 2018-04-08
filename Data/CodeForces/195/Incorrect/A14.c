#include <stdio.h>
int main()
{
    int min,i,a,b,c,sum,t,num,k;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        sum=a*c;
        t=sum/b;
        if(b*t<sum)
        t++;
        num=t*b;
        k=t+num/a;
        while((k+1)*b>=sum)
        {
            t--;
            num-=b;
            k=t+num/a;
        }
        printf("%d\n",++t);
    }
    return 0;
}
