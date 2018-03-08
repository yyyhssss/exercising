#include <stdio.h>

int main()
{
int i,j,m,n;
for(i=0;i<=1;i++)
  {
  for(j=0;j<=9;j++)
    {
    m=1000+i*100+j*10+9;
    n=9000+j*100+i*10+1;
    if(9*m == n) printf("Original is %d, Reverse is %d\n", m,n);
    }
  }
}
