#include <stdio.h>

int a[7];
char b[7]="AABCDEF";
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
    if(n==6)
    {
      if(a[1]+a[2]>=1 &&
	  a[1]+a[4]<=1 &&
	  a[1]+a[5]+a[6]>=2 &&
	  a[2]==a[3] &&
	  a[3]!=a[4] &&
	  (a[4]==a[5] || a[4]==1) )
	print_result();
    }
    else search(n+1);
  }
}

void print_result()
{
  int i;
  total++;
  printf("Possibility %d:", total);
  for(i=1;i<=6;i++)
  {
    if(a[i]==1) printf("%c ", b[i]);
  }
  printf("\n");
}
