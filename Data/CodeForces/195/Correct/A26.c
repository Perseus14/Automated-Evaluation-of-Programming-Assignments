#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    printf("%d\n",(int) ceil((a-b)*(c/b)));
    return 0;


}