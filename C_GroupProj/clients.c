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

static int equals(client_t* data_a, client_t* data_b)
{
	return strcmp(data_a->id, data_b->id);
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
		if (strcmp(get_id(temp), id))
			return temp;
	}

	return temp;
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