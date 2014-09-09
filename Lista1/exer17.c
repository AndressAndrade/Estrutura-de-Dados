#include <stdio.h>

int main(void)
{
    float array[10] = {1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5};
    float *ponteiro = array;
    int i;
    for(i = 0; i < 10; i++)
    {
        ponteiro = &array[i];
        printf("%p ", ponteiro);
    }
    return 0;
}
