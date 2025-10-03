// CALCULADORA
#include <stdio.h>

float Soma(float n1, float n2)
{
    return (n1 + n2);
}
float Subtracao(float n1, float n2)
{
    return (n1 - n2);
}
float Multiplicacao(float n1, float n2)
{
    return (n1 * n2);
}
float verificarDivisao(float n2)
{
    if (n2 == 0) { 
        printf("ERR0!Nao e possivel dividir um numero por 0!\n");
        return 1; 
    } else {
        return 0; 
    }
}
float Divisao(float n1, float n2)
{
    float x = verificarDivisao(n2);
    if(x==1){
        return 0;
    }else{
        return n1/n2;  
    }
   
}

int main()
{
    float n1 = 0, n2 = 0, retorno = 0;
    int opcao;
    int z=0;
    do {
        printf("---------CALCULADORA SIMPLES---------\n");
        printf("1--ENTRE COM OS NUMEROS\n");
        printf("2--SOMA\n");
        printf("3--SUBTRACAO\n");
        printf("4--MULTIPLICACAO\n");
        printf("5--DIVISAO\n");
        printf("6--SAIR\n");
        printf("ESCOLHA UMA DAS OPCOES ACIMA:\n");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                printf("INFORME OS NUMEROS:\n");
                scanf("%f%f", &n1, &n2);
                int z = 0;
                break;
            case 2:
                retorno = Soma(n1, n2);
                if(z!=0){
                    printf("Voce nao entrou com nenhum numero ainda!\n");
                }else{
                     system("cls");
                     printf("Resultado: %.2f\n", retorno);              
                }
                break;
            case 3:
                retorno = Subtracao(n1, n2);
                if(z!=0){
                    printf("Voce nao entrou com nenhum numero ainda!\n");
                }else{
                     system("cls");
                     printf("Resultado: %.2f\n", retorno);
                }
                break;
            case 4:
                retorno = Multiplicacao(n1, n2);
                if(z!=0){
                    printf("Voce nao entrou com nenhum numero ainda!\n");
                }else{ 
                    system("cls");
                    printf("Resultado: %.2f\n", retorno);
                }
                break;
            case 5:
                retorno = Divisao(n1, n2);
                    if(z!=0){
                        printf("Voce nao entrou com nenhum numero ainda!\n");
                    }else if (n2 != 0){
                    system("cls");
                    printf("Resultado: %.2f\n", retorno);
                    }
                break;
            case 6:
                printf("SAINDO...\n");
                break;
            default:
                printf("OPCAO INVALIDA!\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

    
    