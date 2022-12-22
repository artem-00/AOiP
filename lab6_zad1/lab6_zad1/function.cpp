#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

int array_size(int size_array) {
	while (scanf_s("%d", &size_array) == 0 || size_array < 1 || getchar() != '\n') {
		printf("\nYou need to write a right numbers\n");
		rewind(stdin);
	}
	return size_array;
}
void memory(int** array, int size_array) {
	*array = (int*)malloc(size_array * sizeof(int));
}
int choice_rand_manually(int choice) {
	printf("\n0 - manually input, 1 - random input: ");
	while (scanf_s("%d", &choice) == 0 || choice < 0 || choice > 1 || getchar() != '\n') {
		printf("\nTry again pls))\n( 0 or 1 )");
		rewind(stdin);
	}
	return choice;
}
void array_input(int* array, int size_array) {
	for (int i = 0; i < size_array; i++) {
		printf("Enter a %d element: ", i + 1);
		while (scanf_s("%d", &array[i]) == 0 || getchar() != ' ') {
			printf("\nTry again pls))\n");
			rewind(stdin);
		}
	}
}
void array_input_random(int* array, int size_array) {
	for (int i = 0; i < size_array; i++)
		array[i] = rand() % 10;
}
void final_output(int* array, int size_array, int choice) {
	choice = choice_rand_manually(choice);
	if (choice == 0)
		array_input(array, size_array);
	else
		array_input_random(array, size_array);

}
void print_array(int* array, int size_array) {
	for (int i = 0; i < size_array; i++)
		printf("%d ", array[i]);
	printf("\n");
}
void sort_Shell(int* array, int size_array) {
	int step;
	int buff;
	for (step = size_array / 2; step > 0; step /= 2)
		for (int i = step; i < size_array; i++)
		{
			int j;
			buff = array[i];
			for (j = i; j >= step; j -= step)
			{
				if (buff < array[j - step])
					array[j] = array[j - step];
				else
					break;
			}
			array[j] = buff;
		}
}
void sort_bouble(int* array, int size_array) {
	int i, j, buff;
	for (i = 0; i < size_array - 1; i++) {
		for (j = 0; j < size_array - 1; j++) {
			if (array[j] < array[j + 1]) {
				buff = array[j];
				array[j] = array[j + 1];
				array[j + 1] = buff;
			}
		}
	}
}
void time_sort_Shell(int* array, int size_array, int start_Shell, int end_Shell) {
	int time_Shell;
	start_Shell = clock();
	sort_Shell(array, size_array);
	end_Shell = clock();
	time_Shell = end_Shell - start_Shell;
	printf("Time Shell sort: %d\n",time_Shell);
}
void time_sort_bouble(int* array, int size_array, int start_bouble, int end_bouble) {
	int time_bouble;
	start_bouble = clock();
	sort_bouble(array, size_array);
	end_bouble = clock();
	time_bouble = end_bouble - start_bouble;
	printf("Time bouble sort: %d\n", time_bouble);

}
int copying_array(int* array, int* copi_array, int size_array) {
	memory(&copi_array, size_array);
	for (int i1 = 0, i2 = 0; i1 < size_array;i1++, i2++)
		copi_array[i2] = array[i1];
	return *copi_array;
}

//void choise_sort(int* array, int size_array, int start_Shell, int end_Shell, int start_bouble, int end_bouble) {
//	int copi_array[] = {0};
//	int choice_sort;
//	int time_bouble = 0, time_Shell = 99;
//	printf("select sorting:\n1.Shell sort\n2.Bouble sort\nYou choise: ");
//	while (scanf_s("%d", &choice_sort) == 0 || choice_sort < 1 || choice_sort > 2 || getchar() != '\n') {
//		printf("\nTry again pls))\n( 0 or 1 )");
//		rewind(stdin);
//	}
//	copying_array(array, copi_array, size_array);
//	if (choice_sort == 1) {
//		time_Shell = time_sort_Shell(array, size_array, start_Shell, end_Shell, time_Shell);
//		printf("\nShell sort time: %d\n", time_Shell);
//		time_sort_bouble(copi_array, size_array, start_bouble, end_bouble, time_bouble);
//		printf("\nbouble sort time: %d\n", time_bouble);
//	}
//	else {
//		time_sort_bouble(array, size_array, start_bouble, end_bouble, time_bouble);
//	}
//
//}

