#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

node_t* construct_node(void)
{
	node_t* node;
	node = malloc(sizeof(node_t));

	node->data = NULL;
	node->next = NULL;

	return node;
}

node_t* construct_node_overload1(node_t* next, void* data)
{
	node_t* node;
	node = malloc(sizeof(node_t));

	node->data = data;
	node->next = next;

	return node;
}

void destruct_node(node_t* node)
{
	free(node->data);
	free(node);
}

void* get_data(node_t* node)
{
	return node->data;
}

node_t* get_next(node_t* node)
{
	return node->next;
}

void set_next(node_t* node, node_t* next)
{
	node->next = next;
}

linked_list_t* construct_linked_list(void)
{
	linked_list_t* list;
	list = malloc(sizeof(linked_list_t));
	list->head = NULL;
	list->length = 0;

	return list;
}

void destruct_linked_list(linked_list_t* list)
{
	node_t* current = list->head;
	node_t* it = list->head;

	while (get_next(it) != NULL)
	{
		it = get_next(it);
		destruct_node(current);
		current = it;
	}
	destruct_node(it);
	free(list);
}

int is_list_empty(linked_list_t* list)
{
	return list->length == 0;
}

void push_front(linked_list_t* list, void* data, unsigned int size)
{
	void* data_d = malloc(size);
	unsigned int i;
	for (i = 0; i < size; i++)
		*((char*)data_d + i) = *((char*)data + i);

	node_t* node = construct_node_overload1(list->head, data_d);
	list->head = node;
	++(list->length);
}

void push_back(linked_list_t* list, void* data, unsigned int size)
{
	void* data_d = malloc(size);
	unsigned int i;
	for (i = 0; i < size; i++)
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

void pop_front(linked_list_t* list)
{
	node_t* front = list->head;
	list->head = front->next;
	destruct_node(front);
	--(list->length);
}

unsigned int get_length(linked_list_t* list)
{
	return list->length;
}

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

int delete_data(linked_list_t* list, void* data)
{
	unsigned int index = get_index(list, data);
	return delete_by_index(list, index);
}