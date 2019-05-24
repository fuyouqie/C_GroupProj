#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date_time.h"

#define MAX_CLIENT_ID_LEN 8
#define MAX_TRANS_ID_LEN 6
#define MONTH_START 1
#define MONTH_END 12
#define DAY_START 1
#define DAY_END 31
#define HOUR_START 0
#define HOUR_END 23
#define MINUTE_START 0
#define MINUTE_END 59

typedef struct transaction
{
	char transaction_id[MAX_TRANS_ID_LEN + 1];
	char sender_id[MAX_CLIENT_ID_LEN + 1];
	char receiver_id[MAX_CLIENT_ID_LEN + 1];
	double amount;
	date_time_t* date_time;
}
transaction_t;

transaction_t* construct_transaction(void);
transaction_t* construct_transaction_overload1(char*, char*, char*, double, date_time_t*);
char* get_transaction_id(transaction_t*);
char* get_sender_id(transaction_t*);
char* get_receiver_id(transaction_t*);
double get_amount(transaction_t*);
date_time_t* get_date_time(transaction_t*);
void set_transaction_id(transaction_t*, char*);
void set_sender_id(transaction_t*, char*);
void set_receiver_id(transaction_t*, char*);
void set_amount(transaction_t*, double);
void set_date_time(transaction_t*, date_time_t*);