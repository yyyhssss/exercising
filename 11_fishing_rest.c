#include <stdio.h>

struct date
{
int year, month,day;
};

int days(date day)
{
static int day_tab[2][13]=
  {{0,31,28,31,30,31,30,31,31,30,31,30,31},
   {0,31,29,31,30,31,30,31,31,30,31,30,31}};
int i,lp;
lp= (day.year%4==0) && (day.year%100!=0) || (day.year%400==0);
for(i=1; i<day.month; i++)
  {day.day+=day_tab[lp][i];}
return(day.day);
}


int main()
{
struct date, today;
int yerterday, day;
printf("Enter year/month/day:")
scanf("%d/%d/%d", &today.year, &today.month, &today.day);
yesterday=0;

yesterday+=(today.year-1990)/4*(365*3+366);

if((today.year-1990)%4==3) yesterday+=365*2+366;
else yesterday+=(today.year-1990)%4*365;

yesterday+=days(today);

day=yesterday%5;
if(day>0 && day<=3) printf("He was fishing at that day.\n");
else printf("He was sleeping at that day.\n");
}
