#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum
months{NOT_MONTH, Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec}
month;

void invalid_month(int, enum months);
void next_day(int, enum months);
static int days_in_months[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static char *month_out[] = {"invalid", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", 
"Sep", "Oct", "Nov", "Dec"};
enum months translate(char *);

void main()
{
    int day;
    char mon[10];
    printf("\nEnter a date (Format: 2 Feb): ");
    scanf("%d %s", &day, mon);
    month = translate(mon);
    invalid_month(day, month);
    next_day(day, month);
}

enum months translate(char *m)
{
    if(strcmp(m, "Jan") == 0)
        return Jan;
    if(strcmp(m, "Feb") == 0)
        return Feb;
    if(strcmp(m, "Mar") == 0)
        return Mar;
    if(strcmp(m, "Apr") == 0)
        return Apr;
    if(strcmp(m, "May") == 0)
        return May;
    if(strcmp(m, "Jun") == 0)
        return Jun;
    if(strcmp(m, "Jul") == 0)
        return Jul;
    if(strcmp(m, "Aug") == 0)
        return Aug;
    if(strcmp(m, "Sep") == 0)
        return Sep;
    if(strcmp(m, "Oct") == 0)
        return Oct;
    if(strcmp(m, "Nov") == 0)
        return Nov;
    if(strcmp(m, "Dec") == 0)
        return Dec;
}

void invalid_month(int day, enum months month_in)
{
    if((month_in == NOT_MONTH) || day < 1 || day > days_in_months[month])
    {
        printf("\nInvalid Input %d %s", day, month_out[month_in]);
        exit(-1);
    }
}

void next_day(int day, enum months month_in)
{
    if(day < days_in_months[month_in])
        printf("\nTomorrow is %d %s\n", day + 1, month_out[month_in]);

    else if(day == days_in_months[month_in] && (strcmp(month_out[month_in], "Dec") != 0))
        printf("\nTomorrow is 1 %s\n", month_out[month_in + 1]);
    else
        printf("\nTomorrow is 1 Jan\n");
}