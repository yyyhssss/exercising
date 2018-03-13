#include <stdio.h>
#include <math.h>

int number[210][5];         //所有可逆素数,第一列存该素数，后面4位为分解后数字
int first[105];            //存储可放在第一行及第四行的素数的下标
int a[5];            //素数幻方，第一列为素数下标

int count=0;                //number下标
int firstcount=0;          //select下标

int reverse(int n);         //求逆序数
int prime(int n);           //检验是否为素数
int re_prime(int n);        //检验是否为可逆素数
int process(int n);         //向number中填写数字
int colnum(int i, int n);   //取第i列的n位数
int compnum(int n);         //与number中素数比较，检验是否为可逆素数
int comparray(int n);            //比较前n行是否能构成可逆素数

int main()
{
  int i,j,k;
  int total=0;
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
    a[1]=first[i];
    if(number[a[1]][1]>number[a[1]][4]) continue;           //左上角<=右上角
    for(a[2]=0;a[2]<count;a[2]++)
    {
      if(comparray(2))
      {
        for(a[3]=0;a[3]<count;a[3]++)
        {
          if(comparray(3)) 
          {
            for(j=i+1;j<firstcount;j++)
            {
              a[4]=first[j];

	      if(number[a[4]][1]<=number[a[1]][1]             //左上角<=左下角
	        || colnum(1,4)<number[a[1]][0]                //第一列>第一行
	        || (colnum(1,4)==number[a[1]][0] && colnum(2,4)<number[a[2]][0])           //第一列＝第一行并且第二列>第二行
	        || reverse(number[a[4]][0])<number[a[1]][0]              //第四行反序>第一行
	        || (reverse(number[a[4]][0])==number[a[1]][0] && reverse(number[a[3]][0])<number[a[2]][0]) )    //第三行反序>第二行
		continue;

              if(comparray(4)) 
              {
		
                total++;
                //printf("No. %d\n%d\n%d\n%d\n%d\n", total,number[a[1]][0],number[a[2]][0],number[a[3]][0],number[a[4]][0]);
                printf("No. %2d: %d  %d  %d  %d\n", total,number[a[1]][0],number[a[2]][0],number[a[3]][0],number[a[4]][0]);
              }
            }
	  }
        }
      }
    }
  }
//for(i=0;i<count;i++)
//  {printf((i+1)%8 ? "%d:%d %d %d %d  ":"%d:%d %d %d %d\n", number[i][0],number[i][1],number[i][2],number[i][3],number[i][4]);}
return(0);
}

int reverse(int n)
{
  int i,m=0;
  for(i=1000;i>=1;i/=10)
  {
    m+=n%10*i;
    n/=10;
  }
  return m;
}

int prime(int n)                   //检验是否为素数
{
  int i;
  if(n==2 || n==3)  return(1);
  for(i=2;i<=n/2;i++)
  {
    if(n%i==0) return(0);
  }
  return(1);
}

int re_prime(int n)            //检验是否为可逆素数
{
  int m;
  m=reverse(n);
  if(prime(n) && prime(m))  return(1);
  return(0);
}

int process(int n)           //向number中填写数字
{
  int i,temp;
  for(temp=number[n][0],i=4; i>=1; temp/=10,i--)
  {
    number[n][i]=temp%10;
  }
  return(0);
}

int compnum(int n)           //与number中素数比较，检验是否为可逆素数
{
  int i,k;
  for(k=1000;n/k==0;k/=10);
  k=1000/k;
  for(i=0;i<count;i++)
  {
    if(n==(number[i][0]/k)) return(1);
  }
  return(0);
}

int colnum(int i, int n)           //取第i列的n位数
{
  int k,num=0;
  for(k=1;k<=n;k++)
    num=10*num+number[a[k]][i];
  return num;
}

int comparray(int n)        //比较前n行是否能构成可逆素数
{
  int i,k,llnumii=0,llnumij=0;
  for(i=1;i<=4;i++)
  {
    if(!compnum(colnum(i,n))) return(0);      //判断列方向能否构成可逆素数

//    if(i==1)                                   //第一列>=第一行
//    {
//      for(k=4-n;k>0;k--)
//        llnum*=10;
//      if(llnum<number[a[1]][0]) return(0);
//    }
  }

  for(k=1;k<=n;k++)
    llnumii=10*llnumii+number[a[k]][k];
  if(!compnum(llnumii)) return(0);            //判断正对角方向能否构成可逆素数

  for(k=1;k<=n;k++)
    llnumij=10*llnumij+number[a[k]][5-k];
  if(!compnum(llnumij)) return(0);           //判断反对角方向能否构成可逆素数
  
  return(1);
}
