#include <stdio.h>

int a[15];
char b[14][3]={" 0"," A"," 2"," 3"," 4"," 5"," 6"," 7"," 8"," 9","10"," J"," Q"," K"};

int swap(int n);
void print_result();

int main()
{
  int i;
  for(i=13;i>0;i--)
  {
    a[i]=i;
    swap(i);
  }
  print_result();
}

int swap(int n)
{
  int i,j,temp;
  for(i=1;i<n;i++)
  {
    temp=a[13];
    for(j=13;j>n;j--)
      a[j]=a[j-1];
    a[n]=temp;
  }
  return(0);
}

void print_result()
{
  int i;
  printf("Sequence of poker is:");
  for(i=1;i<=13;i++)
    printf(" %s", b[a[i]]);
  printf("\n");
}
