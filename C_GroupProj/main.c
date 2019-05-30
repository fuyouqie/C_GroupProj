#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "BankingApp.h"


void test_oop_2(transactions_t* transactions)
{
	print_transaction_list(transactions);

	remove_transaction(transactions, 1);
	print_transaction_list(transactions);

	destruct_transactions(transactions);
}

transactions_t* test_oop(void)
{
	
	clients_t* clients = construct_clients();
	client_t client;

	char id1[] = "ASDE";
	char pw1[] = "Bse41";
	double balance1 = 54.23;

	char id2[] = "bvvb";
	char pw2[] = "14asd141";
	double balance2 = 12.23;

	char id3[] = "N%fg@#";
	char pw3[] = "fg!sd2";
	double balance3 = 76.23;

	set_client(&client, id1, pw1, balance1);
	add_client(clients, client);

	set_client(&client, id2, pw2, balance2);
	add_client(clients, client);

	set_client(&client, id3, pw3, balance3);
	add_client(clients, client);

	print_client_list(clients);

	remove_client(clients, 1);
	print_client_list(clients);

	destruct_clients(clients);

	



	transactions_t* transactions = construct_transactions();
	transaction_t transaction;
	date_time_t date_time;

	char trans_id1[] = "trans1";
	char sender_id1[] = "client1";
	char receiver_id1[] = "client1";
	double amount1 = 233.34;
	set_date_time_(&date_time, 1, 1, 1, 1);
	set_transaction(&transaction, trans_id1, sender_id1, receiver_id1, amount1, &date_time);
	add_transaction(transactions, transaction);

	char trans_id2[] = "trans2";
	char sender_id2[] = "client2";
	char receiver_id2[] = "client2";
	double amount2 = 53.34;
	set_date_time_(&date_time, 2, 2, 2, 2);
	set_transaction(&transaction, trans_id2, sender_id2, receiver_id2, amount2, &date_time);
	add_transaction(transactions, transaction);

	char trans_id3[] = "trans3";
	char sender_id3[] = "client3";
	char receiver_id3[] = "client3";
	double amount3 = 25456.545;
	set_date_time_(&date_time, 3, 3, 3, 3);
	set_transaction(&transaction, trans_id3, sender_id3, receiver_id3, amount3, &date_time);
	add_transaction(transactions, transaction);

	print_transaction_list(transactions);

	return transactions;
}

void test_enc()
{
	char a[20];
	printf("Enter Password\n");
	scanf("%s", a);
	unsigned long hash = encrypt(a, strlen(a), MAX_CLIENT_PW_CIPHER_LEN);
	printf("After encryption:  %08lx\n", hash);
}


int main(void)
{
	BankingApp();

	return 0;
}