#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "BankingApp.h"

void print_menu(void)
{

}

char read_option(void)
{
	print_menu();

	int option;
	if (scanf("%d", &option) != 1)
	{
		InputMissMatchException_t exp;
		throw exp;
	}
	return option;
}

void menu(void)
{
	switch (option)
	{
		case 1:
			login();
		case 2:
			exit();
		default:
			error();
	}
}