#include<stdio.h>
#include<math.h>


int main(void)
{
    int input;
    scanf("%llu",&input);
    int n,m,marker;
    int triangle2;
    int tag;
    for(n=1;n<46500;n++)
    { marker=0;
        triangle2=input-(n*n+n)+input;
        tag=sqrt(triangle2);
        if(triangle2==0)
        {
        printf("NO");
            return 0;
        }
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
