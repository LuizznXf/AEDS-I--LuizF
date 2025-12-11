#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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

void Insere(TipoItem x, TipoLista *Lista)
{
    if (Lista->Ultimo == MaxTam + 1)
    {
        printf("Erro: Lista cheia\n");
        return;
    }
    else
    {
        Lista->Item[Lista->Ultimo] = x;
        Lista->Ultimo++;
    }
}

void Imprime(TipoLista Lista)
{
    int aux;
    for (aux = Lista.Primeiro; aux < Lista.Ultimo; aux++)
    {
        printf("Codigo: %d\n", Lista.Item[aux].cod);
        printf("Idade: %d\n", Lista.Item[aux].idade);
    }
}

void Procura(TipoItem x, TipoLista Lista, Apontador *Pos)
{
    int i;
    int encontrado = 0;
    for (i = Lista.Primeiro; i <=Lista.Ultimo-2; i++)
    {
        if (Lista.Item[i].cod == x.cod)
        {
            encontrado = 1;
            printf("Elemento encontrado: Codigo na posicao %d\n", i);
            break;
        }
    }   
    if (encontrado == 0)
    {
       printf("Elemento nao encontrado na lista\n");
    }
    
}


int main()
{
    int opcao, resposta;
    setlocale(LC_ALL, "");
    FLVazia(&Lista);
    do
    {

        system("cls");
        printf("\n\nMENU\n");
        printf("Digite a opção desejada:\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Lista\n");
        printf("2 - Verificar se a lista esta vazia\n");
        printf("3 - Inserir elemento na lista\n");
        printf("4 - Imprimir os elemento da lista\n");
        printf("5 - Pesquisar elemento na lista\n");
        
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 0:
            printf("Saindo...\n");
            break;
        case 1:
            FLVazia(&Lista);
            printf("Lista esvaziada com sucesso!\n");
            break;
        case 2:
            resposta = Vazia(Lista);
            if (resposta == 1)
                printf("A lista esta vazia!\n");
            else
                printf("A lista nao esta vazia!\n");
            break;
        case 3:
            printf("Digite o codigo\n");
            scanf("%d", &x.cod);
            printf("Digite a idade\n");
            scanf("%d", &x.idade);
            Insere(x, &Lista);
            break;
        case 4:
            Imprime(Lista);
            break;
        case 5:
            printf("Funcao de pesquisa nao implementada!\n");
            break;    
        default:
            printf("Opcao invalida!\n");
        }
        _getch();
        system("cls");
    } while (opcao != 0);
    return 0;
}
