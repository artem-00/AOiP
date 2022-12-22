#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "Header.h"
#define SIZE (argc-1)

int main(int argc, char** argv)
{
    char** string = (char**)malloc((argc) * sizeof(char*));
    for (int i = 0; i < (argc); i++)
    {
        string[i] = (char*)calloc(1, sizeof(char));
    }
    copi_strings(argc, string, argv);
    printf("\nMasive:");
    print_string(string, SIZE);
    insertion_sort(string, SIZE);
    printf("\nResult:");
    print_string(string, SIZE);
    free(string);
    return 0;
}