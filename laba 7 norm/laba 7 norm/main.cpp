#include "Header.h"

int main()
{
    int task = 0;
    //setlocale(LC_ALL, "Rus");
    while (1)
    {
        task = choice(task);
        void (*taskss[3]) () = { Task_1, Task_2, stop };
        taskss[task - 1]();
    }
    return 0;
}