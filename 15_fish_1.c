#include <stdio.h>

int main()
{
int i,n,x,flag=1;
for(n=3; flag; n+=4)
  {
  for(x=n,i=1; i<5; i++)
    {
    if((5*x+1)%4 == 0) x=(5*x+1)/4;
    else flag=0;
    }
  if(flag) break;
  else flag=1;
  }
printf("Total fish is %d\n", 5*x+1);
}
