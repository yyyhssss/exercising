#include <stdio.h>

int main()
{
int n,x=11;
for(n=4; n>=1; n--)
  {
  x=(x*(n+1)+1)/n;
  }
printf("Total fish is %d\n", x);
}
