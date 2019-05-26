#include "client.h"
#include "linked_list.h"

typedef struct clients
{
	linked_list_t* client_list;
}
clients_t;

clients_t* construct_clients();
void destruct_clients(clients_t*);
linked_list_t* get_client_list(clients_t*);
void add_client(clients_t*, client_t);
void remove_client(clients_t*, client_t);
client_t* get_client_by_index(clients_t*, unsigned int);
client_t* get_client_by_id(clients_t*, char*);
void print_client_list(clients_t*);