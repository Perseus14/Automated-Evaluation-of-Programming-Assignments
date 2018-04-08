#include <stdio.h>
#include <stdlib.h>
int main()
{
        int a , b , c ,minl;
        scanf("%d%d%d",&a,&b,&c);
        int i ;
         int total_data = a*c ;
        for( i = 1; i < total_data ; i++)
        {
            int remain = total_data - i*b;
            if(b*c >= remain)
            {
                minl = i;
                break;
            }

        }
        printf("%d",minl);

    return 0;
}
