#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cmf(const void*a,const void*b)
{
     return (*(int*)a-*(int*)b);
}
int f(int n)
{
     long long s,t,sq,p;
     s=(n*8)+1;
     sq=sqrt(s)-1;
     t=sq/2;
     return t;
}
int b[100001],c[100001];
int main()
{
     int n,m,i,k,j=0,s=0,t,z=0,a[100005],d;
     scanf("%d",&n);
     if(n==1)
     {
          puts("NO");
          return 0;
     }
     t=f(n);
     k=(t*(t+1))/2;
     s=n-k;
     if(!s)
     {
          puts("YES");
          return 0;
     }
     j=f(s);
     j=(j*(j+1))/2;
     if(j==s)
     puts("YES");
     else
     puts("NO");
     return 0;
}