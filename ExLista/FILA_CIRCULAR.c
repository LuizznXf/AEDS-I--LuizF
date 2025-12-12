
QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>

#define MaxTam 3


typedef int Apontador;

typedef struct {
    int cod;
} TipoItem;

typedef struct {
    TipoItem Item[MaxTam];
    Apontador Frente;
    Apontador Trás;
} TipoFila;

TipoFila Lista;
TipoItem x;
int tamanho=0;

void FFVazia(TipoFila *Fila) {
    Fila->Frente=1;
    Fila->Frente=Fila->Trás ;
    tamanho=0;
}

int Vazia(TipoFila Fila) {
    return (Fila.Frente==Fila.Trás);
}


int main(){
    int opcao , resposta;
    FFVazia(&Lista);

    do{

        printf("\n\nMENU\n\n");
        printf("Digite a opção desejada!!!!");
        printf("\n0 - Sair");
        printf("\n1 - Esvaziar Fila");
     
        switch (opcao)
        {
        case 0:
        {
            printf("PROGRAMA ENCERRADO!\n");
        break;
        }
        case 1:
        {
            FFVazia(&fila);
            printf("\nA FILA VAZIA\n");
        break;
        }

        default: printf("\n\nOPCAO INVALIDA\n\n");
        }
        _getch();
        system("cls");
        } while (opcao!=0);
        return(0);
    
    
}
    







