#include <stdio.h>
int main()
{
int i,j,k,count=1;
for(i=0; i<5; i++)
{
  for(j=0; j<5; j++)
  {
    for(k=0; k<5; k++)
    {
      if(i!=j && i!=k && j!=k)
      {printf(count%8?"%2d: %d %d %d " : "%2d: %d %d %d\n", ++count,i,j,k);}
    }
  }
}
}
