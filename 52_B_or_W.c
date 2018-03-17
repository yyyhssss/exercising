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
