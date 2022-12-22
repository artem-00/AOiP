#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

char* input_string(int* length_str) {
	*length_str = 0;
	int length = 1;
	char* str = (char*)malloc(sizeof(char));
	printf("Enter the string: ");
	char i = getchar();
	while (i != '\n') {
		str[(*length_str)++] = i;
		if (*length_str >= length) {
			length *= 2;
			str = (char*)realloc(str, length * sizeof(char));
		}
		i = getchar();
	}
	str[*length_str] = ' ';
	str[*length_str + 1] = '\0';
	return str;
}
int input_k(int k) {
	printf("Enter the maksimum number of letters in a words: ");
	while (scanf_s("%d", &k) == 0 || getchar() != '\n') {
		printf("\nYou need to write a correct numbers\n");
		rewind(stdin);
	}
	return k;
}
int found_col_world(char* str, int col_world, int length_str) {
	for (int j = 0; j <= length_str;j++) {
		if (str[j] == ' ' || str[j] == '\t' || str[j] == '\0')
			col_world++;
	}
	printf("Number of words entered: %d\n", col_world);
	return col_world;
}
void delete_world(char* str, int length_str, int i, int length_world) {
	int k = i;
	//if (cnt > 0) {
	while (str[k] != '\0')
	{
		str[k] = str[k + length_world + 1];
		k++;
	}
	//}
}
int leter_in_world(char* str, int i, int fl, int length_str) {
	int j = i;
	for (j; j < length_str + 1; j++) {
		if (str[j] == ' ' || str[j] == '\t' || str[j] == '\0')
			break;
		fl++;
	}
	return fl;
}
int new_length_str(char* str, int length_str, int length_world) {
	length_str -= length_world;
	str = (char*)realloc(str, length_str * sizeof(char));
	str[length_str] = '\0';
	return length_str;
}
//int delete_world_main(char* str, int k, int length_str) {
//	int length_world, i, col_world = 0;
//	col_world = found_col_world(str, col_world, length_str);
//	for (int i = 0, j = 0; j < col_world; i += length_world + 1, j++) {
//		length_world = 0;
//		length_world = leter_in_world(str, i, length_world, length_str);
//		if (length_world > k) {
//			delete_world(str, length_str, i, length_world);
//			length_str = new_length_str(str, length_str, length_world);
//		}
//	}
//	return length_str;
//} 
//void del_world(char* str, int length_str, int k) {
//	int length_world, col_world = 0;
//	col_world = found_col_world(str, col_world, length_str);
//	for (int i = 0, j = 0; j < col_world; i += length_world + 1, j++) {
//		length_world = 0;
//		length_world = leter_in_world(str, i, length_world, length_str);
//		if (length_world > k) {
//			delete_world(str, length_str, i, length_world);
//			length_str = new_length_str(str, length_str, length_world);
//		}
//	}
//}
int new_length_str_2(char* str, int length_str, int z,int a) {
	length_str -= z - a;
	str = (char*)realloc(str, (length_str + 1) * sizeof(char));
	str[length_str + 1] = '\0';
	return length_str;
}
void delete_worlds(char* str, int length_str, int a, int z) {
	while (str[a] != '\0')
	{
		str[a] = str[z];
		a++;
		z++;
	}
}
int end_of_world(char* str, int z, int length_str) {
	//for (z; z < length_str + 1; z++) {
	//	if (str[z] == ' ' || str[z] == '\t' || str[z] == '\0')
	//		break;
	//}
	int i = z;
	while (str[i] != ' ') {
		z++;
		i++;
	}
	return z;
}
void del_worlds(char* str, int length_str, int k) {
	int a = 0;
	int z = 0;
	while (a < length_str) {
		z = end_of_world(str, z, length_str);
		if (z - a + 1 > k) {
			delete_worlds(str, length_str, a, z);
			length_str = new_length_str_2(str, length_str, z, a);
			a = z;
		}
		else { a = z; }
	}
}