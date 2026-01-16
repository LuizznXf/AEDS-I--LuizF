#include <stdio.h>
#include <stdlib.h>
#define MaxTam 3

typedef struct {
    int modelo;
    float consumo; 
} Moto;

typedef struct {
    Moto itens[MaxTam];
    int Frente;
    int Tras;
} Fila;

void InicializaFila(Fila *f) {
    f->Frente = 0;
    f->Tras = 0;
}

void Enfileira(Fila *f, Moto m) {
    if (FilaCheia(f)) {
        printf("\nFila cheia!\n");
    } else {
        f->itens[f->Tras] = m;
        f->Tras++;
    }
}

int main() {
    Fila fila;
    Moto m;
    int i;

    InicializaFila(&fila);

    for (i = 0; i < MaxTam; i++) {
        printf("\nDigite o modelo da moto %d: ", i + 1);
        scanf("%d", &m.modelo);

        printf("Digite o consumo (km por litro): ");
        scanf("%f", &m.consumo);

        Enfileira(&fila, m);
    }

    int MaisEconomica = fila.Frente;

    for (i = fila.Frente + 1; i < fila.Tras; i++) {
        if (fila.itens[i].consumo > fila.itens[MaisEconomica].consumo) {
            MaisEconomica = i;
        }
    }

    printf("\nMoto mais economica: Modelo %d\n",
           fila.itens[MaisEconomica].modelo);

    printf("\nConsumo para percorrer 100 km:\n");

    for (i = fila.Frente; i < fila.Tras; i++) {
        float litros = 100 / fila.itens[i].consumo;
        printf("Modelo %d consome %.2f litros\n",
               fila.itens[i].modelo, litros);
    }

    return 0;
}