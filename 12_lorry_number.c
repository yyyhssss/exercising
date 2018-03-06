#include <stdio.h>
#include <math.h>
int main()
{
int i,j,k,m;
for(i=1;i<=9;i++)
  {
  for(j=1;j<9;j++)
    {
    if(i!=j)
      {
      k=i*1000+i*100+j*10+j;
      for(m=31; m<100; m++)
        {
        if(m*m==k) printf("Lorry No. is: %d\n", k);
        }
      }
    }
  }
}
