#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clients.h"

clients_t* construct_clients()
{
	clients_t* clients = malloc(sizeof(clients_t));
	clients->client_list = construct_linked_list(NULL,sizeof(client_t));
	
	return clients;
}

void destruct_clients(clients_t* clients)
{
	destruct_linked_list(clients->client_list);
	free(clients);
}

linked_list_t* get_client_list(clients_t* clients)
{
	return clients->client_list;
}

void add_client(clients_t* clients, client_t client)
{
	push_back(clients->client_list, &client);
}

int remove_client(clients_t* clients, unsigned int index)
{
	return delete_by_index(clients->client_list, index);
}

client_t* get_client_by_index(clients_t* clients, unsigned int index)
{
	return get_by_index(clients->client_list, index);
}

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

void print_client_list(clients_t* clients)
{
	node_t* current = (clients->client_list->head);
	while (current != NULL)
	{
		print_client(get_data(current));
		current = get_next(current);
	}
}