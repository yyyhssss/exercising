#include <stdio.h>
#include <math.h>

float capital(int n)
{
float cap, rate=0.0063;

if(n==1) cap=1000/(1+12*rate);
else cap=(capital(n-1)+1000)/(1+12*rate);

return cap;
}

int main()
{
printf("Capital should be %.2f\n", capital(5));
}
