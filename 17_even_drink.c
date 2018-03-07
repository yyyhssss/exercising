#include <stdio.h>

int main()
{
int n1,n2,n3;
n1=2;
for(n2=n1+1;n2<5;n2++)
  {
  for(n3=n2+1;n3<100;n3++)
    {if((n1*n2+n1*n3+n2*n3)==n1*n2*n3) printf("Number of each bottle is: %d %d %d\n", n1,n2,n3);}
  }
}
