#include <stdio.h>
#include <math.h>
int main()
{
  int integer[10], i, max, min, sum,n_best,n_worst,average;
  max=-32768;
  min=32768;
  sum=0;
  n_best=0;
  n_worst=0;
  for(i=0; i<10; i++)
  {
    printf("Input number %d=", i+1);
    scanf("%d", &integer[i]);
    sum+= integer[i];
    if(integer[i]>max) max=integer[i];
    if(integer[i]<min) min=integer[i];
  }
  average=(sum-max-min)/8;
  for(i=0; i<10; i++)
  {
    if(abs(integer[i]-average)>abs(integer[n_worst]-average)) n_worst=i;
    if(abs(integer[i]-average)<abs(integer[n_best]-average)) n_best=i;
  }
  printf("Canceled max score: %d\nCanceled min score %d\n", max, min);
  printf("Average score: %d\n", average);
  printf("Best judge: number %d\nWorst judge: number %d\n", n_best, n_worst);
}
