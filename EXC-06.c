// SALARIOS
#include <stdio.h>

float Salario(float s1, float s2)
{
    if(s1>s2){
        return(s1);
    }else{
         return(s2);
    }
   
}

int main()
{
    float s1, s2;

    printf("INFORME OS SALARIOS:\n");
    scanf("%f%f", &s1, &s2);
    printf("O maior salario entre os 2 informados e de : %.2f\n", Salario(s1, s2));

    return (0);
}
