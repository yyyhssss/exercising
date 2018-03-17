//A、B、C、D、E五人，每人额头上贴了一张或黑或白的约。五人对坐，每人都可以看到其他人额头上的纸的颜色，但都不知道自己额头上的纸的颜色。五人相互观察后，
//A说：我看见有三人额头上贴的是白纸，一人额头上贴的是黑纸；
//B说：我看见其他四人额头上贴的都是黑纸；
//C说：我看见有一个额头上贴的是白纸，其他人额头上贴的都是黑纸；
//D说：我看见四人额头上贴的都是白纸；
//E什么也没说
//现已知额头上贴黑纸的人说的都是谎话，额头上贴白纸的人说的都是真话。请问谁的额头上贴的是白纸，谁的额头上贴的是黑纸？

#include <stdio.h>

int a[6];
char b[7]="AABCDEF";
char c[2][6]={"Black","White"};
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
  int i;
  for(i=0;i<=1;i++)
  {
    a[n]=i;
    if(n==5)
    {
      if(((a[1]==1&&a[2]+a[3]+a[4]+a[5]==3)||(a[1]==0&&a[2]+a[3]+a[4]+a[5]!=3)) &&
	  ((a[2]==1&&a[1]+a[3]+a[4]+a[5]==0)||(a[2]==0&&a[1]+a[3]+a[4]+a[5]!=0)) &&
	  ((a[3]==1&&a[1]+a[2]+a[4]+a[5]==1)||(a[3]==0&&a[1]+a[2]+a[4]+a[5]!=1)) &&
	  ((a[4]==1&&a[1]+a[2]+a[3]+a[5]==4)||(a[4]==0&&a[1]+a[2]+a[3]+a[5]!=4)) )
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
  for(i=1;i<=5;i++)
    printf("%c is %s\n", b[i],c[a[i]]);
  printf("\n");
}
