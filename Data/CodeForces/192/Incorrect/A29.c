#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int cmf(const void*a,const void*b)
{
     return (*(int*)a-*(int*)b);
}
long long f(long long n)
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
     long long n,m,i,k,j=0,s=0,x,t,z=0,a[100005],d;
     scanf("%lld",&n);
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
        puts("NO");
        return 0;
     }
     j=f(s);
     m=(j*(j+1))/2;
     while(k)
     {
      // printf("%d + %d = %d\n",k,m,k+m);
        if(k+m==n)
        {
           puts("YES");
           return 0;
        }
        k-=t;
        x=f(n-k);
        m=(x*(x+1))/2;
        t--;
     }
     puts("NO");
     return 0;
}