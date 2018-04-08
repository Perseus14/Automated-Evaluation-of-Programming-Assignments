#include<stdio.h>
#include<math.h>
int main(){
	int n,i,nn,ii;
	scanf("%d",&n);
	n*=2;
	for(i=1;;i++){
		nn=n-i*i-i;
		if(nn<0){printf("NO\n");return 0;}
		ii=sqrt(nn);
		if(ii>0&&ii*ii+ii==nn){printf("YES\n");return 0;}
	}
	return 0;
}
	  				 	 	  					 	    	  		 	