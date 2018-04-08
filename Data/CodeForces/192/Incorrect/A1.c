#include<stdio.h>
#include<math.h>
int main()
{
	long long db[50010];
	int n,bj,pd;
	for(int i=1;i<=50000;i++)
	db[i]=i*(i+1)/2;
	while(scanf("%d",&n)!=EOF)
	{
		pd=0;
		for(int i=1;i<=50000;i++)
		if(2*db[i]>=n)
		{
			bj=i;
		 break;
	     }
	     for(int i=1;i<=bj;i++)
	     if(db[i]+db[bj]==n)
	     {
	     	pd=1;
	     	break;
		 }
		 if(pd==1)
		 printf("YES\n");
		 else
		 printf("NO\n");
	 } 
	 return 0;
 } 
 		 	  	    	 	 	 	 	       	 	