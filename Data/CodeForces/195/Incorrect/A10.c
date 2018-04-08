#include<stdio.h>
int main()
{
    int a,b,c,t,i,q,s;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        t=a*c;
        s=0;
        for(i=1;; i++)
        {
            s++;
            q=(b*i)+((b*i)/c);
            if(q>t)
                break;
        }
        printf("%d\n",s);

    }
    return 0;
}

 	  	 			  		 					 			  			 		