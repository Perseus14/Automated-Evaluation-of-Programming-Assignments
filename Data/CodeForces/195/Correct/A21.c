#include<stdio.h>
int main()
{
    int a, b, c, ans, cal;
    scanf("%d %d %d",&a, &b, &c);
    cal = c * (a-b);
    ans = (cal%b==0)?cal/b:(cal/b)+1;
    printf("%d\n",ans);
    return 0;
}
