# include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if (((a-b)*c) % b == 0)
    {
        printf("%d",(a-b)*c/b);
    }
    else if((a-b)*c % b != 0)
    {
        printf("%d",(a-b)*c/b+1);
    }
    else if(((a-b)*c)<b)
    {
        printf("%d",(a-b)*c);
    }
    return 0;
}

 		   			  	  		  			 		