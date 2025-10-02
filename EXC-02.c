// SOMA DE NUMEROS INTEIROS
#include <stdio.h>

int Soma(int n1, int n2)
{

    return ((n1 + n2) * 5);
}

int main()
{
    int n1, n2;

    printf("INFORME OS hhhhhhhhhhhhhhhNUMEROS:\n");
    scanf("%d%d", &n1, &n2);
    printf("A soma multiplicada por 5 e: %.d\n", Soma(n1, n2));

    return (0);
}
