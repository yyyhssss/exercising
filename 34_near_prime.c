#include <stdio.h>
#define N 20

int fflag(int n);

int main()
{
int q[N]={1},s[N][10]={0};
int i,j,k,sum,flag=1,m,count=0,iflag=N-2;
for(i=0;i<N;i++)
  {
  for(j=0,k=0;j<(N/2);j++)
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
for(i=1;i<N&&i>=1;i++)
  {
  if(i!=(N-1)) {for(k=i;k<N;k++) q[k]=0;}
  
  for(j=m;s[q[i-1]-1][j]!=0;j++)
    {
    for(k=0,flag=1;k<i&&flag==1;k++)
      {
      if(s[q[i-1]-1][j]==q[k]) flag=0;
      }
    if(flag)
      {
      q[i]=s[q[i-1]-1][j];
      break;
      }
    }
  if(s[q[i-1]-1][j]==0) 
    {
    i--;
    iflag=i;
    for(m=0;s[q[i-1]-1][m]!=q[i];m++) ;
    i--;
    m++;
    }
  else m=0;
  
  if(i==(N-1)&&q[N-1]!=0)
    {
      if(!fflag(q[N-1]+q[0]))
        {
        i--;
        for(m=0;s[q[i-1]-1][m]!=q[i];m++) ;
        i--;
        m++; 
        }
      else
        {
        if(q[N-1]>q[1]) continue;
        printf("queue:");
        for(k=0;k<N;k++)
            printf("%3d",q[k]);
        printf("\n");
        
        i=iflag;
        for(m=0;s[q[i-1]-1][m]!=q[i];m++) ;
        i--;
        m++;
        }
    }

  count++;
  }
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
