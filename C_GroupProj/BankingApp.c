#include <stdio.h>
#include <stdlib.h>
#include "clients.h"
#include "transactions.h"
#include "encrypt.h"
#include "BankingApp.h"

void BankingApp(void)
{
	clients_t* clients = construct_clients();
	load_client_db(clients);

	start_menu(clients);
}

void print_start_menu(void)
{
	printf("\n"
	"1.    Login\n"
	"2.    Register\n"
	"3.    Exit Program\n\n"
	"Enter option(1 - 4)> \n");
}

unsigned int start_menu_read_option(void)
{
	print_start_menu();

	int option;
	if (scanf("%d", &option) != 1)
	{
		while ((getchar()) != '\n');
		printf("Input type mismatch\n");
		return start_menu_read_option();
	}

	return option;
}

void start_menu(clients_t* clients)
{
	unsigned int option = start_menu_read_option();

	while (option != 3)
	{
		switch (option)
		{
			case 1:
				login_client(clients);
				break;
			case 2:
				register_client(clients);
				break;
			default:
				error();
		}

		option = start_menu_read_option();
	}
}

void print_client_menu(void)
{
	printf("\n"
		   "1.    View Account Detail\n"
		   "2.    Transfer\n"
		   "3.    Deposit\n"
		   "4.    Withdraw\n"
		   "5.    Change Password\n"
		   "6.    Delete Account\n"
		   "7.    Exit Program\n\n"
		   "Enter option(1 - 7)> \n");
}

unsigned int client_menu_read_option(void)
{
	print_client_menu();

	int option;
	if (scanf("%d", &option) != 1)
	{
		while ((getchar()) != '\n');
		printf("Input type mismatch\n");
		return client_menu_read_option();
	}

	return option;
}

void client_menu(client_t* current, transactions_t* transactions)
{
	unsigned int option = client_menu_read_option();

	while (option != 7)
	{
		switch (option)
		{
			case 1:
				view_account(current, transactions);
				break;
			case 2:
				//register_client(clients);
				break;
			case 3:
				//register_client(clients);
				break;
			case 4:
				//register_client(clients);
				break;
			case 5:
				//register_client(clients);
				break;
			case 6:
				//register_client(clients);
				break;
			case 7:
				exit_program();
				break;
			default:
				error();
		}

		option = client_menu_read_option();
	}
}

void print_client_transactions(client_t* client, transactions_t* transactions)
{
	node_t* current = (transactions->transaction_list->head);
	while (current != NULL)
	{
		transaction_t* transaction = (transaction_t*)get_data(current);

		if(strcmp(transaction->sender_id, client->id) || strcmp(transaction->receiver_id, client->id))
			print_transaction(transaction);
		current = get_next(current);
	}
}

void view_account(client_t* current, transactions_t* transactions)
{
	printf("#Account Information\n");
	print_client(current);
	printf("#Transaction Details\n");
	print_client_transactions(current, transactions);
}

int check_client_id_format(const char* buffer)
{
	unsigned int length = strlen(buffer);
	if (length != CLIENT_ID_LEN)
		return 0;

	unsigned int i;
	for (i = 0; i < length; i++)
	{
		if (buffer[i] < ASCII_NUM_ZERO || buffer[i] > ASCII_NUM_NINE)
			return 0;
	}

	return 1;
}

int check_client_pw_format(const char* buffer)
{
	unsigned int length = strlen(buffer);
	if (length < MIN_CLIENT_PW_LEN || length > MAX_CLIENT_PW_LEN)
		return 0;

	int result = 0;
	/*contains numbers*/
	unsigned int i;
	for (i = 0; i < length; i++)
	{
		if (buffer[i] > ASCII_NUM_ZERO && buffer[i] < ASCII_NUM_NINE)
		{
			++result;
			break;
		}
	}

	/*contains upper case*/
	for (i = 0; i < length; i++)
	{
		if (buffer[i] > ASCII_UPPER_A && buffer[i] < ASCII_UPPER_Z)
		{
			++result;
			break;
		}
	}

	/*contains lower case*/
	for (i = 0; i < length; i++)
	{
		if (buffer[i] > ASCII_LOWER_A && buffer[i] < ASCII_LOWER_Z)
		{
			++result;
			break;
		}
	}

	/*contains special character*/
	for (i = 0; i < length; i++)
	{
		if (buffer[i] == ASCII_SPECIAL_1 || 
			buffer[i] == ASCII_SPECIAL_2 ||
			buffer[i] == ASCII_SPECIAL_3 ||
			buffer[i] == ASCII_SPECIAL_4 ||
			buffer[i] == ASCII_SPECIAL_5 ||
			buffer[i] == ASCII_SPECIAL_6 ||
			buffer[i] == ASCII_SPECIAL_7 ||
			buffer[i] == ASCII_SPECIAL_8 ||
			buffer[i] == ASCII_SPECIAL_9)
		{
			++result;
			break;
		}
	}

	if (result != 4)
		return 0;
	
	return 1;
}

