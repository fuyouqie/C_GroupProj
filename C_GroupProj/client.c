#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

client_t* construct_client()
{
	client_t* client = malloc(sizeof(client_t));
	client->balance = 0.0;

	return client;
}

client_t* construct_client_overload1(char* id, char* pw_cipher, double balance)
{
	client_t* client = malloc(sizeof(client_t));
	strcpy(client->id, id);
	strcpy(client->pw_cipher, pw_cipher);
	client->balance = balance;

	return client;
}

void destruct_client(client_t* client)
{
	free(client);
}

char* get_id(client_t* client)
{
	return client->id;
}

char* get_pw_cipher(client_t* client)
{
	return client->pw_cipher;
}

void set_pw_cipher(client_t* client, char* new_pw_cipher)
{
	memset(client->pw_cipher, 0, MAX_CLIENT_PW_CIPHER_LEN + 1);
	strcpy(client->pw_cipher, new_pw_cipher);
}

double get_balance(client_t* client)
{
	return client->balance;
}

void increase_balance(client_t* client, double balance)
{
	client->balance += balance;
}

void decrease_balance(client_t* client, double balance)
{
	client->balance -= balance;
}
