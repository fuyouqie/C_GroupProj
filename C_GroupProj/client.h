#pragma once

#define MAX_CLIENT_ID_LEN 8
#define MAX_CLIENT_PW_CIPHER_LEN 16

typedef struct client
{
	char id[MAX_CLIENT_ID_LEN + 1];
	char pw_cipher[MAX_CLIENT_PW_CIPHER_LEN + 1];
	double balance;
}
client_t;

client_t* construct_client();
client_t* construct_client_overload1(char*, char*, double);
void destruct_client(client_t*);
char* get_id(client_t*);
char* get_pw_cipher(client_t*);
void set_pw_cipher(client_t*, char*);
double get_balance(client_t*);
void increase_balance(client_t*, double);
void decrease_balance(client_t*, double);