int read_client_id_pw(char* id, char* pw)
{
	char buffer[GENERAL_BUFFER_SIZE];
	int check_result = 1;
	/*
	1 - format correct
	2 - id no pw yes
	3 - id yes pw no
	4 - id no pw no
	*/

	printf("Client ID> \n");
	scanf("%[^\n]", buffer);

	if (!check_client_id_format(buffer))
		check_result = 2;
	else
		strcpy(id, buffer);
	while ((getchar()) != '\n');

	if (!check_client_pw_format(buffer))
	{
		if (check_result == 2)
			check_result = 4;
		else
			check_result = 3;
	}
	else
		strcpy(pw, buffer);
	while ((getchar()) != '\n');

	return check_result;
}

void login(clients_t* clients, char* id, char* pw)
{
	client_t* current_client = NULL;
	char pw_cipher[MAX_CLIENT_PW_CIPHER_LEN + 1];

	unsigned long pw_hash = encrypt(pw, strlen(pw), MAX_CLIENT_PW_CIPHER_LEN);
	sprintf(pw_cipher, "%08lx", pw_hash);

	current_client = login_check(clients, id, pw_cipher);
	if (current_client == NULL)
		printf("Incorrect client ID or password\n");
	else
	{
		printf("Logged in as client %s\n", current_client->id);
		transactions_t* transactions = construct_transactions();
		client_menu(current_client, transactions);
	}
}

void login_client(clients_t* clients)
{
	printf("Login\n");

	char id[MAX_CLIENT_ID_LEN + 1];
	char pw[MAX_CLIENT_PW_LEN + 1];

	int read_result = read_client_id_pw(id, pw);
	switch (read_result)
	{
		case '1':
			login(clients, id, pw);
			break;
		case '2':
			printf("Incorrect ID format\n");
			break;
		case '3':
			printf("Incorrect password format\n");
			break;
		case '4':
			printf("Incorrect ID and password format\n");
			break;
		default:;
	}
}

void regist(clients_t* clients, char* id, char* pw)
{
	client_t* current_client = NULL;
	char pw_cipher[MAX_CLIENT_PW_CIPHER_LEN + 1];

	unsigned long pw_hash = encrypt(pw, strlen(pw), MAX_CLIENT_PW_CIPHER_LEN);
	sprintf(pw_cipher, "%08lx", pw_hash);

	if (!register_check(clients, id))
		printf("Client ID already exists\n");
	else
	{
		printf("New client registered %s\n", id);
		client_t temp;
		set_client(&temp, id, pw_cipher, 0.0);
		add_client(clients, temp);
		current_client = get_client_by_index(clients, get_length(clients->client_list) - 1);
		save_client_db(clients);
		
		transactions_t* transactions = construct_transactions();
		client_menu(current_client, transactions);
	}
}

void register_client(clients_t* clients)
{
	printf("Register\n");
	char id[MAX_CLIENT_ID_LEN + 1];
	char pw[MAX_CLIENT_PW_LEN + 1];

	int read_result = read_client_id_pw(id, pw);
	switch (read_result)
	{
		case '1':
			regist(clients, id, pw);
			break;
		case '2':
			printf("Incorrect ID format\n");
			break;
		case '3':
			printf("Incorrect password format\n");
			break;
		case '4':
			printf("Incorrect ID and password format\n");
			break;
		default:;
	}

}

void save_client_db(clients_t* clients)
{
	FILE* fp;
	fp = fopen(CLIENT_DB, "w+");

	fprintf(fp, "Client ID      PW_Cipher      Balance\n");
	unsigned int i;
	for (i = 0; i < get_length(clients->client_list); i++)
	{
		client_t* current = get_client_by_index(clients, i);
		fprintf(fp, "%s   %s   %f\n", current->id, current->pw_cipher, current->balance);
	}
	fclose(fp);
}

int load_client(FILE* fp, client_t* temp)
{
	int result = fscanf(fp, "%s   %s   %lf\n", temp->id, temp->pw_cipher, &(temp->balance));

	return result;
}

void load_client_db(clients_t* clients)
{
	FILE* fp;
	fp = fopen(CLIENT_DB, "r");
	if (fp == NULL)
	{
		printf("Read error\n");
		return;
	}

	destruct_clients(clients);
	clients = construct_clients();

	fscanf(fp, "%*[^\n]");

	client_t temp;

	while (load_client(fp, &temp) == CLIENT_FIELD_COUNT)
		add_client(clients, temp);

	fclose(fp);
}

void exit_program(void)
{
	printf("Program ends\n");
}

void error(void)
{
	printf("Option not found\n");
}