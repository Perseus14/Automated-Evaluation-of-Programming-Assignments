#include <stdio.h>
int main(void)
{
	int a,b,c,i,f,j;
	scanf("%d %d %d",&a,&b,&c);

	int r=((c*a)%b)==0?c*a/b:c*a/b+1;
	int min=r;

	for(i=1;i<=r;++i)
	{
		f=1;
		for(j=i;j<=r;++j){
			if(j-i>c) break;
			if(i*b+(j-i)*b<(j-i)*a) f=0;
		}
		if(f && i<min) min=i;
	}
	printf("%d",min);
	return 0;
}