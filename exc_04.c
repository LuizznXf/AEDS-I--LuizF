#include <stdio.h>
#include <stdlib.h>
#define MaxTam 1000

typedef struct {
    float notas[MaxTam];
    int tamanho;
} Lista;

void InicializaLista(Lista *l) {
    l->tamanho = 0;
}

int ListaVazia(Lista *l) {
    return l->tamanho == 0;
}

int ListaCheia(Lista *l) {
    return l->tamanho == MaxTam;
}

void InserirNota(Lista *l, float nota) {
    if (ListaCheia(l)) {
        printf("Lista cheia!\n");
        return;
    }

    l->notas[l->tamanho] = nota;
    l->tamanho++;
}

void RemoverNota(Lista *l, float nota) {
    int i, j;

    if (ListaVazia(l)) {    
        printf("Lista vazia!\n");
        return;
    }

    for (i = 0; i < l->tamanho; i++) {
        if (l->notas[i] == nota) {
            for (j = i; j < l->tamanho - 1; j++) {
                l->notas[j] = l->notas[j + 1];
            }
            l->tamanho--;
            printf("Nota removida com sucesso!\n");
            return;
        }
    }

    printf("Nota nao encontrada!\n");
}

float CalcularMedia(Lista *l) {
    float soma = 0;
    int i;

    if (ListaVazia(l)) {
        return 0;
    }

    for (i = 0; i < l->tamanho; i++) {
        soma += l->notas[i];
    }

    return soma / l->tamanho;
}

void MaiorMenor(Lista *l, float *maior, float *menor) {
    int i;

    if (ListaVazia(l)) {
        *maior = *menor = 0;
        return;
    }

    *maior = *menor = l->notas[0];

    for (i = 1; i < l->tamanho; i++) {
        if (l->notas[i] > *maior)
            *maior = l->notas[i];

        if (l->notas[i] < *menor)
            *menor = l->notas[i];
    }
}

int main() {
    Lista lista;
    int opcao;
    float nota, media, maior, menor;

    InicializaLista(&lista);

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Inserir nota\n");
        printf("2 - Remover nota\n");
        printf("3 - Calcular media\n");
        printf("4 - Mostrar maior e menor nota\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a nota: ");
                scanf("%f", &nota);
                InserirNota(&lista, nota);
                break;

            case 2:
                printf("Digite a nota a remover: ");
                scanf("%f", &nota);
                RemoverNota(&lista, nota);
                break;

            case 3:
                media = CalcularMedia(&lista);
                printf("Media: %.2f\n", media);
                break;

            case 4:
                MaiorMenor(&lista, &maior, &menor);
                printf("Maior nota: %.2f\n", maior);
                printf("Menor nota: %.2f\n", menor);
                break;

            case 0:
                printf("Programa encerrado.\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
