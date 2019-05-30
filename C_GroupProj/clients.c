#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clients.h"

/**************************************************************************
* This function is to allocaet memory to clients _struct
*
*   inputs:
* - none
*   outputs:
* - none
**************************************************************************/
clients_t* construct_clients()
{
	clients_t* clients = malloc(sizeof(clients_t));
	clients->client_list = construct_linked_list(NULL,sizeof(client_t));
	
	return clients;
}

/**************************************************************************
* This function is to set free memory allocate to clients _struct
*
*   inputs:
* - clients_t* clients
*   outputs:
* - none
**************************************************************************/
void destruct_clients(clients_t* clients)
{
	destruct_linked_list(clients->client_list);
	free(clients);
}

/**************************************************************************
* This function is to getteh client_list
*
*   inputs:
* - clients_t* clients
*   outputs:
* - linked_list_t*
**************************************************************************/
linked_list_t* get_client_list(clients_t* clients)
{
	return clients->client_list;
}

/**************************************************************************
* 
*
*   inputs:
* - clients_t* clients
*   outputs:
* - linked_list_t*
**************************************************************************/
void add_client(clients_t* clients, client_t client)
{
	push_back(clients->client_list, &client);
}

/**************************************************************************
* This function is toremove the client from the linklist
*
*   inputs:
* - clients_t* clients, unsigned int index
*   outputs:
* - int
**************************************************************************/
int remove_client(clients_t* clients, unsigned int index)
{
	return delete_by_index(clients->client_list, index);
}

/**************************************************************************
* This function is to get the client list
*
*   inputs:
* - clients_t* clients, unsigned int index
*   outputs:
* - client_t*
**************************************************************************/
client_t* get_client_by_index(clients_t* clients, unsigned int index)
{
	return get_by_index(clients->client_list, index);
}

/**************************************************************************
* This function is to get the client by search id
*
*   inputs:
* - clients_t* clients, char* id
*   outputs:
* - client_t*
**************************************************************************/
client_t* get_client_by_id(clients_t* clients, char* id)
{
	client_t* temp = NULL;

	unsigned int i;
	for (i = 0; i < get_length(clients->client_list); i++)
	{
		temp = get_client_by_index(clients, i);
		if (strcmp(get_client_id(temp), id) == 0)
			return temp;
	}

	return temp;
}

/**************************************************************************
* This function is to get the client index by search id
*
*   inputs:
* - clients_t* clients, char* id
*   outputs:
* - int
**************************************************************************/
int get_client_index_by_id(clients_t* clients, char* id)
{
	unsigned int i;
	for (i = 0; i < get_length(clients->client_list); i++)
	{
		if (matches_client_id(get_client_by_index(clients, i), id))
			return i;
	}

	return -1;
}

/**************************************************************************
* This function is to check the login 
*
*   inputs:
* - clients_t* clients, char* id, char* pw_cipher
*   outputs:
* - client_t*
**************************************************************************/
client_t* login_check(clients_t* clients, char* id, char* pw_cipher)
{
	unsigned int i;
	for (i = 0; i < get_length(clients->client_list); i++)
	{
		client_t* temp = get_client_by_index(clients, i);
		if (matches_client_id_pw(temp, id, pw_cipher))
			return temp;
	}

	return NULL;
}

/**************************************************************************
* This function is to check the register
*
*   inputs:
* - clients_t* clients, char* id
*   outputs:
* - int
**************************************************************************/
int register_check(clients_t* clients, char* id)
{
	unsigned int i;
	for (i = 0; i < get_length(clients->client_list); i++)
	{
		if (matches_client_id(get_client_by_index(clients, i), id))
			return 0;
	}

	return 1;
}

/**************************************************************************
* This function is to print the client list
*
*   inputs:
* - clients_t* clients
*   outputs:
* - none
**************************************************************************/
void print_client_list(clients_t* clients)
{
	node_t* current = (clients->client_list->head);
	while (current != NULL)
	{
		print_client(get_data(current));
		current = get_next(current);
	}
}