#include <stdio.h>
#include <stdlib.h>
#define MaxTam 20

typedef struct {
    int numero;
} Cliente;

typedef struct {
    Cliente itens[MaxTam];
    int Frente;
    int Tras;
} Fila;

void InicializaFila(Fila *f) {
    f->Frente = 0;
    f->Tras = 0;
}

int FilaVazia(Fila *f) {
    return f->Frente == f->Tras;
}

int FilaCheia(Fila *f) {
    return f->Tras == MaxTam;
}

void Enfileira(Fila *f, Cliente c) {
    if (FilaCheia(f)) {
        printf("Fila cheia! Aguarde.\n");
    } else {
        f->itens[f->Tras] = c;
        f->Tras++;
        printf("Cliente %d adicionado à fila.\n", c.numero);
    }
}

Cliente Desenfileira(Fila *f) {
    Cliente c;
    c.numero = -1;

    if (FilaVazia(f)) {
        printf("Fila vazia! Nenhum cliente para atender.\n");
    } else {
        c = f->itens[f->Frente];
        f->Frente++;
    }

    return c;
}

void ProximoCliente(Fila *f) {
    if (FilaVazia(f)) {
        printf("Fila vazia!\n");
    } else {
        printf("Próximo cliente: %d\n", f->itens[f->Frente].numero);
    }
}

int main() {
    Fila fila;
    Cliente c;
    int opcao;
    int contador = 1;

    InicializaFila(&fila);

    do {
        printf("\n--- FILA DE ATENDIMENTO ---\n");
        printf("1 - Adicionar cliente\n");
        printf("2 - Atender cliente\n");
        printf("3 - Mostrar próximo cliente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            c.numero = contador++;
            Enfileira(&fila, c);
            break;

        case 2:
            c = Desenfileira(&fila);
            if (c.numero != -1)
                printf("Atendendo cliente %d\n", c.numero);
            break;

        case 3:
            ProximoCliente(&fila);
            break;

        case 0:
            printf("Encerrando programa...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
