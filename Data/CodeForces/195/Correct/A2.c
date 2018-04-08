#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
        int L = 1, R = a*c/b+1;
        while(R>L){
            int M = (L+R)/2;
            if(a*c <= (M+c)*b)
                R = M;
            else
                 L = M+1;
        }
        printf("%d\n", L);
    
    return 0;
}
