#include<stdio.h>
int main()
{
    int a,b,c,d,total,min,i,show_mb,baki_mb_show;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        total=a*c;
        min=total/b;
        for(i=1;i<=min;i++)
        {
            show_mb=(i*b);
            baki_mb_show=(total-show_mb);
            if(baki_mb_show<=c*b)
            break;
        }
        printf("%d\n",i);

    }
    return 0;
}
