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

void menu_1_print_menu(void);
unsigned int menu_1_read_option(void);
void menu_1(clients_t*);

int check_client_id_format(const char*);
int check_client_pw_format(const char*);
int read_client_id_pw(char*, char*);
void login(clients_t*, char*, char*);
void login_client(clients_t*);
void regist(clients_t*, char*, char*);
void register_client(clients_t*);
void exit_program(void);
void error(void);
