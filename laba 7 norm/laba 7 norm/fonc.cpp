#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int choice(int n)
{
    printf("\nChoice what do you want to do\n1.Start task number one\n2.Start task number two\n3.Exit\nYour choice:");
    int lastchar;

    while ((scanf_s("%d", &n)) != 1 || n < 1 || n > 3 || ((lastchar = getchar()) != '\n' && lastchar != ' '))
    {
        printf("Try again =)");
        rewind(stdin);
    }
    return n;
}

//TASK 1 LAB 7
void input_string(char** string, int* lenght)       
{
    *string = (char*)calloc(256, sizeof(char));
    char ch;
    int pos = 0;
    while (1)  
    {
        ch = getchar();

        if (ch == '\n')
        {
            (*string)[pos] = '\0';
            *string = (char*)realloc(*string, (pos + 1) * sizeof(char));
            break;
        }
        (*string)[pos] = ch;
        pos++;
        *lenght = pos;
        if (pos >= 256)
            *string = (char*)realloc(*string, pos + 1 * sizeof(char));
    }

}

int input_delete_num(int n)
{
    int lastchar;
    printf("\nEnter the maksimum number of letters in a words:\n");
    while ((scanf_s("%d", &n)) != 1 || ((lastchar = getchar()) != '\n' && lastchar != ' '))
    {
        printf("Try again =)");
        rewind(stdin);
    }
    return n;
}

int if_letter(char string)
{
    if ((string >= 'a' && string <= 'z') || (string >= 'A' && string <= 'Z') /* (string >= 'à' && string <= 'ÿ')  (string >= 'À' && string <= 'ß')*/)
        return 1;

    return 0;
}

void check_string(char** string, int delete_num, int size)
{
    delete_num = input_delete_num(delete_num);
    int i = 0, cnt = 0; int lenght = size;
    while ((*string)[i] != '\0')
    {
        if ((i == 0 && if_letter((*string)[i]) == 1) || (if_letter((*string)[i - 1]) == 0 && if_letter((*string)[i]) == 1))
        {
            while (if_letter((*string)[i]) == 1)
            {
                i++;
                cnt++;
            }
            if (cnt > delete_num)
            {
                int j = i;
                while ((*string)[j] != '\0')
                {
                    (*string)[j - cnt] = (*string)[j];
                    j++;
                    if (j == lenght)
                        break;
                }
                lenght -= cnt + 1;
                *string = (char*)realloc(*string, lenght + 1 * sizeof(char));
                (*string)[lenght + 1] = '\0';
                lenght++;
                i = 0;
            }
            i--;
        }
        i++;
        cnt = 0;
    }
}

void Task_1()
{
    char* string;
    int lenght = 0, delete_num = 0;

    printf("Enter string:\n");
    input_string(&string, &lenght);

    printf("Entered string:\n");
    printf("%s", string);

    check_string(&string, delete_num, lenght);

    printf("Final string:\n");
    printf("%s", string);

    string = (char*)calloc(0, 1);
}

//TASK 2 LAB 7

char input_char(char c)
{
    printf("\nInput one symbole:\n");
    scanf_s("%c", &c);

    return c;
}

void delete_second_c(char** string, int lenght, char c)
{
    int i = 0, fl = 0;

    while ((*string)[i] != '\0')
    {
        if ((*string)[i] == c)
            fl++;

        if (fl == 2)
        {
            int buf = i;
            while ((*string)[i] != '\0')
            {
                (*string)[i] = (*string)[i + 1];
                i++;
            }
            *string = (char*)realloc(*string, (--lenght) * sizeof(char));
            (*string)[lenght] = '\0';
            fl = 0;
            i = buf;
            i--;
        }
        i++;
    }
}

void Task_2()
{
    char* string;
    int lenght = 0;
    char c = '\0';

    printf("Input string:\n");
    input_string(&string, &lenght);

    printf("Entered string:\n");
    printf("%s", string);

    c = input_char(c);

    delete_second_c(&string, lenght, c);

    printf("Final string:\n");
    printf("%s", string);

    string = (char*)calloc(0, 1);
}

void stop()
{
    exit(EXIT_SUCCESS);
}