#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - none                                                                  *
*   outputs:                                                              *
* - node_t*                                                               *
**************************************************************************/
node_t* construct_node(void)
{
	node_t* node;
	node = malloc(sizeof(node_t));

	node->data = NULL;
	node->next = NULL;

	return node;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*  inputs:                                                                *
* - node_t* next, void* data                                              *
*                                                                         *
*  outputs:                                                               *
* - node_t*                                                               *
**************************************************************************/

node_t* construct_node_overload1(node_t* next, void* data)
{
	node_t* node;
	node = malloc(sizeof(node_t));

	node->data = data;
	node->next = next;

	return node;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*  inputs:                                                                *
* - node_t* node                                                          *
*                                                                         *
*  outputs:                                                               *
* - none                                                                  *
**************************************************************************/
void destruct_node(node_t* node)
{
	free(node->data);
	free(node);
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
*  - node_t* node                                                         *
*   outputs:                                                              *
*  - none                                                                 *
**************************************************************************/
void* get_data(node_t* node)
{
	return node->data;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - node_t* node                                                          *
*   outputs:                                                              *
*   node_t* node                                                          *
**************************************************************************/
node_t* get_next(node_t* node)
{
	return node->next;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - node_t* node, node_t* next                                            *
* - outputs:                                                              *
*   none                                                                  *
**************************************************************************/
void set_next(node_t* node, node_t* next)
{
	node->next = next;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - destruct_data_function destruct_data_fn, unsigned int element_size    *
*   outputs:                                                              *
*  -linked_list_t*                                                        *
**************************************************************************/
linked_list_t* construct_linked_list(destruct_data_function destruct_data_fn, unsigned int element_size)
{
	linked_list_t* list = malloc(sizeof(linked_list_t));
	list->head = NULL;
	list->length = 0;
	list->destruct_data_fn = destruct_data_fn;
	list->element_size = element_size;

	return list;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list                                                   *
*   outputs:                                                              *
* - none                                                                  *
**************************************************************************/
void destruct_linked_list(linked_list_t* list)
{
	node_t* current = list->head;
	node_t* it = list->head;

	while (it != NULL)
	{
		it = get_next(it);
		if (list->destruct_data_fn != NULL)
			list->destruct_data_fn(current->data);
		else
			destruct_node(current);
		current = it;
	}
	free(list);
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list                                                   *
*   outputs:                                                              *
* - int                                                                   *
**************************************************************************/
int is_list_empty(linked_list_t* list)
{
	return list->length == 0;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list, void* data                                       *
*   outputs:                                                              *
* - none                                                                  *
**************************************************************************/
void push_front(linked_list_t* list, void* data)
{
	unsigned int element_size = get_element_size(list);
	void* data_d = malloc(element_size);
	unsigned int i;
	for (i = 0; i < element_size; i++)
		*((char*)data_d + i) = *((char*)data + i);

	node_t* node = construct_node_overload1(list->head, data_d);
	list->head = node;
	++(list->length);
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list, void* data                                       *
*   outputs:                                                              *
* - node_t*                                                               *
**************************************************************************/
void push_back(linked_list_t* list, void* data)
{
	unsigned int element_size = get_element_size(list);
	void* data_d = malloc(element_size);
	unsigned int i;
	for (i = 0; i < element_size; i++)
		*((char*)data_d + i) = *((char*)data + i);

	node_t* node = construct_node_overload1(NULL, data_d);

	if (list->head == NULL)
		list->head = node;
	else
	{
		node_t* current = list->head;
		while (get_next(current) != NULL)
			current = get_next(current);
		set_next(current, node);
	}
	++(list->length);
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list                                                   *
*   outputs:                                                              *
* - none                                                                  *
**************************************************************************/
void pop_front(linked_list_t* list)
{
	node_t* front = list->head;
	list->head = front->next;
	destruct_node(front);
	--(list->length);
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list                                                   *
*   outputs:                                                              *
* - unsigned int                                                          *
**************************************************************************/
unsigned int get_element_size(linked_list_t* list)
{
	return list->element_size;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list                                                   *
*   outputs:                                                              *
* - unsigned int                                                          *
**************************************************************************/
unsigned int get_length(linked_list_t* list)
{
	return list->length;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list, void* data                                       *
*   outputs:                                                              *
* - unsigned int                                                          *
**************************************************************************/
unsigned int get_index(linked_list_t* list, void* data)
{
	unsigned int i;
	for (i = 0; i < get_length(list); i++)
	{
		if (get_by_index(list, i) == data)
			return i;
	}
	
	return -1;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list, unsigned int index                               *
*   outputs:                                                              *
* - none                                                                  *
**************************************************************************/
void* get_by_index(linked_list_t* list, unsigned int index)
{
	if (index > get_length(list) - 1)
		return NULL;

	node_t* current = list->head;
	unsigned int counter = 0;
	while (counter < get_length(list))
	{
		if (counter == index)
			return get_data(current);
		current = get_next(current);
		++counter;
	}
	
	return NULL;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list, unsigned int index                               *
*   outputs:                                                              *
* - int                                                                   *
**************************************************************************/
int delete_by_index(linked_list_t* list, unsigned int index)
{
	if (index > get_length(list) - 1)
		return 0;

	if (index == 0)
		pop_front(list);

	node_t* current = list->head;
	unsigned int counter = 0;
	while (counter < get_length(list))
	{
		if (counter == index - 1)
		{
			free(current->next->data);
			current->next = current->next->next;
			--(list->length);
			return 1;
		}
		current = get_next(current);
		++counter;
	}

	return 0;
}

/**************************************************************************
*                                                                         *
*                                                                         *
*                                                                         *
*   inputs:                                                               *
* - linked_list_t* list, void* data                                       *
*   outputs:                                                              *
* - int                                                                   *
**************************************************************************/
int delete_data(linked_list_t* list, void* data)
{
	unsigned int index = get_index(list, data);
	return delete_by_index(list, index);
}