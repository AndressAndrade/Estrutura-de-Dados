#include <stdio.h>
#include <math.h>

int main(void)
{
    int raizes (float a, float b, float c, float *x1, float *x2);
    int numraiz;
    float a,b,c,x1,x2;
    printf("Digite os valores de a, b e c, separados por espaco:\n");
    scanf("%f %f %f", &a,&b,&c);
    numraiz = raizes(a,b,c,&x1,&x2);
    printf("O numero de raizes reais e distintas eh: %i\n",numraiz);
    if(numraiz == 2)
    {
        printf("As raizes reais e distintas sao: %.2f e %.2f",x1,x2);
    }
    else if(numraiz == 1)
    {
        printf("As raizes sao identicas: %.2f",x1);
    }
    return 0;
}

int raizes (float a, float b, float c, float *x1, float *x2)
{
    if(a > 0)
    {
        double delta = b*b - 4*a*c;
        if(delta > 0)
        {
            *x1 = (-b + sqrt(delta))/2*a;
            *x2 = (-b - sqrt(delta))/2*a;
            return 2;
        }
        else if(delta == 0)
        {
            *x1 = -b/2*a;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
