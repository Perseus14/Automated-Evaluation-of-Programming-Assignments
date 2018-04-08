#include <stdio.h>
int main()
{
unsigned int a,k,d;
scanf("%u  %u",&a,&k);
 if(k+1<=a/2)
{
d=(a/2)/(k+1);
}
printf("%u %u %u",d,d*k,a-(d+d*k));
return 0;
}
