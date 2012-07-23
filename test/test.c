#include <stdio.h>
#include <stdlib.h>
#include "ml_list.h"

int main()
{
    ml_list list = ml_list_new(sizeof(int));
    int i;

    for (i = 0; i < 100; i++) {
	ml_list_push_front(list, &i);
    }
    
    if (ml_list_empty(list)) {
	printf("empty\n");
    } else {
	printf("size: %d\n", (int) ml_list_size(list));
	ml_list_clear(list);
	if (ml_list_empty(list))
	    printf("size: %d\n", (int) ml_list_size(list));
    }
    
    ml_list_delete(&list);

    return 0;
}
