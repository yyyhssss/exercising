#include <stdio.h>
int main()
{
int i,j,n=0,final;
printf("Please input a number(>=5):");
scanf("%d", &final);
for(i=5; i<=final; i++)
{
  if(i%5==0)
  {
    n++;
    for(j=i/5; j>=5; j=j/5)
    {
      if(j%5==0) n++;
    }
  }
}
printf("%d! has %d digit of 0", final, n);
}
