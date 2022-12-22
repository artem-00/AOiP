#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void copi_strings(int argc, char** str, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        int j = 0;
        while (str[i][j] != '=')
        {
            str[i - 1][j] = argv[i][j];
            j++;

            if (j != 0)
            {
                char* storer;
                storer = (char*)realloc(str[i - 1], (j + 1) * sizeof(char));
                if (str[i - 1] != NULL)
                    str[i - 1] = storer;

            }
        }
        str[i - 1][j + 1] = '\0';
    }
}

void memory(char*** str, int argc)
{
    *str = (char**)malloc((argc) * sizeof(char*));
    for (int i = 0; i < (argc); i++)
    {
        *(str)[i] = (char*)calloc(1, sizeof(char));
    }
}

int len(char* str)
{
    int i = 0;
    while (*(str + i) != '\0')
    {
        i++;
    }
    return i;
}

int col_word(char* str)
{
    int size_word = 0, number_word = 0;
    for (int i = 0; i < len(str); i++)
    {
        size_word = 0;
        if ((*(str + i) >= 'A' && *(str + i) <= 'Z') || (*(str + i) >= 'a' && *(str + i) <= 'z'))
        {
            int j = i;
            while (((*(str + j) >= 'A' && *(str + j) <= 'Z') || (*(str + j) >= 'a' && *(str + j) <= 'z')))
            {
                size_word++;
                j++;
            }

            if (size_word % 2 == 0)
                number_word++;

            i = j;
        }

    }
    /*printf("\n%s:\nnum = %d\n", string, number_word);*/
    return number_word;
}

void insertion_sort(char** str, int size) {
    for (int i = 1; i < size; i++) {
        char* temp = str[i];
        int j = i - 1;
        while (j >= 0 && col_word(temp) > col_word(str[j])) {
            str[j + 1] = str[j];
            j--;
        }
        str[j + 1] = temp;
    }
}

void print_string(char** array, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (*(array + i) != NULL)
        {
            printf("%s", *(array + i));
            printf("\n       ");
        }
    }
}