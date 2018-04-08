#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{

  int a,b,c;
 
  scanf("%d%d%d",&a,&b,&c);
  int time;
  if(a<=b)
   printf("%d\n",c);
  else
   {

      int data  = c*b;
      int ddata = a*c-data;
      time  = ceil((double)ddata/b);

   }
   
   printf("%d\n",time);

}
