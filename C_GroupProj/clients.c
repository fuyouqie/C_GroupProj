#include "clients.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

clients_t* construct_clients()
{
	clients_t* client_list;
	client_list = malloc(sizeof(clients_t));
	client_list->client_list = construct_linked_list();
	
	return client_list;
}

void destruct_clients(clients_t* clients)
{
	destruct_linked_list(clients->client_list);
	free(clients);
}

int equals(void* data_a, void* data_b)
{
	return strcmp(((client_t*)data_a)->id, ((client_t*)data_b)->id);
}

linked_list_t* get_client_list(clients_t* clients)
{
	return clients->client_list;
}

void add_client(clients_t* clients, client_t client)
{
	push_back(clients->client_list, &client, sizeof(client_t));
}

void remove_client(clients_t* clients, client_t client)
{
	delete_data(clients->client_list, &client);
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
	unsigned int i;
	for (i = 0; i < get_length(clients->client_list); i++)
		print_client(get_client_by_index(clients, i));
}