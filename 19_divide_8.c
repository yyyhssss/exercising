#include <stdio.h>

int main()
{
int a,n8,n17,flag=1;
for(a=1; flag; a++)
  {
  n8=8*(8*(8*a+7)+1)+1;
  n17=17*(17*2*a+15)+4;
  if(n8==n17) flag=0;
  }
printf("This number is %d\n", n8);
}
