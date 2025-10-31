//AUMENTO
#include <stdio.h>

float Aumento(float x , float y)
{
    return(x * (1 + y / 100));
}
int main()
{
    float x,y;

    printf("INFORME O VALOR DE X:\n");
    scanf("%f", &x);
    printf("INFORME EM QUANTOS %% X RECEBERA AUMENTO:\n");
    scanf("%f", &y);
    
    printf("O valor final de X e de: %.2f",Aumento(x, y));


    return (0);
}
    