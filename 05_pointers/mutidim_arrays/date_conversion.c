// date_conversion.c
#include <stdlib.h>
#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


/**
 * day_of_year: set day of year from month & day
 */
int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}


/**
 * month_day: set month, day from day of year
 */
void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;

    leap = year % 4 == 00 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

/**
 * daytab is the first two-dimensional array we have dealt with. In C, a two-dimensional array is
 * really a one-dimensional array, each of whose elements is an array. Hence subscripts are
 * written as
 *      daytab[i][j]
 * rather than
 *      daytab[i, j]
 * 
 * An array is initialized by a list of initializers in braces; each row of a two-dimensional array is
 * initialized by a corresponding sub-list. We started the array daytab with a column of zero so
 * that month numbers can run from the natural 1 to 12 instead of 0 to 11. Since space is not at a
 * premium here, this is clearer than adjusting the indices.
 * 
 * If a two-dimensional array is to be passed to a function, the parameter declaration in the
 * function must include the number of columns; the number of rows is irrelevant, since what is
 * passed is, as before, a pointer to an array of rows, where each row is an array of 13 int s. In
 * this particular case, it is a pointer to objects that are arrays of 13 int s. Thus if the array
 * daytab is to be passed to a function f , the declaration of f would be:
 *      f(int daytab[2][13]) { . . . }
 * It could also be
 *      int daytab[][13]) { . . . }
 * which says that the parameter is a pointer to an array of 13 integers. The parentheses
 * are necessary since brackets [] have higher precedence than *. Without parentheses,
 * the declaration
 *      int *daytab[13]
 * is an array of 13 pointers to integers. More generally, only the first dimension
 * (subscript) of an array is free; all the others have to be specified.
 */
