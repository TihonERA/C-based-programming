#include <assert.h>
#include <stdio.h>
char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int _get_year_type(int year) {
  return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int validate_days_in_year(int leap, int day) {
  return (leap && day <= 366) || (!leap && day <= 365);
}

int validate_month(int month) {
  if (month > 12) {
    printf("error: month input is too high\n");
    return 0;
  } else if (month < 0) {
    printf("error: month input is too low\n");
    return 0;
  }
  return 1;
}

int day_of_year(int year, int month, int day) {
  char *searching_year, *p;
  int leap;

  if (year < 0 || month < 0 || day < 0) {
    printf("error: dates cant be negative\n");
    return -1;
  }
  if (!validate_month(month))
    return -1;

  leap = _get_year_type(year);

  if (!validate_days_in_year(leap, day)) {
    printf("error: day input is too high\n");
    return -1;
  }

  searching_year = *(daytab + leap);
  for (p = searching_year + 1; (p - searching_year) < month; p++)
    day += *p;

  return day;
}

void month_day(int year, int year_day, int *pmonth, int *pday) {
  int i, leap;
  char *searching_year, *p;

  if (year < 0 || year_day < 0) {
    printf("error: dates cant be negative\n");
    return;
  }

  leap = _get_year_type(year);

  if (!validate_days_in_year(leap, year_day)) {
    printf("error: day input is too high\n");
    return;
  }

  searching_year = *(daytab + leap);
  for (p = searching_year; year_day > *p; p++)
    year_day -= *p;

  *pmonth = p - searching_year;
  *pday = year_day;
}

int main() {
  int month, day;
  month_day(2008, 305, &month, &day);
  printf("%d\t%d\n", month, day);
}
