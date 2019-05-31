#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**************************************************************************
*   The default constructor for a node                                    
*   it allocates memory for the a node                                    
*   and sets the data and next pointer to NULL                            
*   inputs:                                                               
* - void                                                                  
*   outputs:                                                              
* - node_t*                                                               
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
*  The alternate constructor that initialises the fields with value      
*  passed in                                                                       
*                                                                         
*  inputs:                                                                
* - node_t* next, void* data                                              
*                                                                         
*  outputs:                                                               
* - node_t*                                                               
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
*  The default way to destruct a node                                                                       
*  frees up whatever the data is pointing to and frees up memory                      
*  allocated to itself. But does not free next node                                                                     
*  inputs:                                                                
* - node_t* node                                                          
*                                                                         
*  outputs:                                                               
* - void                                                                  
**************************************************************************/
void destruct_node(node_t* node)
{
	free(node->data);
	free(node);
}

/**************************************************************************
*   Returns a void pointer to data                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
*  - node_t* node                                                         
*   outputs:                                                              
*  - void                                                                 
**************************************************************************/
void* get_data(node_t* node)
{
	return node->data;
}

/**************************************************************************
*   Returns the next opinter to next                                                                      
*                                                                         
*                                                                         
*   inputs:                                                              
* - node_t* node                                                          
*   outputs:                                                              
* - node_t* node                                                          
**************************************************************************/
node_t* get_next(node_t* node)
{
	return node->next;
}

/**************************************************************************
*   set the next node to be the one passed in                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - node_t* node, node_t* next                                            
*   outputs:                                                              
* - void                                                                  
**************************************************************************/
void set_next(node_t* node, node_t* next)
{
	node->next = next;
}

/**************************************************************************
*   Alternate constructor for a linked list                                                                      
*   Takes the destruct function and element size                                                                      
*   Allocates memory for all fields and initialises them with proper value                                                                     
*   inputs:                                                              
* - destruct_data_function destruct_data_fn, unsigned int element_size    
*   outputs:                                                              
*  -linked_list_t*                                                        
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
*   Destruct linked list from the head node to the tail                                                                    
*   Use the destruct function if provided with one                                                                      
*   Or use the default node destructor if not provided with destruct func                                                                      
*   inputs:                                                               
* - linked_list_t* list                                                   
*   outputs:                                                              
* - void                                                                 
**************************************************************************/
void destruct_linked_list(linked_list_t* list)
{
	node_t* current = list->head;
	/*node_t* it keeps track of the node that's going to be deleted*/
	node_t* it = list->head;

	while (it != NULL)
	{
		/*Store the next node before deleting it*/
		it = get_next(it);

		/*With or without desctruct data function*/
		if (list->destruct_data_fn != NULL)
		{
			/*Frees up data data using destruct function*/
			/*Frees up node normally*/
			list->destruct_data_fn(current->data);
			free(current);
		}
		else
			/*Frees up data and node normally using node destructor*/
			destruct_node(current);

		/*Set current to the next node*/
		current = it;
	}
	/*Frees list in the end*/
	free(list);
}

/**************************************************************************
*   Checks if list length is 0                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - linked_list_t* list                                                   
*   outputs:                                                              
* - int                                                                   
**************************************************************************/
int is_list_empty(linked_list_t* list)
{
	return list->length == 0;
}

/**************************************************************************
*   Adds a node in front of the linked list                                                                      
*   First allocates memory for the node and construct it                                                                      
*   Then set the head node to be it and increment length by 1                                                                      
*   inputs:                                                               
* - linked_list_t* list, void* data                                       
*   outputs:                                                              
* - void                                                                 
**************************************************************************/
void push_front(linked_list_t* list, void* data)
{
	/*Allocate memory for data*/
	unsigned int element_size = get_element_size(list);
	void* data_d = malloc(element_size);
	/*Copies all data the pointer is pointing to*/
	unsigned int i;
	for (i = 0; i < element_size; i++)
		*((char*)data_d + i) = *((char*)data + i);

	/*Construct the new node*/
	node_t* node = construct_node_overload1(list->head, data_d);
	/*Set head node to be the new one so it's at the front*/
	list->head = node;
	/*Increment length*/
	++(list->length);
}

