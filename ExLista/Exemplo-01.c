#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define InicioArranjo 1
#define MaxTam 5

typedef int Apontador;

typedef struct
{
    int cod;
    int idade;
} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam + 1];
    Apontador Primeiro;
    Apontador Ultimo;
} TipoLista;

TipoLista Lista;
TipoItem x;
Apontador pos;

void FLVazia(TipoLista *Lista)
{
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
}
int Vazia(TipoLista Lista)
{
    return (Lista.Primeiro == Lista.Ultimo);
}

int main()
{
   int opcao,resposta;
    setlocale(LC_ALL,"");
    // FLVazia(&Lista);
    do{

        system("cls");
        printf("\n\nMENU\n");
        printf("Digite a opção desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Lista\n");
        printf("2 - Verificar se a lista esta vazia\n");
        scanf("%d",&opcao);
        switch(opcao)
        {
           case 0:
            printf("Saindo...\n");
           break;
           case 1:
            //FLVazia(&Lista);
               printf("Lista esvaziada com sucesso!\n");
            break;
            case 2:
             resposta=Vazia(Lista);
                if(resposta==1)
                    printf("A lista esta vazia!\n");
                else
                    printf("A lista nao esta vazia!\n");
                break;
           default:
            printf("Opcao invalida!\n");
        }
        _getch();
        system("cls");
    }while(opcao!=0);   
    return 0;
}
