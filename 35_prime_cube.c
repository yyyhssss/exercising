#include <stdio.h>
#include <math.h>

int number[210][5];         //所有可逆素数,第一列存该素数，后面4位为分解后数字
int first[105];            //存储可放在第一行及第四行的素数的下标
int array[4][5];            //素数幻方，第一列为素数下标

int count=0;                //number下标
int firstcount=0;          //select下标
int llnum;                  //前两行组成的列方向的两位数
int lllnum;                 //前三行组成的列方向的三位数

int prime(int n);           //检验是否为素数
int re_prime(int n);        //检验是否为可逆素数
int process(int n);         //向number中填写数字
int comp(int n);             //与number中素数比较，检验是否为可逆素数

int main()
{
int i,j,k,flag;
for(i=1001;i<10000;i++)
  {
  k=i/1000;
  if(k%2!=0 && i%5!=0 && re_prime(i))
    {
    number[count][0]=i;
    process(count);
    if(number[count][2]%2!=0
      && number[count][3]%2!=0
      && number[count][2]!=5
      && number[count][3]!=5)
      {first[firstcount++]=count;}
    count++;
    }
  }
for(i=0;i<firstcount;i++)
  {
  a[0]=first[i];
  for(j=0,flag=1;j<count;j++)
    {
    for(k=1;k<=4;k++)
      {
      llnum=number[a[0]][k]*10+number[j][k];
      if(!comp(llnum)) 
        {
        flag=0;
        break;
        }
      }
    printf("Line 1:%d, line 2:%d\n", number[a[0]][0],number[a[1]][0]);
    }
  }
//for(i=0;i<count;i++)
//  {printf((i+1)%8 ? "%d:%d %d %d %d  ":"%d:%d %d %d %d\n", number[i][0],number[i][1],number[i][2],number[i][3],number[i][4]);}
return(0);
}

int prime(int n)
{
int i;
if(n==2 || n==3)  return(1);
for(i=2;i<=n/2;i++)
  {
  if(n%i==0) return(0);
  }
return(1);
}

int re_prime(int n)
{
int i,m=0,temp;
temp=n;
for(i=1000;i>=1;i/=10)
  {
  m+=temp%10*i;
  temp/=10;
  }
if(prime(n) && prime(m))  return(1);
return(0);
}

int process(int n)
{
int i,temp;
for(temp=number[n][0],i=4; i>=1; temp/=10,i--)
  {
  number[n][i]=temp%10;
  }
return(0);
}

int comp(int n)
{
int i,k;
for(k=1000;n/k==0;k/=10);
k=1000/k;
for(i=0;i<count;i++)
  {
  if(n==number[i][0]/k) return(1);
  }
return(0);
}
