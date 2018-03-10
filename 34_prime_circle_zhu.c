#include<cstdio> 
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
bool b[21]={0,1};
int total=0;
int a[21]={0,1};
void search(int t);
void print();
bool pd(int,int);
int main()
{
    search(2);
    cout<<total;
    getchar();
    return 0;
} 
void search( int t )
{
    int i;
    for (i=1;i<11;i++)
    {
        if (pd(a[t-1],i)&&(!b[i]))// 原来是i-1,实际是t-1
        {
            a[t]=i;
            b[i]=1;
            if(t==10)  
            {
                if (pd(a[10],a[1])) 
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
    cout<<"<"<<total<<">";
    for (int j=1;j<=10;j++)
    {
        cout<<a[j]<<" ";
    }
 
    cout<<endl;
}
bool pd(int x,int y)
{
    int i=x+y;
    for (int k=2;k*k<=i;k++)
    {
        if(i%k== 0)
        {
            return false;
        }
    }
 
    return true;          
}
