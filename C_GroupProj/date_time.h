#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MONTH_START 1
#define MONTH_END 12
#define DAY_START 1
#define DAY_END 31
#define HOUR_START 0
#define HOUR_END 23
#define MINUTE_START 0
#define MINUTE_END 59

struct date_time
{
	int month;
	int day;
	int hour;
	int minute;
};
typedef struct date_time date_time_t;

date_time_t* construct_date_time(void);
date_time_t* construct_date_time_overload1(int, int, int, int);
void destruct_date_time(date_time_t*);
void set_date_time_(date_time_t*, int, int, int, int);
int get_month(date_time_t*);
int get_day(date_time_t*);
int get_hour(date_time_t*);
int get_minute(date_time_t*);
void set_month(date_time_t*, int);
void set_day(date_time_t*, int);
void set_hour(date_time_t*, int);
void set_minute(date_time_t*, int);
void print_date_time(date_time_t*);

