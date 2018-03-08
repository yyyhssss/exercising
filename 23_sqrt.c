#include <stdio.h>
#include <math.h>

int f(int i, int *s);

int main()
{
int i,j, a[3],b[3];
for(i=11;i<=31;i++)
  {
  for(j=11;j<=31;j++)
    {
    f(i*i, a);
    f(j*j, b);
    if(sqrt(a[0]*10+b[0])==(int)sqrt(a[0]*10+b[0])
       &&sqrt(a[1]*10+b[1])==(int)sqrt(a[1]*10+b[1])
       &&sqrt(a[2]*10+b[2])==(int)sqrt(a[2]*10+b[2]))
      printf("%d and %d\n", i*i,j*j);
    }
  }
}

int f(int i, int *s)
{
int k;
for(k=1000;k>=10;k/=10,s++)
  {
  *s=i/(k/10);
  i=i%(k/10);
  }
}
