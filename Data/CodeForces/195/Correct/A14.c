#include<stdio.h>
int main()
{
int a,b,c,x;
scanf("%d%d%d",&a,&b,&c);
int t = a*c - b*c;
x = t/b;
if(t%b)x++;
printf("%d\n",x);
return 0;
}