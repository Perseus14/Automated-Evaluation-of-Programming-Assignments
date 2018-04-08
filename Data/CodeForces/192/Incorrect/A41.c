#include<stdio.h>
#include<math.h>


int main(void)
{
    long long int input;
    scanf("%llu",&input);
    long int n,m,marker;
    long long int triangle2;
    int tag;

    for(n=1;n<46500;n++)
    { marker=0;
        triangle2=input-(n*n+n)+input;
        tag=sqrt(triangle2);
        if(tag*tag+tag==triangle2)
        {
             marker=1;
                break;
        }
    }
    if(marker==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
