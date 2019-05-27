#pragma once

typedef struct node
{
	void* data;
	struct node* next;
}
node_t;

typedef struct linked_list
{
	node_t* head;
	unsigned int length;
}
linked_list_t;

typedef struct iterator
{
	linked_list_t* current_list;
	unsigned int position;
}
iterator_t;

node_t* construct_node(void);
node_t* construct_node_overload1(node_t*, void*);
void destruct_node(node_t*);
void* get_data(node_t*);
node_t* get_next(node_t*);
void set_next(node_t*, node_t*);

linked_list_t* construct_linked_list(void);
void destruct_linked_list(linked_list_t*);
int is_list_empty(linked_list_t*);
int equals(void* data_a, void* data_b);
void push_front(linked_list_t*, void*, unsigned int);
void push_back(linked_list_t*, void*, unsigned int);
void pop_front(linked_list_t*);
unsigned int get_length(linked_list_t*);
iterator_t* get_iterator(linked_list_t*, void*);
void* get_by_index(linked_list_t*, unsigned int);
int delete_by_index(linked_list_t*, unsigned int);
iterator_t* begin(linked_list_t*);
iterator_t* end(linked_list_t*);

iterator_t* construct_iterator(void);
iterator_t* construct_iterator_overload1(linked_list_t*, unsigned int);