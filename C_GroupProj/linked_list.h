#pragma once

typedef void(*destruct_data_function)(void*);

typedef struct node
{
	void* data;
	struct node* next;
}
node_t;

typedef struct linked_list
{
	node_t* head;
	unsigned int element_size;
	unsigned int length;
	destruct_data_function destruct_data_fn;
}
linked_list_t;

node_t* construct_node(void);
node_t* construct_node_overload1(node_t*, void*);
void destruct_node(node_t*);
void* get_data(node_t*);
node_t* get_next(node_t*);
void set_next(node_t*, node_t*);

linked_list_t* construct_linked_list(destruct_data_function, unsigned int);
void destruct_linked_list(linked_list_t*);
int is_list_empty(linked_list_t*);
void push_front(linked_list_t*, void*);
void push_back(linked_list_t*, void*);
void pop_front(linked_list_t*);
unsigned int get_element_size(linked_list_t*);
unsigned int get_length(linked_list_t*);
unsigned int get_index(linked_list_t*, void*);
void* get_by_index(linked_list_t*, unsigned int);
int delete_by_index(linked_list_t*, unsigned int);
int delete_data(linked_list_t*, void*);