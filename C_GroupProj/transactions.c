#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transactions.h"

transactions_t* construct_transactions(void)
{
	transactions_t* transactions = malloc(sizeof(transactions_t));
	transactions->transaction_list = construct_linked_list((destruct_data_function)(&destruct_transaction), sizeof(transaction_t));
	
	return transactions;
}

void destruct_transactions(transactions_t* transactions)
{
	destruct_linked_list(transactions->transaction_list);
	free(transactions);
}

linked_list_t* get_transaction_list(transactions_t* transactions)
{
	return transactions->transaction_list;
}

void add_transaction(transactions_t* transactions, transaction_t transaction)
{
	push_back(transactions->transaction_list, &transaction);
}

int remove_transaction(transactions_t* transactions, unsigned int index)
{
	return delete_by_index(transactions->transaction_list, index);
}

transaction_t* get_transaction_by_index(transactions_t* transactions, unsigned int index)
{
	return get_by_index(transactions->transaction_list, index);
}

transaction_t* get_transaction_by_id(transactions_t* transactions, char* transaction_id)
{
	transaction_t* temp = NULL;

	unsigned int i;
	for (i = 0; i < get_length(transactions->transaction_list); i++)
	{
		temp = get_transaction_by_index(transactions, i);
		if (!strcmp(get_transaction_id(temp), transaction_id))
			return temp;
	}

	return temp;
}

int get_transaction_index_by_id(transactions_t* transactions, char* transaction_id)
{
	unsigned int i;
	for (i = 0; i < get_length(transactions->transaction_list); i++)
	{
		if (matches_transaction_id(get_transaction_by_index(transactions, i), transaction_id))
			return i;
	}

	return -1;
}

void print_transaction_list(transactions_t* transactions)
{
	node_t* current = (transactions->transaction_list->head);
	while (current != NULL)
	{
		print_transaction(get_data(current));
		current = get_next(current);
	}
}