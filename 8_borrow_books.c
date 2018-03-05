#include <stdio.h>
int main()
{
int i,j,k,count=1;
for(i=0; i<5; i++)
{
  for(j=0; j<5; j++)
  {
    while(j==i) j++;
    for(k=0; k<5; k++)
    {
      while(k==j || k==i) k++;
      printf("Method %d: %d %d %d  ", count,i,j,k);
      count++;
    }
  }
}
}
