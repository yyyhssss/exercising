//医院有A、B、C、D、E、F、G七位医生，在一星期内（星期一至星期天）第人轮流值班一天。现已知：
//A比C晚一天；
//D比E晚两天；
//B比G早三天；
//F在B和C中间，且是星期四；
//请确定每天是哪位大夫值班？

#include <stdio.h>

#define N 7

int a[N+1];
char b[N+1]="AABCDEFG";
char c[8][10]={"","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
int d[N+1];
int total=0;

int search(int n);
void print_result();

int main()
{
  int i;
  search(1);
  return(0);
}

int search(int n)
{
  int i,j;
  for(i=1;i<=N;i++)             //i为星期几
  {
    if(!d[i])
    {
      a[n]=i;
      d[i]=1;
    }
    else continue;

    if(n==N)
    {
      if(a[6]==4 &&
	 ((a[1]-a[3])==1 || (a[3]-a[1])==6) && 
	 ((a[4]-a[5])==2 || (a[5]-a[4])==5) && 
	 ((a[7]-a[2])==3 || (a[2]-a[7])==4) /*&&
	 ((a[2]<4&&a[3]>4)||(a[2]>4&&a[3]<4))*/)
	print_result();
    }
    else search(n+1);
    d[i]=0;
  }
}

void print_result()
{
  int i;
  total++;
  printf("Possibility %d:\n", total);
  for(i=1;i<=N;i++)
    printf("%c is %s\n", b[i],c[a[i]]);
  printf("\n");
}
