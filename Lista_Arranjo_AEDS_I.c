/*QUESTÃO 3
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>  // para _getch()

#define InicioArranjo 1
#define MaxTam 5

typedef int Apontador;

typedef struct {
    int cod;
    int idade;
} TipoItem;

typedef struct {
    TipoItem Item[MaxTam + 1];
    Apontador Primeiro;
    Apontador Ultimo;
} TipoLista;

TipoLista Lista;
TipoItem x;
Apontador pos;

void FLVazia(TipoLista *Lista) {
    Lista->Primeiro = InicioArranjo;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista) {
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista) {
    if (Lista->Ultimo > MaxTam) {
        printf("Erro: Lista cheia\n");
        return;
    }
    Lista->Item[Lista->Ultimo] = x;
    Lista->Ultimo++;
    printf("Elemento inserido com sucesso!\n");
}

void Imprime(TipoLista Lista) {
    if (Vazia(Lista)) {
        printf("Lista vazia!\n");
        return;
    }
    printf("\n--- Elementos da Lista ---\n");
    for (int aux = Lista.Primeiro; aux < Lista.Ultimo; aux++) {
        printf("Posicao %d -> Codigo: %d | Idade: %d\n", aux, Lista.Item[aux].cod, Lista.Item[aux].idade);
    }
    printf("--------------------------\n");
}

void Procura(TipoItem x, TipoLista Lista, Apontador *Pos) {
    if (Vazia(Lista)) {
        printf("Lista vazia! Nada para pesquisar.\n");
        *Pos = -1;
        return;
    }

    for (int i = Lista.Primeiro; i < Lista.Ultimo; i++) {
        if (Lista.Item[i].cod == x.cod) {
            printf(">>> Elemento ENCONTRADO!\n");
            printf("    Codigo: %d | Idade: %d | Posicao: %d\n",
                   Lista.Item[i].cod, Lista.Item[i].idade, i);
            *Pos = i;
            return;
        }
    }
    printf("Elemento com codigo %d NAO encontrado na lista.\n", x.cod);
    *Pos = -1;
}

int main() {
    int opcao;
    setlocale(LC_ALL, "Portuguese");

    FLVazia(&Lista);

    do {
        system("cls");
        printf("\n\n=== MENU DA LISTA ===\n");
        printf("0 - Sair\n");
        printf("1 - Esvaziar Lista\n");
        printf("2 - Verificar se a lista esta vazia\n");
        printf("3 - Inserir elemento na lista\n");
        printf("4 - Imprimir os elementos da lista\n");
        printf("5 - Pesquisar elemento na lista (pelo codigo)\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                printf("Saindo do programa...\n");
                break;

            case 1:
                FLVazia(&Lista);
                printf("Lista esvaziada com sucesso!\n");
                break;

            case 2:
                if (Vazia(Lista))
                    printf("A lista esta vazia!\n");
                else
                    printf("A lista NAO esta vazia! (tem %d elementos)\n", Lista.Ultimo - Lista.Primeiro);
                break;

            case 3:
                printf("Digite o codigo: ");
                scanf("%d", &x.cod);
                printf("Digite a idade: ");
                scanf("%d", &x.idade);
                Insere(x, &Lista);
                break;

            case 4:
                Imprime(Lista);
                break;

            case 5:
                if (Vazia(Lista)) {
                    printf("A lista esta vazia! Nada para pesquisar.\n");
                } else {
                    printf("Digite o codigo que deseja pesquisar: ");
                    scanf("%d", &x.cod);
                    Procura(x, Lista, &pos);
                }
                break;

            default:
                printf("Opcao invalida!\n");
        }
        printf("\nPressione qualquer tecla para continuar...");
        _getch();

    } while (opcao != 0);

    return 0;
}
*/

/*QUESTÃO 4


#include <stdio.h>
#define MAX 1000 // tamanho máximo seguro (pode aumentar se precisar)

int main()
{
    int notas[MAX];
    int i = 0; // contador de notas
    int valor;
    int soma = 0;
    int qtd_acima_media = 0;
    int qtd_abaixo_sete = 0;
    float media;

    // Leitura das notas
    printf("Digite as notas (digite -1 para encerrar):\n");

    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &valor);
        if (valor == -1)
        {
            break;
        }
        notas[i] = valor;
        // d)
        soma += valor;
        // e)
      
    }  
    if (i > 0)
        {
            media = (float)soma / i;
        }
        else
        {
            media = 0;
        }
    // a)
    printf("\nA quantidade de notas lidas e de %d\n", i);
    // b)
    printf("Valores na ordem informada:\n");
    for (int j = 0; j < i; j++)
    {
        printf("%d,", notas[j]);
    }
    // c)
    printf("\nValores na ordem inversa:\n");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d\n", notas[j]);
    }
    // d) continuação...
    printf("\nA soma dos valores e: %d\n", soma);

    // e) continuação...
    printf("\nA media dos valores e: %.2f\n", media);

    // f)
    for (int j = 0; j < i; j++)
    {
        if (notas[j] > media)
        {
            qtd_acima_media++;
        }
    }
    printf("A quantidade de valores acima da media e: %d\n", qtd_acima_media);

    // g)
    for (int j = 0; j < i; j++)
    {
        if (notas[j] < 7)
        {
            qtd_abaixo_sete++;
        }
    }
    printf("A quantidade de valores abaixo de sete e: %d\n", qtd_abaixo_sete);
    return 0;

   // h)
    printf("Programa encerrado...!\n"); 
}
    */

/*QUESTÃO 5*/
 
#include <stdio.h>
#include <string.h>
#define MAX 5
    int main(){
        char perguntas[MAX][100] = {
            "Telefonou para a vitima? (s/n): ",
            "Esteve no local do crime? (s/n): ",
            "Mora perto da vitima? (s/n): ",
            "Devia para a vitima? (s/n): ",
            "Ja trabalhou com a vitima? (s/n): "
        };

        char resposta;
        int contador_sim = 0;
        for(int i = 0; i < MAX; i++){
            printf("%s", perguntas[i]);
            scanf(" %c", &resposta);
            if(resposta == 's' || resposta == 'S'){
                contador_sim++;
            }
        }

        if(contador_sim == 2){
            printf("Classificacao: Suspeita\n");
        } else if(contador_sim >= 3 && contador_sim <= 4){
            printf("Classificacao: Cumplice\n");
        } else if(contador_sim == 5){
            printf("Classificacao: Assassino\n");
        } else {
            printf("Classificacao: Inocente\n");
        }
    }