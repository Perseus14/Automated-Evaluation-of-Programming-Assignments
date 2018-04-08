
#include <stdio.h>

int main() {
    int i=0,n;
scanf("%d",&n);
int a,b;
for(a=1;;a++){
    for(b=a;;b++){
        if(a*a+b*b==8*n+2)
        i++;
        if(a*a+b*b>=8*n+2)
        break;
    }
    if(a*a>=8*n+2)
    break;
    if(i!=0)
    break;
}

if(i==0)
printf("No");
else 
printf("Yes");

return 0;

}