#include <stdio.h>
#include <math.h>

int number[210][5];         //所有可逆素数,第一列存该素数，后面4位为分解后数字
int first[105];            //存储可放在第一行及第四行的素数的下标
int a[4];            //素数幻方，第一列为素数下标

int count=0;                //number下标
int firstcount=0;          //select下标
int llnum;                 //列方向组成的数
int llnumii,llnumij;       //对角线方向组成的数

int prime(int n);           //检验是否为素数
int re_prime(int n);        //检验是否为可逆素数
int process(int n);         //向number中填写数字
int comp(int n);             //与number中素数比较，检验是否为可逆素数

int main()
{
  int i,j,k,flag1,flag2,flag3;
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
    a[0]=first[i];
    for(a[1]=0;a[1]<count;a[1]++)
    {
      flag1=1;
      for(k=1;k<=4;k++)
      {
        llnum=number[a[0]][k]*10+number[a[1]][k];
        if(!comp(llnum))        //列方向无法构成可逆素数
        {
          flag1=0;
          break;                //跳出k循环
        }
      }
      if(flag1)
      {
        llnumii=number[a[0]][1]*10+number[a[1]][2];
        llnumij=number[a[0]][4]*10+number[a[1]][3];
        if((!comp(llnumii)) || (!comp(llnumij)))  {flag1=0;}        //对角线方向无法构成可逆素数
      }
      if(flag1)
      {
        for(a[2]=0;a[2]<count;a[2]++)
        {
          flag2=1;
          for(k=1;k<=4;k++)
          {
            llnum=number[a[0]][k]*100+number[a[1]][k]*10+number[a[2]][k];
            if(!comp(llnum))
            {
              flag2=0;
              break;
            }
          }
          if(flag2)
          {
            llnumii=number[a[0]][1]*100+number[a[1]][2]*10+number[a[2]][3];
            llnumij=number[a[0]][4]*100+number[a[1]][3]*10+number[a[2]][2];
            if((!comp(llnumii)) || (!comp(llnumij)))  flag2=0;
          }
          if(flag2) 
	        {
            for(j=0;j<firstcount;j++)
            {
              flag3=1;
              a[3]=first[j];
              for(k=1;k<=4;k++)
              {
                llnum=number[a[0]][k]*1000+number[a[1]][k]*100+number[a[2]][k]*10+number[a[3]][k];
                if(!comp(llnum))
                {
                  flag3=0;
                  break;
                }
              }
              if(flag3)
              {
                llnumii=number[a[0]][1]*1000+number[a[1]][2]*100+number[a[2]][3]*10+number[a[3]][4];
                llnumij=number[a[0]][4]*1000+number[a[1]][3]*100+number[a[2]][2]*10+number[a[3]][1];
                if((!comp(llnumii)) || (!comp(llnumij)))  flag3=0;
              }
              if(flag3) 
              {
                total++;
                printf("No. %d: %d %d %d %d\n", total,number[a[0]][0],number[a[1]][0],number[a[2]][0],number[a[3]][0]);
              }
            }
	        }
        }
      }
      
   // printf("Line 1:%d, line 2:%d, line 3:%d\n", number[a[0]][0],number[a[1]][0],number[a[2]][0]);
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
    if(n==(number[i][0]/k)) return(1);
  }
  return(0);
}
