#include<stdio.h>
#include<math.h>




main()
{
    long long D=0,C=0,N=0,n=0,k=0;

    scanf("%I64d  %I64d",&n,&k);

    D=n/(2+(2*k));
    printf("%I64d ",D);
    C=k*D;
    printf("%I64d ",C);
    N=n-(C+D);
    printf("%I64d",N);




    return 0;
}
