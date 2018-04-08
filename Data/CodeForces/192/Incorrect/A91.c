#include <stdio.h>
 
#define fo(i,m,n) for(i=m;i<n;i++)
#define rep(i,n) fo(i,0,n)
#define s(n) scanf("%d",&n)
#define ss(s) scanf("%s",s)
#define sc(c) scanf("%c",&c)
#define ps(s) printf("%s",s)
#define p(n) printf("%d\n",n)
#define swp(i,a,b) {i=a^b a^=i b^=i}
#define g(n) n*(n+1)/2
 
int main(void) {
int i,j,l,r,n;
s(n);
for(i=1,l=1;i<n;i+=l,l++)
for(j=1,r=1;j<=n-i;j+=r,r++)
{
if(g(i)+g(j)==n) { ps("YES\n"); return 0; }
} puts("NO\n");
return 0;
}