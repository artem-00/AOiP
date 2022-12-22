#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
#include"name.h"

int main()
{
    int* array = 0;
    int* copi_array = 0;
    int size = 0, col_elem = 0;
    double time_spend = 0;

    size = size_input_check_task1(size);

    memory_task1(&array, size);
    rand_array_task1(array, size);

    col_elem = col_need_elem(array, size, col_elem);

    print_array_task1(array, size);

    memory_task1(&copi_array, col_elem);

    choice_case(array, copi_array, size, col_elem, &time_spend);

    printf("\nSorted array:\n");
    print_array_task1(array, size);

    printf("\nThe elapsed time is %0.6f seconds", time_spend);

    free(array);
    return 0;
}