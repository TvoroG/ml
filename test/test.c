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

    int *d = (int *) ml_list_back(list);
    *d = 100;
    d = (int *) ml_list_back(list);
    printf("%d\n", *d);
    
    ml_list_delete(&list);

    return 0;
}
