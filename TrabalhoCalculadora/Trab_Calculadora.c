// CALCULADORA
#include <stdio.h>
#include <stdlib.h>

float Soma(float n1, float n2) {
    return n1 + n2;
}

float Subtracao(float n1, float n2) {
    return n1 - n2;
}

float Multiplicacao(float n1, float n2) {
    return n1 * n2;
}

float verificarDivisao(float n2) {
    if (n2 == 0) {
        printf("ERRO! Nao e possivel dividir um numero por 0!\n");
        return 1;
    }
    return 0;
}

float Divisao(float n1, float n2) {
    if (verificarDivisao(n2))
        return 0;
    return n1 / n2;
}

int main() {
    float n1 = 0, n2 = 0, retorno = 0;
    int opcao = 0;
    int z = 0;

    do {
        printf("---------CALCULADORA SIMPLES---------\n");
        printf("ESCOLHA UMA DAS OPCOES ABAIXO:\n");
        printf("1--ENTRE COM OS NUMEROS\n");
        printf("6--SAIR\n");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("INFORME OS NUMEROS:\n");
            scanf("%f%f", &n1, &n2);
            z = 1;

            printf("2--SOMA\n");
            printf("3--SUBTRACAO\n");
            printf("4--MULTIPLICACAO\n");
            printf("5--DIVISAO\n");
            scanf("%d", &opcao);
        }

        switch (opcao) {
        case 2:
            if (z == 1) {
                retorno = Soma(n1, n2);
                system("cls");
                printf("Resultado: %.2f\n", retorno);
            } else {
                printf("Escolha a opcao 1 para iniciarmos ou 6 pra fechar a Calculadora\n");
            }
            break;
        case 3:
            if (z == 1) {
                retorno = Subtracao(n1, n2);
                system("cls");
                printf("Resultado: %.2f\n", retorno);
            } else {
                printf("Escolha a opcao 1 para iniciarmos ou 6 pra fechar a Calculadora\n");
            }
            break;
        case 4:
            if (z == 1) {
                retorno = Multiplicacao(n1, n2);
                system("cls");
                printf("Resultado: %.2f\n", retorno);
            } else {
                printf("Escolha a opcao 1 para iniciarmos ou 6 pra fechar a Calculadora\n");
            }
            break;
        case 5:
            if (z == 1) {
                retorno = Divisao(n1, n2);
                if (n2 != 0) {
                    system("cls");
                    printf("Resultado: %.2f\n", retorno);
                }
            } else {
                printf("Escolha a opcao 1 para iniciarmos ou 6 pra fechar a Calculadora\n");
            }
            break;
        case 6:
            printf("SAINDO...\n");
            break;
        default:
            if (opcao != 1)
                printf("OPCAO INVALIDA!\n");
            break;
        }

    } while (opcao != 6);

    return 0;
}