#include <stdio.h>
#include <stdlib.h>
#define MaxTam 1000

typedef struct {
    int nota;
} Item;

typedef struct {
    Item itens[MaxTam];
    int Frente;
    int Tras;
} Fila;

void InicializaFila(Fila *f) {
    f->Frente = 0;
    f->Tras = 0;
}

int FilaCheia(Fila *f) {
    return f->Tras == MaxTam;
}

void Enfileira(Fila *f, Item x) {
    if (FilaCheia(f)) {
        printf("\nFila cheia!\n");
    } else {
        f->itens[f->Tras] = x;
        f->Tras++;
    }
}

int main() {
    Fila fila;
    Item x;
    int soma = 0;
    float media;
    int i, acimaMedia = 0, abaixoSete = 0;

    InicializaFila(&fila);

    printf("Digite as notas (-1 para encerrar):\n");

    while (1) {
        scanf("%d", &x.nota);

        if (x.nota == -1)
            break;

        Enfileira(&fila, x);
    }

    // a) Quantidade de valores lidos
    printf("\nQuantidade de valores lidos: %d\n", fila.Tras);

    // b) Valores na ordem informada
    printf("\nValores na ordem informada:\n");
    for (i = fila.Frente; i < fila.Tras; i++) {
        printf("%d ", fila.itens[i].nota);
    }

    // c) Valores na ordem inversa
    printf("\n\nValores na ordem inversa:\n");
    for (i = fila.Tras - 1; i >= fila.Frente; i--) {
        printf("%d\n", fila.itens[i].nota);
    }

    // d) Soma dos valores
    for (i = fila.Frente; i < fila.Tras; i++) {
        soma += fila.itens[i].nota;
    }
    printf("\nSoma dos valores: %d\n", soma);


    // e) Média dos valores
    if (fila.Tras > 0) {
         media = (float)soma / fila.Tras;
        printf("Media dos valores: %.2f\n", media);
    } else {
        media = 0;
        printf("Média dos valores: N/A (nenhum valor lido)\n");
    }

    // f) Quantidade de valores acima da média
    for (i = fila.Frente; i < fila.Tras; i++) {
        if (fila.itens[i].nota > media) {
            acimaMedia++;
        }
    }
    printf("Quantidade de valores acima da média: %d\n", acimaMedia);

    // g) Quantidade de valores abaixo de sete
    for (i = fila.Frente; i < fila.Tras; i++) {
        if (fila.itens[i].nota < 7) {
            abaixoSete++;
        }
    }
    printf("Quantidade de valores abaixo de sete: %d\n", abaixoSete);

    // h) Mensagem de encerramento
    printf("\nPrograma encerrado. Obrigado por utilizar!\n");

    return 0;
}