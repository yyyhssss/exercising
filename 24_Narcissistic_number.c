#include <stdio.h>
#include <math.h>

int f(int n,int *s)
{
int k;
for(k=1000;k>=10; s++)
  {
  *s=(n%k)/(k/10);
  k/=10;
  }
return(0);
}

int main()
{
int i, a[3];
for(i=1;i<1000;i++)
  {
  f(i,a);
  if(i==(pow(a[0],3)+pow(a[1],3)+pow(a[2],3)))
    printf("%d = %d**3 + %d**3 + %d**3\n", i,a[0],a[1],a[2]);
  }
}
