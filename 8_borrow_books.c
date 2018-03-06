#include <stdio.h>
int main()
{
int i,j,k,count=1;
for(i=1; i<=5; i++)
{
  for(j=1; j<=5; j++)
  {
    for(k=1; i!=j && k<=5; k++)
    {
      if(i!=k && j!=k)
      {printf(count%8?"%2d: %d %d %d " : "%2d: %d %d %d\n", ++count,i,j,k);}
    }
  }
}
}
