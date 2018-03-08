#include <stdio.h>

int main()
{
int i,n,m;
for(n=4;n<1000;n++)
  {
  for(m=1,i=2;i<=n/2;i++)
    {
    if(n%i==0) m+=i;
    }
  if(n==m) printf("%d\n", n);
  }
}
