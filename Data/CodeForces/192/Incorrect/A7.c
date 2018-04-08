//rextester.com:gcc 5.4.0--codeforces.com:gcc 5.1.0
#include<stdbool.h>
main(){
    int a;scanf("%d",&a);a*=2;bool b=false;
    for(int i=1;i<sqrt(a);i++){
        int c=a-i*i-i;int d=sqrt(c);
        if(d*(d+1)==c)b=true;
    }
    printf("%s",b?"YES":"NO");
}