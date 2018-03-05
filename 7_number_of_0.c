#include <stdio.h>
int main()
{
int i,n=0,final;
long multi=1;
printf("Please input a number(>=2):");
scanf("%d", &final);
for(i=2; i<=final; i++)
{
  multi=multi*i;
  while((multi%10)==0)
  {
    multi/=10;
    n++;
  }
}
printf("%d! has %d digit of 0", final, n);
}
