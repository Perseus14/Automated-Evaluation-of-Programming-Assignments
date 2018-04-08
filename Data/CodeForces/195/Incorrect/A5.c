#include <stdio.h>
int main()
{
    int a, b , c,e , d;
    scanf("%d %d %d", &a,&b, &c);
    d = c * a;
    if(c == 1) {
    e = (d / b) - c;
    if(e ==0 ){
        e =1;
    }
    }
    else if(c>1) {
e = (d / b) - (c-1);
    }
    printf("%d\n", e);
    return 0;
}

    		   				   	 					    			