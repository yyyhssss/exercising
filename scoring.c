#include <stdio.h>
main
{
  int integer, i, max, min, sum;
  max=-32768;
  min=32768;
  sum=0;
  for(i=1; i<=10; i++)
  {
    printf("Input number %d=", i);
    scanf("%d", &integer);
    sum+= integer;
    if(integer>max) max=integer;
    if(integer<min) min=integer;
  }
  printf("Canceled max score: %d\nCanceled min score %d\n", max, min);
  printf("Average score: %d", (sum-max-min)/8);
}
