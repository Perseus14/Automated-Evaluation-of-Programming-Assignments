#include<stdio.h>
#include<math.h>
int main()
{
    double a, b, c, n, s1=0, s2=0, hold, mark=0;
    scanf("%lf", &n);
    if(n==1){
        printf("NO");
        return 0;
    }
    for(a=1;a<=sqrt(n);a++){
        s1 = ((a+1)*a)/2;
        hold = n-s1;
        b = (-1+sqrt(1+(8*hold)))/2;
        if(b==(int)b){
            mark=1;
            break;
        }
    }
    if(mark){
        printf("YES");
    }
    else{
        printf("NO");
    }


    return 0;

}
