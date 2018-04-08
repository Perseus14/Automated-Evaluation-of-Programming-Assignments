#include <stdio.h>
#define ll long long;

int main(void) {
    ll int x;
    scanf("%lld",&x);
    ll int a[250000];
    ll int c=0;
    a[c]=1;
    while(a[c]<=x){
        ll int temp=c;
        a[++c]=a[temp]+temp+2;
    }
    ll int i,j;
    for(i=0;i<c;i++){
        for(j=i;j<c;j++)    if(a[i]+a[j]==x){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}
