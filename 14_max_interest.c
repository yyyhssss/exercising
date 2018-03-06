#include <stdio.h>
#include <math.h>

int main()
{
int n8,n5,n3,n2,n1,max[5];
float rate[5]={0.0084*12,0.0075*12,0.0069*12,0.0066*12,0.0063*12};
float total=0,term=00;
for(n8=0; n8<3; n8++)
  {
  for(n5=0; n5<=((20-8*n8)/5); n5++)
    {
    for(n3=0; n3<=((20-8*n8-5*n5)/3); n3++)
      {
      for(n2=0; n2<=(20-8*n8-5*n5-3*n3)/2; n2++)
        {
        n1=20-8*n8-5*n5-3*n3-2*n2;
        term=2000*pow((1+8*rate[0]),n8)*pow((1+5*rate[1]),n5)*pow(1+3*rate[2],n3)*pow(1+2*rate[3],n2)*pow(1+rate[4],n1);
        if(term>total)
          {
          total=term;
          max[0]=n8; max[1]=n5; max[2]=n3; max[3]=n2; max[4]=n1;
          }
        }
      }
    }
  }
printf("Method for max interest is:\n");
printf("8-year %d times\n", max[0]);
printf("5-year %d times\n", max[1]);
printf("3-year %d times\n", max[2]);
printf("2-year %d times\n", max[3]);
printf("1-year %d times\n", max[4]);
printf("Max interest is %.3f\n", total);
}
