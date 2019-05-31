#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**************************************************************************
*   Default constructor                                                                      
*   Allocates memeory and initialises the fields                                                                      *
*                                                                         
*   inputs:                                                               
* - void                                                                  
*   outputs:                                                              
* - client_t*                                                             
**************************************************************************/
client_t* construct_client(void)
{
	client_t* client = malloc(sizeof(client_t));

	memset(client->id, 0, CLIENT_ID_LEN + 1);
	memset(client->pw_cipher, 0, MAX_CLIENT_PW_CIPHER_LEN + 1);
	set_balance(client, 0.0);

	return client;
}

/**************************************************************************
*   Alternate construct that takes id, pw_cipher and balance as paramters                                                                      
*   Allocates memory and initialises the fields with value passed in                                                                      
*                                                                         
*   inputs:                                                               
* - char* id, char* pw_cipher, double balance                             
*   outputs:                                                              
* - client_t*                                                             
**************************************************************************/
client_t* construct_client_overload1(char* id, char* pw_cipher, double balance)
{
	client_t* client = malloc(sizeof(client_t));

	set_client(client, id, pw_cipher, balance);

	return client;
}

/**************************************************************************
*   Destruct a client                                                                      
*   No special consideration needed since                                                                       
*   all fields are allocated statically                                                                    
*   inputs:                                                               
* - client_t* client                                                      
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void destruct_client(client_t* client)
{
	free(client);
}

/**************************************************************************
*   Checks if the id and pw passed in is the same as the id and pw of                                                                      
*   the client passed in                                                                      
*                                                                         
*   inputs:                                                               
* - client_t* client, char* id, char* pw_cipher                           
*   outputs:                                                              
* - int                                                                   
**************************************************************************/
int matches_client_id_pw(client_t* client, char* id, char* pw_cipher)
{
	if (strcmp(client->id, id) == 0 && strcmp(client->pw_cipher, pw_cipher) == 0)
		return 1;

	return 0;
}

/**************************************************************************
*   Checks if the id passed in is the same as the id of                                                                      
*   the client passed in                                                                      
*                                                                         
*   inputs:                                                               
* - client_t* client, char* id                                            
*   outputs:                                                              
* - int                                                                   
**************************************************************************/
int matches_client_id(client_t* client, char* id)
{
	if (strcmp(client->id, id) == 0)
		return 1;
	
	return 0;
}

/**************************************************************************
*   Checks if the pw passed in is the same as the pw of                                                                      
*   the client passed in                                                                      
*                                                                         
*   inputs:                                                               
* - client_t* client, char* pw_cipher                                            
*   outputs:                                                              
* - int                                                                   
**************************************************************************/
int matches_client_pw(client_t* client, char* pw_cipher)
{
	if (strcmp(client->pw_cipher, pw_cipher) == 0)
		return 1;

	return 0;
}

/**************************************************************************
*   setup a client with value passed in                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client, char* id, char* pw_cipher, double balance           
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void set_client(client_t* client, char* id, char* pw_cipher, double balance)
{
	set_client_id(client, id);
	set_pw_cipher(client, pw_cipher);
	set_balance(client, balance);
}

/**************************************************************************
*   get a client's id                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client                                                      
*   outputs:                                                              
* - char*                                                                 
**************************************************************************/
char* get_client_id(client_t* client)
{
	return client->id;
}

/**************************************************************************
*   set a client's id                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client, char* id                                            
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void set_client_id(client_t* client, char* id)
{
	memset(client->id, 0, CLIENT_ID_LEN + 1);
	strcpy(client->id, id);
}

/**************************************************************************
*   get a client's password cipher                                                                      
*                                                                        
*                                                                         
*   inputs:                                                               
* - client_t* client                                                      
*   outputs:                                                              
* - char*                                                                 
**************************************************************************/
char* get_pw_cipher(client_t* client)
{
	return client->pw_cipher;
}

/**************************************************************************
*   set a client's password cipher                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client, char* pw_cipher                                     
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void set_pw_cipher(client_t* client, char* pw_cipher)
{
	memset(client->pw_cipher, 0, MAX_CLIENT_PW_CIPHER_LEN + 1);
	strcpy(client->pw_cipher, pw_cipher);
}

/**************************************************************************
*   get a client's balance                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client                                                      
*   outputs:                                                              
* - double                                                                
**************************************************************************/
double get_balance(client_t* client)
{
	return client->balance;
}

/**************************************************************************
*   set a client's balance                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client, double balance                                      
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void set_balance(client_t* client, double balance)
{
	client->balance = balance;
}

/**************************************************************************
*   increase the balance by amount                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client, double balance                                      
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void increase_balance(client_t* client, double balance)
{
	client->balance += balance;
}

/**************************************************************************
*   decrease client's balance by amonut                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client, double balance                                      
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void decrease_balance(client_t* client, double balance)
{
	client->balance -= balance;
}

/**************************************************************************
*   prints a client's fields                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - client_t* client                                                      
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void print_client(client_t* client)
{
	printf("ID: %s", client->id);
	printf("  PW_cipher: %s", client->pw_cipher);
	printf("  Balance: %0.2f\n", client->balance);
}