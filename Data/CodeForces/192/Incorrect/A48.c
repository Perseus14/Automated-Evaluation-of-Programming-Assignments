#include<stdio.h>


int main(void)
{
    long long int input;
    scanf("%llu",&input);
    int n,m,marker;
    input=input*2;
    long long int triangle2;
    for(n=1;n<22500;n++)
    { marker=0;
        triangle2=input-n*n-n;
        if(triangle2%2==1)
            continue;
        for(m=1;m<22500;m++)
        {
            if(m*m+m==triangle2)
                marker=1;
            if(marker==1)
                break;
        }
        if(marker==1)
            break;
    }
    if(marker==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
