#include "linked_list.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	linked_list_t* list;
	list = construct_linked_list();
	
	int num1 = 5;
	int num2 = 10;

	push_back(list, &num1, sizeof(int));
	push_back(list, &num2, sizeof(int));


	printf("%d\n", *(int*)get_by_index(list, 0));
	printf("%d\n", *(int*)get_by_index(list, 1));

	printf("%d\n", delete_by_index(list, 0));
	
	printf("%d\n", *(int*)get_by_index(list, 0));
	
	destruct_linked_list(list);

	return 0;
}