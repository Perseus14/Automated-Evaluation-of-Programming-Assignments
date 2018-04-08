#include<stdio.h>
int main()
{
    int a,b,c,d,total,min,i;
    float show_mb,time_to_show,baki_time_show,haa,hbb;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        total=a*c;
        min=total/b;
        haa=1/(float)a;
        hbb=1/(float)b;

        for(i=c;i<=min;i++)
        {
            show_mb=(i*b);
           
            time_to_show=show_mb*haa;
        
            baki_time_show=(total-show_mb)*hbb;
           
            if(baki_time_show<=time_to_show)
            break;
        }
        if(i==1)
        printf("%d\n",i);
        else
        printf("%d\n",i-1);

    }
    return 0;
}
