#include<stdio.h>
#include<math.h>
int is_triangular(int n){
    //n=x*(x+1)/2;
    //0=x*x+x-2*n;
    //0=(x+1/2)^2-1/4-2*n
    //x=-1/2-+(sqrt(1/4+2*n));x>0，n将是负数
    //x=(sqrt(1/4+2*n))-1/2;
    int x=(int)(sqrt(0.25+2.0*n)-0.5);
    if(x*(x+1)/2==n){
        return 1;
    }else if((x+1)*(x+2)/2==n){
        return 1;
    }else if(x-1>0 && (x-1)*x/2==n){
        return 1;
    }else{
        return 0;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int i=1;
    int find=0;
    while(1){
        int triangular1=i*(i+1)/2;
        if(triangular1>n/2){
            break;
        }else{
            int triangular2=n-triangular1;
            if(is_triangular(triangular2)){
                find=1;
                break;
            }
        }
        i++;
    }
    if(find){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;

}
