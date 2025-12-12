
//QUESTÃO 3
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

TipoFila Fila;
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
    FFVazia(&Fila);

    do{

        printf("\n\nMENU\n\n");
        printf("Digite a opção desejada!!!!");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Fila\n");
        printf("2 - Verfificar se a fila esta vazia\n");
     
        switch (opcao)
        {
        case 0:
        {
            printf("PROGRAMA ENCERRADO!\n");
        break;
        }
        case 1:
        {
            FFVazia(&Fila);
            printf("\nA FILA VAZIA\n");
        break;
        }
        case 2:
        {
            if (Vazia(Fila)==1){
                printf("\nA FILA ESTA VAZIA\n");
            } else {
                printf("\nA FILA NAO ESTA VAZIA\n");
            }
        }
        default: printf("\n\nOPCAO INVALIDA\n\n");
        }
        _getch();
        system("cls");
        } while (opcao!=0);
        return(0);
    
    
}
    







