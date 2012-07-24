#include "ml_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static ml_list new_element(const void *, size_t);
static void delete_element(ml_list);

/* Constructor and destructor */

ml_list ml_list_new(size_t size)
{
    size_t *obj = &size;
    ml_list sentinel = new_element(obj, sizeof(size_t));

    sentinel->next = sentinel;
    sentinel->prev = sentinel;

    return sentinel;
}

void ml_list_delete(ml_list *list)
{
    ml_list_clear(*list);
    delete_element(*list);
}



/* Iterators */

ml_iterator_list ml_list_begin(ml_list list)
{
    return (ml_iterator_list) list->next;
}

ml_iterator_list ml_list_end(ml_list list)
{
    return (ml_iterator_list) list;
}

ml_iterator_list ml_list_rbegin(ml_list list)
{
    return (ml_iterator_list) list->prev;
}

ml_iterator_list ml_list_rend(ml_list list)
{
    return (ml_iterator_list) list;
}

/* Capacity */

bool ml_list_empty(ml_list list)
{
    return list->next != list ? false : true;
}

size_t ml_list_size(ml_list list)
{
    size_t size = 0;
    ml_iterator_list it = NULL;
    
    for (it = ml_list_begin(list); it != ml_list_end(list); 
	 ml_iterator_list_next(&it))
	++size;

    return size;
}



/* Modifiers */

void ml_list_push_back(ml_list list, const void *obj)
{
    size_t *size = (size_t *) list->object;

    ml_list new_elem = new_element(obj, *size);
    ml_list last_elem = list->prev;
    
    last_elem->next = new_elem;
    new_elem->prev = last_elem;
    new_elem->next = list;
    list->prev = new_elem;
}

void ml_list_push_front(ml_list list, const void *obj)
{
    size_t *size = (size_t *) list->object;

    ml_list new_elem = new_element(obj, *size);
    ml_list first_elem = list->next;

    first_elem->prev = new_elem;
    new_elem->next = first_elem;
    new_elem->prev = list;
    list->next = new_elem;
}

void ml_list_pop_back(ml_list list)
{
    ml_list last = list->prev;
    list->prev = last->prev;
    last->prev->next = list;

    delete_element(last);
}

void ml_list_pop_front(ml_list list)
{
    ml_list first = list->next;
    list->next = first->next;
    first->next->prev = list;

    delete_element(first);
}

void ml_list_clear(ml_list list)
{
    while (!ml_list_empty(list))
	ml_list_pop_back(list);
}



/* private functions*/

static ml_list new_element(const void *obj, size_t size)
{
    ml_list list = (ml_list) malloc(sizeof(struct _ml_list));
    list->object = malloc(size);
    memmove(list->object, obj, size);
    return list;
}

static void delete_element(ml_list el)
{
    free(el->object);
    free(el);
}
