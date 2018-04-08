#include<stdio.h>
int main()
{
    int a,b,c,x,y,result;
    scanf("%d %d %d",&a,&b,&c);
    x=a*c;
    y=x/b;
    if(x%b!=0)
    {
        y=y+1;

    }
    result=y-c;
    printf("%d",result);
    return 0;
}

 	 	  	  	 	 	 	     	 					 		