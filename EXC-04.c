// CALCULAR HIPOTENUSA
#include <stdio.h>
#include <math.h>

float HIP(float cat1, float cat2)
{
    return (sqrt((cat1 * cat1) + (cat2 * cat2)));
}

int main()
{
    float cat1, cat2;

    printf("INFORME OS CATETOS:\n");
    scanf("%f%f", &cat1, &cat2);
    printf("A Hipotenusa do triangulo e: %.2f\n", HIP(cat1, cat2));

    return (0);
}
