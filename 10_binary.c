#include <stdio.h>
#include <math.h>
int main()
{
int n,i=0;
long result=0;
printf("Please input a number:");
scanf("%d", &n);
for( ; n>0; n=n/2)
  {
  result+=n%2*pow(10,i);
  i++;
  }
printf("Binary of this number is %ld\n", result);
}
