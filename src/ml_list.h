#ifndef _ML_LIST_
#define _ML_LIST_

#include <stdio.h>
#include <stdbool.h>

struct _ml_list {
    struct _ml_list *prev;
    void *object;
    struct _ml_list *next;
};

typedef struct _ml_list *ml_list;
typedef struct _ml_list *ml_iterator_list;

/* Constructor and destructor: */
ml_list ml_list_new(size_t);
void ml_list_delete(ml_list *);

/* Iterators: */
ml_iterator_list ml_list_begin(ml_list);
ml_iterator_list ml_list_end(ml_list);
ml_iterator_list ml_list_rbegin(ml_list);
ml_iterator_list ml_list_rend(ml_list);

/* Capacity: */
bool ml_list_empty(ml_list);
size_t ml_list_size(ml_list);

/* Modifiers: */
void ml_list_push_back(ml_list, const void *);
void ml_list_push_front(ml_list, const void *);
void ml_list_pop_back(ml_list);
void ml_list_pop_front(ml_list);
void ml_list_clear(ml_list);

#endif
