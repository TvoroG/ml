#ifndef _ML_LIST_
#define _ML_LIST_

#include <stdio.h>

struct _ml_list {
    struct _ml_list *prev;
    void *object;
    struct _ml_list *next;
};

typedef struct _ml_list *ml_list;
typedef struct _ml_list *ml_iterator_list;

ml_list ml_list_new(size_t);
void ml_list_push_back(ml_list, const void *);
void ml_list_push_front(ml_list, const void *);
void ml_list_pop_back(ml_list);
void ml_list_pop_front(ml_list);
void ml_list_print(ml_list);

ml_iterator_list ml_list_begin(ml_list);
ml_iterator_list ml_list_end(ml_list);

#endif
