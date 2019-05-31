#pragma once

/*
	Format for ID:
		MUST be exactly a 8-digit number

	Format for PW and its cipher:
		The password plaintext should be between 8 and 12 characters
		The password cipher is fixed to be 8 characters hex value
		The plaintext should contain:
			At least one upper case
			At least one lower case
			At least one number
			At least one special characters(listed below)
*/
#define CLIENT_ID_LEN 8

#define MIN_CLIENT_PW_LEN 8
#define MAX_CLIENT_PW_LEN 12
#define MAX_CLIENT_PW_CIPHER_LEN 8
#define ASCII_NUM_ZERO 48
#define ASCII_NUM_NINE 57
#define ASCII_UPPER_A 65
#define ASCII_UPPER_Z 90
#define ASCII_LOWER_A 97
#define ASCII_LOWER_Z 122
#define ASCII_SPECIAL_1 33  /*  !  */
#define ASCII_SPECIAL_2 64  /*  @  */
#define ASCII_SPECIAL_3 35  /*  #  */
#define ASCII_SPECIAL_4 36  /*  $  */
#define ASCII_SPECIAL_5 37  /*  %  */
#define ASCII_SPECIAL_6 94  /*  ^  */
#define ASCII_SPECIAL_7 38  /*  &  */
#define ASCII_SPECIAL_8 42  /*  *  */
#define ASCII_SPECIAL_9 46  /*  .  */

#define CLIENT_DB "client_db.txt"
#define CLIENT_FIELD_COUNT 3

/*
	struct client contains:
		ID
		PW in ciphertext
		Balance
*/
typedef struct client
{
	char id[CLIENT_ID_LEN + 1];
	char pw_cipher[MAX_CLIENT_PW_CIPHER_LEN + 1];
	double balance;
}
client_t;

client_t* construct_client(void);
client_t* construct_client_overload1(char*, char*, double);
void destruct_client(client_t*);
int matches_client_id_pw(client_t*, char*, char*);
int matches_client_id(client_t*, char*);
int matches_client_pw(client_t*, char*);
void set_client(client_t*, char*, char*, double);
char* get_client_id(client_t*);
void set_client_id(client_t*, char*);
char* get_pw_cipher(client_t*);
void set_pw_cipher(client_t*, char*);
double get_balance(client_t*);
void set_balance(client_t*, double);
void increase_balance(client_t*, double);
void decrease_balance(client_t*, double);
void print_client(client_t*);