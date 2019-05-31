#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transactions.h"
/**************************************************************************
* Default constructor 
* allocates memory and construct linked list
*   inputs:
* - none
*   outputs:
* - transactions_t*
**************************************************************************/
transactions_t* construct_transactions(void)
{
	transactions_t* transactions = malloc(sizeof(transactions_t));
	transactions->transaction_list = construct_linked_list((destruct_data_function)(&destruct_transaction), sizeof(transaction_t));
	
	return transactions;
}

/**************************************************************************
* Destructor that calls linked list destructor
* Frees up itself as well
*   inputs:
* - transactions_t* transactions
*   outputs:
* - none
**************************************************************************/
void destruct_transactions(transactions_t* transactions)
{
	destruct_linked_list(transactions->transaction_list);
	free(transactions);
}

/**************************************************************************
*  Checks if the transaction id already exists in the transactions list
*
*   inputs:
* - transactions_t* transactions, char* id
*   outputs:
* - none
**************************************************************************/
int check_transaction_id_exists(transactions_t* transactions, char* id)
{
	unsigned int i;
	for (i = 0; i < get_length(transactions->transaction_list); i++)
	{
		if (matches_transaction_id(get_transaction_by_index(transactions, i), id))
			return 1;
	}

	return 0;
}

/**************************************************************************
* This function is to get the transaction list
*
*   inputs:
* - transactions_t* transactions
*   outputs:
* - linked_list_t*
**************************************************************************/
linked_list_t* get_transaction_list(transactions_t* transactions)
{
	return transactions->transaction_list;
}

/**************************************************************************
* This function is to add a transaction to the group
*
*   inputs:
* - transactions_t* transactions, transaction_t transaction
*   outputs:
* - none
**************************************************************************/
void add_transaction(transactions_t* transactions, transaction_t transaction)
{
	push_back(transactions->transaction_list, &transaction);
}

/**************************************************************************
* This function is to remove a transaction from the group at given index
*
*   inputs:
* - transactions_t* transactions, unsigned int index
*   outputs:
* - int
**************************************************************************/
int remove_transaction(transactions_t* transactions, unsigned int index)
{
	return delete_by_index(transactions->transaction_list, index);
}

/**************************************************************************
* This function is to get the transaction by index
*
*   inputs:
* - transactions_t* transactions, unsigned int index
*   outputs:
* - transaction_t*
**************************************************************************/
transaction_t* get_transaction_by_index(transactions_t* transactions, unsigned int index)
{
	return get_by_index(transactions->transaction_list, index);
}

/**************************************************************************
* This function is to get the transaction by ID
*
*   inputs:
* - transactions_t* transactions, char* transaction_id
*   outputs:
* - transaction_t*
**************************************************************************/
transaction_t* get_transaction_by_id(transactions_t* transactions, char* transaction_id)
{
	transaction_t* temp = NULL;

	unsigned int i;
	for (i = 0; i < get_length(transactions->transaction_list); i++)
	{
		temp = get_transaction_by_index(transactions, i);
		if (strcmp(get_transaction_id(temp), transaction_id) == 0)
			return temp;
	}

	return temp;
}

/**************************************************************************
* This function is to get the transaction index by ID
*
*   inputs:
* - transactions_t* transactions, char* transaction_id
*   outputs:
* - int
**************************************************************************/
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

/**************************************************************************
* This function is to print the transaction list
*
*   inputs:
* - transactions_t* transactions
*   outputs:
* - none
**************************************************************************/
void print_transaction_list(transactions_t* transactions)
{
	node_t* current = (transactions->transaction_list->head);
	while (current != NULL)
	{
		print_transaction(get_data(current));
		current = get_next(current);
	}
}