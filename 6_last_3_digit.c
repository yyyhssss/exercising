#include <stdio.h>
main
{
int i,x,y,multi;
multi=1;
printf("Pleaes input two numbers X and Y (X**Y)\n");
scanf("%d**%d", &x, &y);
for(i=0; i<y; i++)
  multi=multi*x%1000;
printf("Last 3 digit of %d**%d is %d\n", x, y, multi);
}
