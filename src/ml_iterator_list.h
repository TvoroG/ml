#ifndef _ML_ITERATOR_LIST_
#define _ML_ITERATOR_LIST_

#include "ml_list.h"

ml_iterator_list ml_iterator_list_new(ml_list);
void ml_iterator_list_next(ml_iterator_list *);
void *ml_iterator_list_get(ml_iterator_list);
void ml_iterator_list_set(ml_iterator_list, ml_list, const void *);
#endif
