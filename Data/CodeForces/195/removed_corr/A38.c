#include<stdio.h>
main()
{
    int a,b,c,t,i;
    scanf("%d %d %d",&a,&b,&c);

    t=(a-b)*c;
        for(i=1;;i++)
        if(i*b>=t) {printf("%d",i);exit(0);}
    return 0;
}
