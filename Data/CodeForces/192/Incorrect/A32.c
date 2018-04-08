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
     int n,m,i,k,j=0,s=0,x,t,z=0,a[100005],d;
     scanf("%d",&n);
     if(n==1)
     {
          puts("NO");
          return 0;
     }
     t=f(n);
     k=(t*(t+1))/2;
     s=n-k;
     j=f(s);
     m=(j*(j+1))/2;
     while(m<=k)
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