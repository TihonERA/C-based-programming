#include <stdio.h>
char daytab[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                      {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int _get_year_type(int year) {
  return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int validate_days_in_year(int leap, int day) {
  return (leap && day <= 366) || (!leap && day <= 365);
}

int day_of_year(int year, int month, int day) {
  if (year < 0 || month < 0 || day < 0) {
    printf("error: dates cant be negative\n");
    return -1;
  }
  if (month > 12) {
    printf("error: month input is too high");
    return -1;
  }
  int leap = _get_year_type(year);
  if (!validate_days_in_year(leap, day)) {
    printf("error: day input is too high\n");
  }
  for (int i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}

void month_day(int year, int year_day, int *pmonth, int *pday) {
  if (year < 0 || year_day < 0) {
    printf("error: dates cant be negative\n");
    return;
  }
  int i, leap = _get_year_type(year);

  if (!validate_days_in_year(leap, year_day)) {
    printf("error: day input is too high\n");
    return;
  }
  for (i = 1; year_day > daytab[leap][i]; i++) {
    year_day -= daytab[leap][i];
  }
  *pmonth = i;
  *pday = year_day;
}
