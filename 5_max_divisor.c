#include <stdio.h>
int main()
{
long i;
int j;
printf("Please input a number:");
scanf("%ld", &i);
for(j=999; j>=100; j--)
{
  if(i%j==0)
  {
    printf("The max 3 digit divisor of %ld is %d\n", i, j);
    break;
  }
}
if(j<100) printf("There is no 3 digit divisor of %ld", i);
}
