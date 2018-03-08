#include <stdio.h>

int main()
{
int i,m,n,k;
for(m=4;m<3000;m++)
  {
  for(n=1,i=2;i<=m/2;i++)
    {
    if(m%i==0) n+=i;
    }
  for(k=1,i=2;i<=n/2;i++)
    {
    if(n%i==0) k+=i;
    }
  if(m==k && m<n) printf("%d and %d\n", m,n);
  }
}
