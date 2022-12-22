#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

void memory_task1(int** array, int size)
{
    *array = (int*)calloc(size, sizeof(int));
}

void rand_array_task1(int* array, int size)
{
    srand(time(0));

    for (int i = 0; i < size; i++)
        array[i] = rand() % 201 - 101;
}

int size_input_check_task1(int n)
{
    printf("Input size of the array:\n");

    int lastchar;

    while (scanf_s("%d", &n) != 1 || ((lastchar = getchar()) != '\n') && lastchar != ' ')
    {
        printf("Try again =)");
        rewind(stdin);
    }

    return n;
}

void print_array_task1(int* array, int size)
{
    for (int i = 0; i < size; i++)
        printf("%4d ", *(array + i));
}

void bouble_sort(int col_elem, int* mass, double*** time_spent)
{
    int buf;
    clock_t begin = clock();

    for (int i = col_elem - 1; i >= 0; i--)
    {
        int noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                buf = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = buf;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }

    clock_t end = clock();
    (***time_spent) = (double)(end - begin) / CLOCKS_PER_SEC;
}

void ShellSort_up(int col_elem, int* mass, double*** time_spent)
{
    int step, buf;
    clock_t begin = clock();

    for (step = col_elem / 2; step > 0; step /= 2)
        for (int i = step; i < col_elem; i++)
        {
            int j;
            buf = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (buf < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = buf;
        }

    clock_t end = clock();
    (***time_spent) = (double)(end - begin) / CLOCKS_PER_SEC;
}

void ShellSort_down(int col_elem, int* mass)
{
    int step, buf;

    for (step = col_elem / 2; step > 0; step /= 2)
        for (int i = step; i < col_elem; i++)
        {
            int j;
            buf = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (buf > mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = buf;
        }
}

int col_need_elem(int* array, int size, int col_elem)
{
    for (int i = 0; i < size; i++)
        if (array[i] % 2 == 0 && array[i] > 0)
            col_elem++;

    return col_elem;
}

void take_elements(int* array, int* mass, int size)
{
    int j = 0;

    for (int i = 0; i < size; i++)
        if (array[i] % 2 == 0 && array[i] > 0)
        {
            mass[j] = array[i];
            j++;
        }
}

void return_the_elements(int* array, int size, int* copi_array)
{
    int j = 0;

    for (int i = 0; i < size; i++)
        if (array[i] % 2 == 0 && array[i] > 0)
        {
            array[i] = copi_array[j];
            j++;
        }

}

void sort(int col_elem, int* mass, double** time_spend)
{
    int n = 0, k = 0;
    /*double time;*/


    n = choice(n);

    if (n == 1)
        bouble_sort(col_elem, mass, &time_spend);

    if (n == 2)
        ShellSort_up(col_elem, mass, &time_spend);
    //*time2 = time;
}

void choice_case(int* array, int* mass, int size, int col_elem, double* time_spend)
{
    int k = 0;
    /*double time2;*/
    printf("\nWhich sort option do you want to use:\n1.Bouble sort.\n2.Shell sort.\nYour choice:");
    k = choice(k);

    if (k == 1)
    {
        take_elements(array, mass, size);

  /*      printf("\nElements for sort:\n");
        print_array_task1(mass, col_elem);*/

        ShellSort_down(col_elem, mass);

        //printf("\nElements for sort:\n");
        //print_array_task1(mass, col_elem);

        return_the_elements(array, size, mass);

        printf("\nSorted array:\n");
        print_array_task1(array, size);

        take_elements(array, mass, size);

        sort(col_elem, mass, &time_spend);

        return_the_elements(array, size, mass);
    }
    if (k == 2)
    {
        take_elements(array, mass, size);

        bouble_sort(col_elem, mass, &time_spend);

        return_the_elements(array, size, mass);
    }

    /* *time_spend = time2;*/
}
int choice(int arg) {
    while (scanf_s("%d", &arg) == 0 || getchar() != '\n') {
        printf("\nYou need to write a right numbers\n");
        rewind(stdin);
    }
    return arg;
}