/**************************************************************************
*   Adds a node at the end of the linked list                                                                      
*   First allocates memory for the node and construct it                                                                       
*   Travel through the whole list and set the new node at the end                                                                      
*   inputs:                                                               
* - linked_list_t* list, void* data                                       
*   outputs:                                                              
* - void                                                               
**************************************************************************/
void push_back(linked_list_t* list, void* data)
{
	/*Allocate memory for data*/
	unsigned int element_size = get_element_size(list);
	void* data_d = malloc(element_size);
	/*Copies all data the pointer is pointing to*/
	unsigned int i;
	for (i = 0; i < element_size; i++)
		*((char*)data_d + i) = *((char*)data + i);

	/*Construct the new node*/
	node_t* node = construct_node_overload1(NULL, data_d);

	/*Put the node at the end*/
	if (list->head == NULL)
		list->head = node;
	else
	{
		node_t* current = list->head;
		while (get_next(current) != NULL)
			current = get_next(current);
		set_next(current, node);
	}
	/*Increment length*/
	++(list->length);
}

/**************************************************************************
*   Deletes the node at the front                                                                      
*   Use desctruct function if provieded                                                                      
*   Decrement length by 1                                                                      
*   inputs:                                                               
* - linked_list_t* list                                                   
*   outputs:                                                              
* - void                                                                 
**************************************************************************/
void pop_front(linked_list_t* list)
{
	/*Similar logic refering to destruct_linked_list function*/
	node_t* front = list->head;
	list->head = front->next;
	if (list->destruct_data_fn != NULL)
	{
		list->destruct_data_fn(front->data);
		free(front);
	}
	else
		destruct_node(front);
	--(list->length);
}

/**************************************************************************
*   Returns the element size                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - linked_list_t* list                                                   
*   outputs:                                                              
* - unsigned int                                                          
**************************************************************************/
unsigned int get_element_size(linked_list_t* list)
{
	return list->element_size;
}

/**************************************************************************
*   Returns list length                                                                      
*                                                                         
*                                                                         
*   inputs:                                                               
* - linked_list_t* list                                                   
*   outputs:                                                              
* - unsigned int                                                          
**************************************************************************/
unsigned int get_length(linked_list_t* list)
{
	return list->length;
}

/**************************************************************************
*   returns the index of the node if it's data pointer and                                                                      
*   the data pointer passed in are pointing the same memory                                                                      
*                                                                         
*   inputs:                                                               
* - linked_list_t* list, void* data                                       
*   outputs:                                                              
* - unsigned int                                                          
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
*   returns the data pointer at a specific index                                                                      
*   by a simple traversal                                                                      
*                                                                         
*   inputs:                                                               
* - linked_list_t* list, unsigned int index                               
*   outputs:                                                              
* - void                                                                
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
*   Deletes a node at given index                                                                     
*                                                                        
*                                                                         
*   inputs:                                                               
* - linked_list_t* list, unsigned int index                               
*   outputs:                                                              
* - int                                                                   
**************************************************************************/
int delete_by_index(linked_list_t* list, unsigned int index)
{
	/*suppose length is 5, the largest index is 4*/
	if (index > get_length(list) - 1)
		return 0;

	/*If it's the first element to delete, just pop_front*/
	if (index == 0)
		pop_front(list);

	node_t* current = list->head;
	unsigned int counter = 0;
	while (counter < get_length(list))
	{
		/*Once it reaches the node before the node to delete*/
		if (counter == index - 1)
		{
			/*Store the node that's gonna be the next element after delete*/
			node_t* next_after_delete = current->next->next;

			/*If destruct function is provided*/
			if (list->destruct_data_fn != NULL)
			{
				/*Destruct the next node data with destruct func*/
				/*Free up the node normally*/
				list->destruct_data_fn(current->next->data);
				free(current->next);
			}
			else
				/*delete the next node normally*/
				destruct_node(current->next);

			/*Set the new next node to be the one stored before delete*/
			current->next = next_after_delete;

			/*Decrement length by 1*/
			--(list->length);

			/*function ends with true*/
			return 1;
		}
		current = get_next(current);
		++counter;
	}

	/*Returns false that means no element has been deleted*/
	return 0;
}

/**************************************************************************
*   delete the give data in the list                                                                      
*   if the data IS EXACTLY the data in the list(same memory address)                                                                      
*                                                                         
*   inputs:                                                               
* - linked_list_t* list, void* data                                       
*   outputs:                                                              
* - int                                                                   
**************************************************************************/
int delete_data(linked_list_t* list, void* data)
{
	unsigned int index = get_index(list, data);
	return delete_by_index(list, index);
}