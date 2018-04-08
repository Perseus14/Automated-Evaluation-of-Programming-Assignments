#include<stdio.h>
int main()
{
    #ifdef debug
        freopen("in.txt","r",stdin);
    #endif
    double a,b,c,t;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        t=a*c/b-c;
        if(t>(int)t)t+=1;
        printf("%d\n",(int)t);
    }
    return 0;
}

			   	 			 			 	   	     	