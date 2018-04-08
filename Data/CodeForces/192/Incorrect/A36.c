#include <stdio.h>
#include <stdlib.h>

int main()
{
   // int n,i,j,a,b,c;
   // scanf("%d",&n);
  //  scanf("%d%d%d",&a,&b,&c);
   // if(a+b+c<=n)printf("1");
   // else if(a+b<=n||a+c<=n||b+c<=n)printf("2");
   // else printf("3");
    int num,n=50000,i,j,a[50000],BO=0;
    scanf("%d",&num);
    for(i=0;i<50000;i++){
    a[i]=(i+1)*(i+2)/2;
    }

    for(i=0;i<n;i++){
        for(j=i;j<n;j++)if(a[i]+a[j]==num){printf("YES");BO=1;break;}
        if(BO==1)break;
    }

    if(i==n)printf("NO");

}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               