//MÉDIA ARITMÉTICA
#include<stdio.h>

float mediaAritmetica(float n1, float n2)
{
    float media;
    media = (n1 + n2)/2;
    return(media);
}

int main()
{
    float result,n1,n2;
    printf("Insira as notas do aluno:\n");
    scanf("%f%f",&n1,&n2);

     result = mediaAritmetica(n1,n2);

     printf("A media e: %.2f\n",result);

     return(0);
}


