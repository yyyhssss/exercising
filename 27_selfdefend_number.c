#include <stdio.h>
#include <math.h>

int main()
{
long i,k,m,rest,last,ll;
for(i=0;i<200000;i++)
  {
  for(k=1;i/k!=0;k*=10);
  for(m=0,ll=1;ll<k;ll*=10)
    {
    rest=i/ll;
    last=rest%10*ll;
    m=(m+i*last)%k;
    }
  if(m==i) printf(" %7ld", i);
  }
}
