#include<stdio.h>
#include<stdlib.h>
#define N 100000
//这个问题可以用binary search
//这是一个有趣的实现！
int main() {
    int n;
    scanf("%d",&n);
    int triangular[N];
    int t=0;
    int i;
    //printf("n=%d\n",n);
    for(i=1;(i*(i+1)/2)<=n;i++){
        triangular[t]=i*(i+1)/2;
        t++;
        if(t==N){
            printf("我申请的内存不够存放整个三角数数组\n");
            exit(1);
        }
    }
    int find=0;
    /*
    for(i=0;i<t;i++){
        printf(" %d",triangular[i]);
    }
    printf("\n");
    */
    for(i=0;i<t && !find;i++){
        int triangular1=triangular[i];
        int target=n-triangular1;
        int left=0;int right=t-1;
        while(left<=right){
            int middle=(left+right)/2;
            if(triangular[middle]==target){
                find=1;
                //printf("%d+%d\n",triangular[i],target);
                break;
            }else if(triangular[middle]>target){
                right=middle-1;
            }else{
                left=middle+1;
            }
        }
    }
    if(find){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;

}
