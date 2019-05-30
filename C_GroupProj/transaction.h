#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "date_time.h"
#include "client.h"

#define TRANSACTION_ID_LEN 6
#define TRANSACTION_DB "transaction_db.txt"

typedef struct transaction
{
	char transaction_id[TRANSACTION_ID_LEN + 1];
	char sender_id[CLIENT_ID_LEN + 1];
	char receiver_id[CLIENT_ID_LEN + 1];
	double amount;
	date_time_t* date_time;
}
transaction_t;

transaction_t* construct_transaction(void);
transaction_t* construct_transaction_overload1(char*, char*, char*, double, date_time_t*);
void destruct_transaction(transaction_t*);
void set_transaction(transaction_t*, char*, char*, char*, double, date_time_t*);
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
void print_transaction(transaction_t*);