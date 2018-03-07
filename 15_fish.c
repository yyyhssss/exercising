#include <stdio.h>

int main()
{
int temp1, temp2, temp3,temp4;
for(temp1=3; ; temp1+=4)
  {
  if((5*temp1+1)%4!=0) continue;
  else
    {
    temp2=(5*temp1+1)/4;
    if((5*temp2+1)%4!=0) continue;
    else
      {
      temp3=(5*temp2+1)/4;
      if((5*temp3+1)%4!=0) continue;
      else
        {
        temp4=(5*temp3+1)/4;
        if((5*temp4+1)%4!=0) continue;
        else break;
        }
      }
    }
  }
printf("There is at least %d fish.\n", (5*temp4+1)/4*5+1);
}
