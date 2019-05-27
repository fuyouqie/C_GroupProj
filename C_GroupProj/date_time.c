#include "date_time.h"
#include <stdio.h>
#include <stdlib.h>

date_time_t* construct_date_time()
{
	date_time_t* date_time = malloc(sizeof(date_time_t));
	date_time->month = 0;
	date_time->day = 0;
	date_time->hour = 0;
	date_time->minute = 0;

	return date_time;
}

date_time_t* construct_date_time_overload1(int month, int day, int hour, int minute)
{
	date_time_t* date_time = malloc(sizeof(date_time_t));
	date_time->month = month;
	date_time->day = day;
	date_time->hour = hour;
	date_time->minute = minute;

	return date_time;
}

void destruct_date_time(date_time_t* date_time)
{
	free(date_time);
}

void set_date_time_(date_time_t* date_time, int month, int day, int hour, int minute)
{
	set_month(date_time, month);
	set_day(date_time, day);
	set_hour(date_time, hour);
	set_minute(date_time, minute);
}

int get_month(date_time_t* date_time)
{
	return date_time->month;
}

int get_day(date_time_t* date_time)
{
	return date_time->day;
}

int get_hour(date_time_t* date_time)
{
	return date_time->hour;
}

int get_minute(date_time_t* date_time)
{
	return date_time->minute;
}

void set_month(date_time_t* date_time, int month)
{
	date_time->month = month;
}

void set_day(date_time_t* date_time, int day)
{
	date_time->day = day;
}

void set_hour(date_time_t* date_time, int hour)
{
	date_time->hour = hour;
}

void set_minute(date_time_t* date_time, int minute)
{
	date_time->minute = minute;
}

void print_date_time(date_time_t* date_time)
{
	printf("%02d-%02d %02d:%02d\n", date_time->month, date_time->day, date_time->hour, date_time->minute);
}