#pragma once

#include "transaction.h"
#include "linked_list.h"

typedef struct transactions
{
	linked_list_t* transaction_list;
}
transactions_t;

transactions_t* construct_transactions(void);
void destruct_transactions(transactions_t*);
linked_list_t* get_transaction_list(transactions_t*);
void add_transaction(transactions_t*, transaction_t);
int remove_transaction(transactions_t*, unsigned int);
transaction_t* get_transaction_by_index(transactions_t*, unsigned int);
transaction_t* get_transaction_by_id(transactions_t*, char*);
int get_transaction_index_by_id(transactions_t*, char*);
void print_transaction_list(transactions_t*);