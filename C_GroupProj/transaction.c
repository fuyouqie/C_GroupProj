#include "transaction.h"
#include "date_time.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************************************
* This function is used to allocate memory of the struct dynamically, and 
* initial the value of struct transaction
*
*
*   inputs:
* - none
*   outputs:
* - transaction_t*
**************************************************************************/
transaction_t* construct_transaction()
{
	transaction_t* transaction = malloc(sizeof(transaction_t));
	transaction->amount = 0.0;
	transaction->date_time = NULL;

	return transaction;
}

/**************************************************************************
* This function is used to set the value of each member of transaction
* in struct transaction
*
*
*   inputs:
* - char* transaction_id, char* sender_id, char* receiver_id, double amount, 
*   date_time_t* date_time
*   outputs:
* - transaction_t*
**************************************************************************/
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

/**************************************************************************
* This function is used to set free the memory that has been allocated to 
* struct transaction
*
*
*   inputs:
* - transaction_t* transaction
*   outputs:
* - none
**************************************************************************/
void destruct_transaction(transaction_t* transaction)
{
	destruct_date_time(transaction->date_time);
	free(transaction);
}

/**************************************************************************
* This function is used to set the value of each member of struct transaction
* base on the input value
*
*   inputs:
* - transaction_t* transaction, char* transaction_id, char* sender_id, 
*   char* receiver_id, double amount, date_time_t* date_time
*   outputs:
* - none
**************************************************************************/
void set_transaction(transaction_t* transaction, char* transaction_id, char* sender_id, char* receiver_id, double amount, date_time_t* date_time)
{
	set_transaction_id(transaction, transaction_id);
	set_sender_id(transaction, sender_id);
	set_receiver_id(transaction, receiver_id);
	set_amount(transaction, amount);
	set_date_time(transaction, date_time);
}

/**************************************************************************
* This function is used to see if the transaction ID of that particular
* accout is the same as stored in the database
*
*   inputs:
* - transaction_t* transaction, char* id
*   outputs:
* - int
**************************************************************************/
int matches_transaction_id(transaction_t* transaction, char* id)
{
	if (strcmp(transaction->transaction_id, id) == 0)
		return 1;

	return 0;
}

/**************************************************************************
* This function is used to get the value of transaction id
*
*   inputs:
* - transaction_t* transaction
*   outputs:
* - char*
**************************************************************************/
char* get_transaction_id(transaction_t* transaction)
{
	return transaction->transaction_id;
}

/**************************************************************************
* This function is used to get the value of sender_id
*
*   inputs:
* - transaction_t* transaction
*   outputs:
* - char*
**************************************************************************/
char* get_sender_id(transaction_t* transaction)
{
	return transaction->sender_id;
}

/**************************************************************************
* This function is used to get the value of receiver_id
*
*   inputs:
* - transaction_t* transaction
*   outputs:
* - char*
**************************************************************************/
char* get_receiver_id(transaction_t* transaction)
{
	return transaction->receiver_id;
}

/**************************************************************************
* This function is used to get the value of amount
*
*   inputs:
* - transaction_t* transaction
*   outputs:
* - double
**************************************************************************/
double get_amount(transaction_t* transaction)
{
	return transaction->amount;
}

/**************************************************************************
* This function is used to get the value of date_time
*
*   inputs:
* - transaction_t* transaction
*   outputs:
* - date_time_t*
**************************************************************************/
date_time_t* get_date_time(transaction_t* transaction)
{
	return transaction->date_time;
}

/**************************************************************************
* This function is used to set the value of transaction_id
*
*   inputs:
* - transaction_t* transaction, char* transaction_id
*   outputs:
* - none
**************************************************************************/
void set_transaction_id(transaction_t* transaction, char* transaction_id)
{
	strcpy(transaction->transaction_id, transaction_id);
}

/**************************************************************************
* This function is used to set the value of sender_id
*
*   inputs:
* - transaction_t* transaction, char* sender_id
*   outputs:
* - none
**************************************************************************/
void set_sender_id(transaction_t* transaction, char* sender_id)
{
	strcpy(transaction->sender_id, sender_id);
}

/**************************************************************************
* This function is used to set the value of receiver_id
*
*   inputs:
* - transaction_t* transaction, char* receiver_id
*   outputs:
* - none
**************************************************************************/
void set_receiver_id(transaction_t* transaction, char* receiver_id)
{
	strcpy(transaction->receiver_id, receiver_id);
}

/**************************************************************************
* This function is used to set the value of amount
*
*   inputs:
* - transaction_t* transaction, double amount
*   outputs:
* - none
**************************************************************************/
void set_amount(transaction_t* transaction, double amount)
{
	transaction->amount = amount;
}

/**************************************************************************
* This function is used to set the value of date_time
*
*   inputs:
* - transaction_t* transaction, date_time_t* date_time
*   outputs:
* - none
**************************************************************************/
void set_date_time(transaction_t* transaction, date_time_t* date_time)
{
	transaction->date_time = construct_date_time_overload1(date_time->month, date_time->day, date_time->hour, date_time->minute);
}

/**************************************************************************
* This function is used to print the detail of transaction
*
*   inputs:
* - transaction_t* transaction
*   outputs:
* - none
**************************************************************************/
void print_transaction(transaction_t* transaction)
{
	printf("Transaction ID: %s", transaction->transaction_id);
	printf("  Sender ID: %s", transaction->sender_id);
	printf("  Receiver ID: %s", transaction->receiver_id);
	printf("  Amount: %0.2f  ", transaction->amount);
	print_date_time(transaction->date_time);
}