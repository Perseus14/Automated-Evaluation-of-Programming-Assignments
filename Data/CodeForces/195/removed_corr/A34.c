#include<stdio.h>
int main()
{
    int a,b,c,x=0;
    scanf("%d %d %d",&a,&b,&c);
    while(1)
    {
     if(b*(x+c)>=a*c)
     {
         printf("%d",x);
         return 0;
     }
     x++;
    }
}
