#include "transaction.h"
#include "date_time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

transaction_t* construct_transaction()
{
	transaction_t* transaction = malloc(sizeof(transaction_t));
	transaction->amount = 0.0;
	transaction->date_time = NULL;

	return transaction;
}

transaction_t* construct_transaction_overload1(char* transaction_id, char* sender_id, char* receiver_id, double amount, date_time_t* date_time)
{
	transaction_t* transaction = malloc(sizeof(transaction_t));
	strcpy(transaction->transaction_id, transaction_id);
	strcpy(transaction->sender_id, sender_id);
	strcpy(transaction->receiver_id, receiver_id);
	transaction->amount = amount;
	transaction->date_time = construct_date_time_overload1(date_time->month, date_time->day, date_time->hour, date_time->minute);

	return transaction;
}

char* get_transaction_id(transaction_t* transaction)
{
	return transaction->transaction_id;
}

char* get_sender_id(transaction_t* transaction)
{
	return transaction->sender_id;
}

char* get_receiver_id(transaction_t* transaction)
{
	return transaction->receiver_id;
}

double get_amount(transaction_t* transaction)
{
	return transaction->amount;
}

date_time_t* get_date_time(transaction_t* transaction)
{
	return transaction->date_time;
}

void set_transaction_id(transaction_t* transaction, char* transaction_id)
{
	strcpy(transaction->transaction_id, transaction_id);
}

void set_sender_id(transaction_t* transaction, char* sender_id)
{
	strcpy(transaction->sender_id, sender_id);
}

void set_receiver_id(transaction_t* transaction, char* receiver_id)
{
	strcpy(transaction->receiver_id, receiver_id);
}

void set_amount(transaction_t* transaction, double amount)
{
	transaction->amount = amount;
}

void set_date_time(transaction_t* transaction, date_time_t* date_time)
{
	transaction->date_time = construct_date_time_overload1(date_time->month, date_time->day, date_time->hour, date_time->minute);
}