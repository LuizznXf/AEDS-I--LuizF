// CALCULO DE AREAS
#include <stdio.h>


float AreaQuadrada(float larg)
{
    return(larg * larg);
}
float AreaCirculo(float raio)
{
    return 3.14f * (raio * raio);
}

int main()
{
    float larg,raio;

    printf("INFORME O LADO DO QUADRADO:\n");
    scanf("%f", &larg);
    printf("A area do quadrado e de : %.2f e o calculo dessa area e (larg * larg)\n\n", AreaQuadrada(larg));

    printf("Agora iremos calcular a Area de um circulo.\n INFORME SEU RAIO!\n");
    scanf("%f", &raio);
    printf("A area do circula e de : %.2f e o calculo dessa area e (pi*raio^2)\n", AreaCirculo(raio));

    return (0);
}
    