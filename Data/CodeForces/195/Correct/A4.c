#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int result(int [],int,int);
int cmpfunc(const void*a,const void*b)
{
    return (*(int*)a - *(int*)b);
}
int main()
{
    int n,m,i,j,sum=0,chk=0,k=0,c=0,max=0,min=0,d=0;
    int a[2000005]={0},b[5]={0};
    char ch[101];
    scanf("%d%d%d",&n,&m,&k);
    sum=(n-m)*k;
    d=sum/m;
    if(sum%m)
    d++;
    printf("%d",d);
    return 0;
}