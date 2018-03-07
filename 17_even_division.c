#include <stdio.h>

int main()
{
int a1,a2,b1,b2,i=1;
for(a1=1;a1<=6;a1+=2)
  {
  for(a2=1;a2<=(6-a1);a2+=2)
    {
    b1=(7-a1)/2; b2=(7-a2)/2;
    if(((7-a1-a2)+2*(7-b1-b2))==7)
      {
      printf("Method %d: Full %d %d %d, Half %d %d %d, Empty %d %d %d\n", i,b1,b2,7-b1-b2,a1,a2,7-a1-a2,7-b1-a1,7-b2-a2,a1+a2+b1+b2-7);
      i++;
      }
    }
  }
}
