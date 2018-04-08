#include<stdio.h>
#include<math.h>

int main(void){
	int n;
	scanf("%d",&n);
	int i,f,j;
	__int64 k,m,t,p;
	f=0;
	for(i=1;;i++){
		k=i*(i-1)/2;
		if(k>1000000000)
			break;
		else{
			m=(n-k)*2;
			t=sqrt(m)-2;
			for(j=t;;j++){
				p=j*(j+1);
				if(p==m){
					f=1;
					break;
				}
				else if(p>m)
					break;
			}
		}
		if(f==1)
				break;
	}
	if(f==1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

