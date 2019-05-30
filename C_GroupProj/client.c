#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

client_t* construct_client(void)
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

int matches_client_id_pw(client_t* client, char* id, char* pw_cipher)
{
	if (strcmp(client->id, id) == 0 && strcmp(client->pw_cipher, pw_cipher) == 0)
		return 1;

	return 0;
}

int matches_client_id(client_t* client, char* id)
{
	if (strcmp(client->id, id) == 0)
		return 1;
	
	return 0;
}

void set_client(client_t* client, char* id, char* pw_cipher, double balance)
{
	set_client_id(client, id);
	set_pw_cipher(client, pw_cipher);
	set_balance(client, balance);
}

char* get_client_id(client_t* client)
{
	return client->id;
}

void set_client_id(client_t* client, char* id)
{
	memset(client->id, 0, CLIENT_ID_LEN + 1);
	strcpy(client->id, id);
}

char* get_pw_cipher(client_t* client)
{
	return client->pw_cipher;
}

void set_pw_cipher(client_t* client, char* pw_cipher)
{
	memset(client->pw_cipher, 0, MAX_CLIENT_PW_CIPHER_LEN + 1);
	strcpy(client->pw_cipher, pw_cipher);
}

double get_balance(client_t* client)
{
	return client->balance;
}

void set_balance(client_t* client, double balance)
{
	client->balance = balance;
}

void increase_balance(client_t* client, double balance)
{
	client->balance += balance;
}

void decrease_balance(client_t* client, double balance)
{
	client->balance -= balance;
}

void print_client(client_t* client)
{
	printf("ID: %s", client->id);
	printf("  PW_cipher: %s", client->pw_cipher);
	printf("  Balance: %0.2f\n", client->balance);
}