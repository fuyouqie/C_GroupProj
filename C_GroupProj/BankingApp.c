#include <stdio.h>
#include <stdlib.h>
#include "clients.h"
#include "transactions.h"
#include "encrypt.h"
#include "BankingApp.h"

void BankingApp(void)
{
	clients_t* clients = construct_clients();

	menu_1(clients);
}

void menu_1_print_menu(void)
{
	printf("\n"
	"1.    Login\n"
	"2.    Register\n"
	"3.    Exit Program\n\n"
	"Enter option(1 - 4)> \n");
}

unsigned int menu_1_read_option(void)
{
	menu_1_print_menu();

	int option;
	if (scanf("%d", &option) != 1)
	{
		while ((getchar()) != '\n');
		printf("Input type mismatch\n");
		return menu_1_read_option();
	}

	return option;
}

void menu_1(clients_t* clients)
{
	unsigned int option = menu_1_read_option();

	while (option != 3)
	{
		switch (option)
		{
			case 1:
				login(clients);
				break;
			case 2:
				register_client(clients);
				break;
			default:
				error();
		}

		option = menu_1_read_option();
	}
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

void login_(clients_t* clients, client_t* current_client, char* id, char* pw)
{
	char pw_cipher[MAX_CLIENT_PW_CIPHER_LEN + 1];
	unsigned long pw_hash = encrypt(pw, strlen(pw), MAX_CLIENT_PW_CIPHER_LEN);
	sprintf(pw_cipher, "%08lx", pw_hash);

}

void login(clients_t* clients)
{
	printf("Login\n");

	char id[MAX_CLIENT_ID_LEN + 1];
	char pw[MAX_CLIENT_PW_LEN + 1];
	client_t* current_client = NULL;

	int read_result = read_client_id_pw(id, pw);
	switch (read_result)
	{
		case '1':
			login_(clients, current_client, id, pw);
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

void register_client(clients_t* clients)
{

}

void exit_program(void)
{
	printf("exit\n");
}

void error(void)
{
	printf("error\n");
}