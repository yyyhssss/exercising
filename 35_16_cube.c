#include <time.h>
#include <stdio.h>

#define N 16

int b[17]={0};
int total=0;
int a[17]={0};
void search(int t);
void print();
int pd(int,int);
int main()
{
    int i;
    time_t start,end;
    double cost=0;
    time(&start);
    for(i=1;i<=11;i++)
    {
      a[1]=i;
      b[i]=1;
      search(2);
      b[i]=0;
    }
    //search(1);
    time(&end);
    cost=difftime(end,start);
    printf("cost is %f\n",cost);
    return 0;
} 
void search( int n)
{
    int i;
    for (i=1;i<=16;i++)
    {
      if(b[i])	continue;     //如果该数存在，继续寻找下一个

      if(n<5)
      {
	if(n==4)
	  if(i<a[1])	continue;   //如果右上角>左上角，寻找下一个

	if( pd(a[n-1],i) )
	{
	  a[n]=i;
	  b[i]=1;
	  search(n+1);
	  b[i]=0;
	}
      }
      else
      {
	if(n==13)
	  if(i<a[4])	continue;          //如果左下角>右上角，寻找下一个

	if(n%4==1? pd(a[n-4],i): (pd(a[n-1],i) && pd(a[n-4],i)) )
	{
	  a[n]=i;
	  b[i]=1;
	  if(n==16 && i>a[13])
	    print();
	  else
	    search(n+1);
	  b[i]=0;
	}
      }
    }
}
void print()
{
    total++;
    printf("%d\n",total);
    for (int j=1;j<=N;j++)
    {
      printf(j%4? "%3d":"%3d\n", a[j]);
    }
 
}
int pd(int x,int y)
{
    int i=x+y;
    for (int k=2;k*k<=i;k++)
    {
        if(i%k== 0)
        {
            return 0;
        }
    }
 
    return 1;          
}
