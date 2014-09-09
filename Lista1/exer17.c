#include <stdio.h>

int main(void)
{
    int array[10] = {1,2,3,4,5,6,7,8,9};
    int *ponteiro = array;
    int i;
    for(i = 0; i < 10; i++)
    {
        ponteiro = &array[i];
        printf("%p ", ponteiro);
    }
    return 0;
}
