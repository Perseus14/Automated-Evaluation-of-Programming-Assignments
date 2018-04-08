#include<stdio.h>
#include<math.h>
int main()
{
   int a,b,c,ans;
   float ansf;
   scanf("%d %d %d",&a,&b,&c);
   if(a<=b)
      puts("0");
   else
   {
   ansf=((a*c)/(float)b)-c;
   ans=(int)ceil(ansf);
   printf("%d\n",ans);
   }
   return 0;
}


