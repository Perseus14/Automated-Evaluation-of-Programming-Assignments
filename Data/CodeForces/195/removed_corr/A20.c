#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    int x=b*c;
    int y=a*c;
    int d=y-x;
    if(d%b==0){
        printf("%d",d/b);
    }
    else{
        printf("%d",(d/b)+1);
    }
    return 0;
}
