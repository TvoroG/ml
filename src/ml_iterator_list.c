#include "ml_iterator_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ml_iterator_list ml_iteartor_list_new(ml_list list)
{
    return NULL;
}

void ml_iterator_list_next(ml_iterator_list *it) 
{
    *it = (*it)->next;
}

void *ml_iterator_list_get(ml_iterator_list it)
{
    return it->object;
}

void ml_iterator_list_set(ml_iterator_list it, ml_list list, const void *obj)
{
    size_t *size = (size_t *) list->object;
    memmove(it->object, obj, *size);
}
