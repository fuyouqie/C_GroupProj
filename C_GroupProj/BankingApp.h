#pragma once

#define GENERAL_BUFFER_SIZE 100
#define ASCII_NUM_ZERO 48
#define ASCII_NUM_NINE 57
#define ASCII_UPPER_A 65
#define ASCII_UPPER_Z 90
#define ASCII_LOWER_A 97
#define ASCII_LOWER_Z 122
#define ASCII_SPECIAL_1 33  /*  !  */
#define ASCII_SPECIAL_2 64  /*  @  */
#define ASCII_SPECIAL_3 33  /*  #  */
#define ASCII_SPECIAL_4 36  /*  $  */
#define ASCII_SPECIAL_5 37  /*  %  */
#define ASCII_SPECIAL_6 94  /*  ^  */
#define ASCII_SPECIAL_7 38  /*  &  */
#define ASCII_SPECIAL_8 42  /*  *  */
#define ASCII_SPECIAL_9 46  /*  .  */


void BankingApp(void);

void print_start_menu(void);
int start_menu_read_option(void);
void start_menu(clients_t*);

void print_client_menu(void);
int client_menu_read_option(void);
void client_menu(client_t*, clients_t*, transactions_t*);

void print_client_transactions(client_t*, transactions_t*);
void view_account(client_t*, transactions_t*);

void transfer(client_t*, clients_t*, transactions_t*);
int check_receiver(client_t*, clients_t*, transactions_t*, char*);
void transfer_amount(client_t*, client_t*, transactions_t*);
void generate_random_ints(int*, int, int);
void generate_transaction_id(char*);
void generate_date_time(date_time_t*);
int read_amount(double*);
int check_amount(client_t*, double);

int check_client_id_format(const char*);
int check_client_pw_format(const char*);
int read_client_id(char*);
int read_client_pw(char*);
int read_client_id_pw(char*, char*);

void login(clients_t*, char*, char*);
void login_client(clients_t*);

void regist(clients_t*, char*, char*);
void register_client(clients_t*);

void save_client_db(clients_t*);
int load_client(FILE*, client_t*);
void load_client_db(clients_t*);

void exit_program(void);
void error(void);
