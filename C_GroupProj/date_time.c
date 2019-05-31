#include "date_time.h"
#include <stdio.h>
#include <stdlib.h>

/**************************************************************************
*  This function is used to dynamicly allocate the memory of struct date_time 
*  initialize each member of date_time struct and return the struct.                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - void                                                                     
*   outputs:                                                              
* - date_time_t*                                                          
**************************************************************************/
date_time_t* construct_date_time(void)
{
	date_time_t* date_time = malloc(sizeof(date_time_t));
	date_time->month = 0;
	date_time->day = 0;
	date_time->hour = 0;
	date_time->minute = 0;

	return date_time;
}

/**************************************************************************
* This function is used to giving value to each member of the date_time struct                                                                      
* base on the input value.                                                                        
*                                                                         
*   inputs:                                                               
* - int month, int day, int hour, int minute                              
*   outputs:                                                              
* - date_time_t*                                                          
**************************************************************************/
date_time_t* construct_date_time_overload1(int month, int day, int hour, int minute)
{
	date_time_t* date_time = malloc(sizeof(date_time_t));
	date_time->month = month;
	date_time->day = day;
	date_time->hour = hour;
	date_time->minute = minute;

	return date_time;
}

/**************************************************************************
*  This function is used to free the memory that been allocate to struct 
*  date_time.                                                          
*                                                                         
*                                                                         
*   inputs:                                                               
* - date_time_t* date_time                                                
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void destruct_date_time(date_time_t* date_time)
{
	free(date_time);
}

/**************************************************************************
*  This function is used to set the value of each member of the struct                                                                       
*                                                                         
*                                                                         
*   inputs:                                                               
* - date_time_t* date_time, int month, int day, int hour, int minute      
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void set_date_time_(date_time_t* date_time, int month, int day, int hour, int minute)
{
	set_month(date_time, month);
	set_day(date_time, day);
	set_hour(date_time, hour);
	set_minute(date_time, minute);
}

/**************************************************************************
*  This function is used to get the value of member month of the struct
*
*
*   inputs:
* - date_time_t* date_time
*   outputs:
* - int
**************************************************************************/
int get_month(date_time_t* date_time)
{
	return date_time->month;
}

/**************************************************************************
*  This function is used to get the value of member day of the struct
*
*
*   inputs:
* - date_time_t* date_time
*   outputs:
* - int
**************************************************************************/
int get_day(date_time_t* date_time)
{
	return date_time->day;
}

/**************************************************************************
*  This function is used to get the value of member hour of the struct
*
*
*   inputs:
* - date_time_t* date_time
*   outputs:
* - int
**************************************************************************/
int get_hour(date_time_t* date_time)
{
	return date_time->hour;
}

/**************************************************************************
*  This function is used to get the value of member minute of the struct
*
*
*   inputs:
* - date_time_t* date_time
*   outputs:
* - int
**************************************************************************/
int get_minute(date_time_t* date_time)
{
	return date_time->minute;
}

/**************************************************************************
*  This function is used to set the value of member month of the struct
*
*
*   inputs:
* - date_time_t* date_time, int month
*   outputs:
* - void 
**************************************************************************/
void set_month(date_time_t* date_time, int month)
{
	date_time->month = month;
}

/**************************************************************************
*  This function is used to set the value of member day of the struct
*
*
*   inputs:
* - date_time_t* date_time, int day
*   outputs:
* - void
**************************************************************************/
void set_day(date_time_t* date_time, int day)
{
	date_time->day = day;
}

/**************************************************************************
*  This function is used to set the value of member hour of the struct
*
*
*   inputs:
* - date_time_t* date_time, int hour
*   outputs:
* - void
**************************************************************************/
void set_hour(date_time_t* date_time, int hour)
{
	date_time->hour = hour;
}

/**************************************************************************
*  This function is used to set the value of member minute of the struct
*
*
*   inputs:
* - date_time_t* date_time, int minute
*   outputs:
* - void
**************************************************************************/
void set_minute(date_time_t* date_time, int minute)
{
	date_time->minute = minute;
}

/**************************************************************************
*  This function is used to print the value of all members of the struct
*
*
*   inputs:
* - date_time_t* date_time
*   outputs:
* - void
**************************************************************************/
void print_date_time(date_time_t* date_time)
{
	printf("%02d-%02d %02d:%02d\n", date_time->month, date_time->day, date_time->hour, date_time->minute);
}