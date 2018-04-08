#include <stdio.h>

int main(void) {
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	a=c*(a-b);
	if(a%b==0){
		a=a/b;
		printf("%d",a);
		return 0;
	}
	else{
		a=a/b;
		a=a+1;
		printf("%d",a);
		return 0;
	}}
