#include<stdio.h>
int main()
{
    int a, b, c, d, e, f;
    scanf("%d%d%d",&a,&b,&c);
    d=a-b;
    e=d*c;
    if(e%b==0)
    {
        f=e/b;
    }
    else
    {
        f=(e/b)+1;
    }
    printf("%d\n",f);
    return 0;
}

   		    	  	 	 	 					 	 			