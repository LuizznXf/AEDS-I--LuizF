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

int main()
{
   int opcao,resposta;
    setlocale(LC_ALL,"");
    // FLVazia(&Lista);
    do{

        system("cls");
        printf("\n\nMENU\n");
        printf("Digite a opção desejada:\n ");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Lista\n");
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
           default:
            printf("Opcao invalida!\n");
        }
        _getch();
        system("cls");
    }while(opcao!=0);   
    return 0;
}
