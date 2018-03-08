#include <stdio.h>

int main()
{
int i,j,k,m,n;
for(i=1;i<=6;i++)
  {
  for(j=0;j<=6;j++)
    {
    for(k=1;k<=6;k++)
      {
      m=i*49+j*7+k;
      n=k*81+j*9+i;
      if(m==n) printf("Septinary is %d, Novenary is %d\n", i*100+j*10+k,i+j*10+k*100);
      }
    }
  }
}
