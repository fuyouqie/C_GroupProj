#pragma once

#define CLIENT_ID_LEN 8
#define MIN_CLIENT_PW_LEN 8
#define MAX_CLIENT_PW_LEN 12
#define MAX_CLIENT_PW_CIPHER_LEN 8

typedef struct client
{
	char id[CLIENT_ID_LEN + 1];
	char pw_cipher[MAX_CLIENT_PW_CIPHER_LEN + 1];
	double balance;
}
client_t;

client_t* construct_client();
client_t* construct_client_overload1(char*, char*, double);
void destruct_client(client_t*);
void set_client(client_t*, char*, char*, double);
char* get_id(client_t*);
void set_id(client_t*, char*);
char* get_pw_cipher(client_t*);
void set_pw_cipher(client_t*, char*);
double get_balance(client_t*);
void set_balance(client_t*, double);
void increase_balance(client_t*, double);
void decrease_balance(client_t*, double);
void print_client(client_t*);