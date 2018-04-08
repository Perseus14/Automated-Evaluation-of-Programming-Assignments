#include <stdio.h>
#include <stdlib.h>
int main()
{
        int number ;
        scanf("%d",&number);
        int f1 = 1 ,f2 = 1 , i = 1 , j;// the relation f2 = f1 + k + 1

        for( i = 1; f1 < number ; i++)
        {
            for( j = i ; f2 <= number - f1 ;j++ )
            {  if(f1 + f2 == number)
              {
                printf("YES");
                return 0;
              }
            f2 = f2 + j + 1;
           }
        f1 = f1 + i + 1;
        f2 = f1;
        }
           printf("NO");
    return 0;
}
