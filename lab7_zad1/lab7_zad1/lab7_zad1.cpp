#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "namer.h"

int main() {
	int length_str;
	int length_world = 0;// длина строки
	char* str = input_string(&length_str); // считываем динамическую строку	
	int k = 0;
	printf("You write: '%s'\nSymbols: %d\n", str, length_str); // выводим строку и её длину
	k = input_k(k);
	del_worlds(str,length_str,  k);
	printf("_________________________\nCorrect string: '%s'\n_________________________\n%d", str, length_str);


	free(str);
	return 0;
}




