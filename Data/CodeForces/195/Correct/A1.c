#include<stdio.h>
int main()
{
    int a,b,c,sum;
    scanf("%d %d %d",&a,&b,&c);
    sum=((a-b)*c+b-1)/b;
    printf("%d\n",sum);
    return 0;
}
