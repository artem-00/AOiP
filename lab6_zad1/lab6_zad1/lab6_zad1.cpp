#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"name.h"

int main()
{
	int* array = 0;
	int size_array = 0, choice = 0;
	int start_bouble = 0, end_bouble = 0, start_Shell = 0, end_Shell = 0;
	printf("Enter a size of the array: ");
	size_array = array_size(size_array);
	memory(&array, size_array);
	final_output(array, size_array, choice);
	time_sort_Shell(array, size_array, start_Shell, end_Shell);
	time_sort_bouble(array, size_array, start_bouble, end_bouble);
	//choise_sort(array, size_array, start_Shell, end_Shell, start_bouble, end_bouble);



	return 0;
}