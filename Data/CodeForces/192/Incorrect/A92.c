#include<stdio.h>
#include<math.h>
int main(void)
{
	double l,m;
	int n;
	int i;
	int flag;
	while(scanf("%d",&n)!=EOF)
	{
		flag=0;  
        m=pow(2*n-3,0.5);  
        for(i=1;i<=m;i++)  
        {  
            l=pow(2*n-i*(i+1),0.5);  
              
            if(l && l*(l+1)+i*(i+1)==2*n)  
            {  
                flag=1;  
                break;  
            }  
        }
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
