//两面族：真一句假一句且真假交替，但第一句是真是假没有规律
//博士遇到三人，分别来自三个不同的种族：说谎族，诚实族，两面族
//博士问左边的人：中间的人是什么族？	左边的人回答：诚实族
//博士问中间的人：中间的人是什么族？	中间的人回答：两面族
//博士问右边的人：中间的人是什么族？	右边的人回答：说谎族
//问三人各是哪个族的？

#include <stdio.h>

int a[4];
char b[7]="AABCDEF";
char c[3][7]={"Lier","Honest","Double"};
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
  int i,j,flag;
  for(i=0;i<=2;i++)             //说谎族为0，诚实族为1，两面族为2
  {
    flag=0;
    a[n]=i;
    for(j=n-1;j>=1;j--)
      if(a[n]==a[j])
      {
	flag=1;
	break;
      }
    if(flag)	continue;
    if(n==3)
    {
      if(((!a[1]&&a[2]!=1)||(a[1]==1&&a[2]==1)||(a[1]==2)) &&
	  ((!a[2]&&a[2]!=2)||(a[2]==1&&a[2]==2)||(a[2]==2)) &&
	  ((!a[3]&&a[2]!=0)||(a[3]==1&&a[2]==0)||(a[3]==2)) )
	print_result();
    }
    else search(n+1);
  }
}

void print_result()
{
  int i;
  total++;
  printf("Possibility %d:\n", total);
  for(i=1;i<=3;i++)
    printf("%c is %s\n", b[i],c[a[i]]);
  printf("\n");
}
