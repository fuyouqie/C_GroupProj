#include "clients.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	clients_t* clients = construct_clients();
	client_t client;
	char id1[] = "ASDE";
	char pw1[] = "Bse41";
	double balance1 = 54.23;

	char id2[] = "bvvb";
	char pw2[] = "14asd141";
	double balance2 = 12.23;

	char id3[] = "N%fg@#";
	char pw3[] = "fg!sd2";
	double balance3 = 76.23;

	set_client(&client, id1, pw1, balance1);
	add_client(clients, client);

	set_client(&client, id2, pw2, balance2);
	add_client(clients, client);

	set_client(&client, id3, pw3, balance3);
	add_client(clients, client);

	print_client_list(clients);

	return 0;
}