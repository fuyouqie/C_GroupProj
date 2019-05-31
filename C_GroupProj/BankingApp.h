#pragma once

#include "clients.h"
#include "transactions.h"
#include "encrypt.h"

#define GENERAL_BUFFER_SIZE 100

/*
	Program start
*/
void BankingApp(void);

/*
	Start menu
*/
void print_start_menu(void);
int start_menu_read_option(void);
void start_menu(clients_t*, transactions_t*);

/*
	Encrypt password
*/
void encrypt_pw(char*, char*);

/*
	Read  id/pw and foramt checks
*/
int check_client_id_format(const char*);
int check_client_pw_format(const char*);
int read_client_id(char*);
int read_client_pw(char*);
int read_client_id_pw(char*, char*);

/*
	Login
*/
void login(clients_t*, transactions_t*, char*, char*);
void login_client(clients_t*, transactions_t*);

/*
	Register
*/
void regist(clients_t*, transactions_t*, char*, char*);
void register_client(clients_t*, transactions_t*);

/*
	Client menu(after login/register)
*/
void print_client_menu(void);
int client_menu_read_option(void);
void client_menu(client_t*, clients_t*, transactions_t*);

/*
	View Account
*/
void print_client_transactions(client_t*, transactions_t*);
void view_account(client_t*, transactions_t*);

/*
	Transfer
*/
void transfer(client_t*, clients_t*, transactions_t*);
int check_receiver(client_t*, clients_t*, transactions_t*, char*);
void transfer_amount(client_t*, client_t*, transactions_t*, clients_t*);
void generate_random_ints(int*, int, int);
void generate_transaction_id(char*);
void generate_date_time(date_time_t*);
int read_amount(double*);
int check_amount(client_t*, double);

/*
	Deposit
*/
void deposit(client_t*, clients_t*);

/*
	Withdraw
*/
void withdraw(client_t*, clients_t*);

/*
	Change password
*/
void change_pw(client_t*, clients_t*);
void change_to_new_pw(client_t*, clients_t*);

/*
	Cancel client
*/
void cancel_client_(client_t*, clients_t*, transactions_t*);
int cancel_client(client_t*, clients_t*, transactions_t*);

/*
	Logout
*/
int logout(client_t*);

/*
	Process client database
*/
void save_client_db(clients_t*);
int load_client(FILE*, client_t*);
void load_client_db(clients_t*);

/*
	Process transaction database
*/
void save_transaction_db(transactions_t*);
int load_transaction(FILE*, transaction_t*);
void load_transaction_db(transactions_t*);

/*
	Error message
*/
void error(void);