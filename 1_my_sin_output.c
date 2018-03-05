#include <stdio.h>
#include <math.h>
main()
{
double y;
int x,m;
for(y=1;y>=-1;y-=0.1)
  {
  m=asin(y)*10;
  if(m>=0)
    {
    for(x=0; x<m; x++)
    {printf(" ");}
    printf("*");
    for( ; x<31-m; x++)
    {printf(" ");}
    printf("*\n");
    }
  else
    {
    for(x=0; x<31-m; x++)
    {printf(" ");}
    printf("*");
    for( ; x<62-m; x++)
    {printf(" ");}
    printf("*\n");
    }
  }
}
