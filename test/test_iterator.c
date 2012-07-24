#include <stdio.h>
#include "ml_list.h"
#include "ml_iterator_list.h"

int main()
{
    ml_list list = ml_list_new(sizeof(int));
    ml_iterator_list it = NULL;
    int i;

    for (i = 0; i < 100; i++) {
	ml_list_push_back(list, &i);
    }

    for (it = ml_list_rbegin(list); it != ml_list_rend(list); 
	 ml_iterator_list_rnext(&it)) {
	
	int *d = ml_iterator_list_get(it);
	printf("%d ", *d);
    }
    printf("\n");

    ml_list_delete(&list);

    return 0;
}
