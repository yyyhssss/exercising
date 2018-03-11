#include <time.h>
#include <stdio.h>

#define N 18

int b[N+1]={0,1};
int total=0;
int a[N+1]={0,1};
void search(int t);
void print();
int pd(int,int);
int main()
{
    time_t start,end;
    double cost=0;
    time(&start);
    search(2);
    time(&end);
    cost=difftime(end,start);
    printf("cost is %f\n",cost);
    return 0;
} 
void search( int t )
{
    int i;
    for (i=1;i<(N+1);i++)
    {
        if (pd(a[t-1],i)&&(!b[i]))// 原来是i-1,实际是t-1
        {
            a[t]=i;
            b[i]=1;
            if(t==N)  
            {
                if (pd(a[N],a[1])&&a[N]>a[2]) 
                {
                    print();
                }
            }
            else
            {
                search(t+1);
            }
            b[i]=0;
        }
    }
}
void print()
{
    total++;
    //cout<<"<"<<total<<">";
    //for (int j=1;j<=N;j++)
    //{
    //    cout<<a[j]<<" ";
    //}
 
    //cout<<endl;
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
