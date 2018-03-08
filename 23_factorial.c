#include <stdio.h>

int factorial(int n);

int main()
{
int i,j,k,m,n;
for(i=1;i<=9;i++)
  {
  for(j=1;j<=9;j++)
    {
    for(k=1;k<=9;k++)
      {
      m=factorial(i)+factorial(j)+factorial(k);
      n=i*100+j*10+k;
      if(m==n) printf("%d = %d!+%d!+%d!\n", m,i,j,k);
      }
    }
  }
}

int factorial(int n)
{
int s=1;
if(n==1) return(s);
else s=n*factorial(n-1);

return(s);
}
