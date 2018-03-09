#include <stdio.h>

int fflag(int n);

int main()
{
int q[20]={1},s[20][10]={0};
int i,j,k,sum,flag=1,m,count=0;
for(i=0;i<20;i++)
  {
  for(j=0,k=0;j<10;j++)
    {
    sum=i+2*j+2+(i+1)%2;
    if(fflag(sum)) 
      {
      s[i][k]=2*j+1+(i+1)%2;
      k++;
      }
    }
  }
m=0;
for(i=1;i<20&&count<1000000;i++)
  {
  if(!flag) for(k=i+1;k<20;k++) q[k]=0;
  
  printf("old:");
  for(k=0;k<=i;k++)
  {printf("%3d", q[k]);}
  printf("\n");
  
  if(q[i]!=0)
    {
    for(m=0; s[q[i-1]-1][j]!=q[i];m++);
    m++;
    }
  for(j=m;s[q[i-1]-1][j]!=0;j++)
    {
    for(k=0;k<i&&flag==1;k++)
      {
      if(s[q[i-1]-1][j]==q[k]) flag=0;
      }
    if(flag)
      {
      q[i]=s[q[i-1]-1][j];
      break;
      }
    }
  if(s[q[i-1]-1][j]==0) i-=2;
  
  printf("new:");
  for(k=0;k<=i;k++)
  {printf("%3d", q[k]);}
  printf("\n");
  }
  count++;
}

int fflag(int n)
{
int i;
if(n==1 || n==2 || n==3) return(1);
for(i=2;i<=n/2;i++)
  {
  if(n%i==0) return(0);
  }
return(1);
}
