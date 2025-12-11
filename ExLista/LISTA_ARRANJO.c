
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
/*
//---------------------------------QUESTÃO 4---------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

#define InicioArranjo 1
#define MaxTam 1000

typedef int Apontador;

typedef struct {
    int valor;
} TipoItem;

typedef struct {
    TipoItem Item[MaxTam];
    Apontador Primeiro;
    Apontador Ultimo;
} TipoLista;


void InicializaLista(TipoLista *L) {
    L->Primeiro = InicioArranjo;
    L->Ultimo = L->Primeiro;
}

int Insere(TipoItem x, TipoLista *L) {
    if (L->Ultimo > MaxTam)
        return 0;
    L->Item[L->Ultimo - 1] = x;
    L->Ultimo++;
    return 1;
}


void mostraQuantidade(TipoLista *L) {
    int qtd = L->Ultimo - L->Primeiro;
    printf("\nQuantidade de valores: %d\n", qtd);
}

void mostraOrdemNormal(TipoLista *L) {
    printf("\nValores na ordem informada:\n");
    for (int i = L->Primeiro; i < L->Ultimo; i++)
        printf("%d ", L->Item[i - 1].valor);
    printf("\n");
}

void mostraOrdemInversa(TipoLista *L) {
    printf("\nValores na ordem inversa:\n");
    for (int i = L->Ultimo - 1; i >= L->Primeiro; i--)
        printf("%d\n", L->Item[i - 1].valor);
}

int somaValores(TipoLista *L) {
    int soma = 0;
    for (int i = L->Primeiro; i < L->Ultimo; i++)
        soma += L->Item[i - 1].valor;
    return soma;
}

float mediaValores(TipoLista *L) {
    int qtd = L->Ultimo - L->Primeiro;
    if (qtd == 0) return 0;
    return (float) somaValores(L) / qtd;
}

void valoresAcimaMedia(TipoLista *L) {
    float media = mediaValores(L);
    int count = 0;

    for (int i = L->Primeiro; i < L->Ultimo; i++)
        if (L->Item[i - 1].valor > media)
            count++;

    printf("\nValores acima da média: %d\n", count);
}

void valoresAbaixoDe7(TipoLista *L) {
    int count = 0;

    for (int i = L->Primeiro; i < L->Ultimo; i++)
        if (L->Item[i - 1].valor < 7)
            count++;

    printf("\nValores abaixo de 7: %d\n", count);
}

void menu() {
    printf("\n=== MENU ===\n");
    printf("1 - Mostrar quantidade de valores\n");
    printf("2 - Mostrar valores na ordem informada\n");
    printf("3 - Mostrar valores na ordem inversa\n");
    printf("4 - Mostrar soma dos valores\n");
    printf("5 - Mostrar média dos valores\n");
    printf("6 - Mostrar quantidade acima da média\n");
    printf("7 - Mostrar quantidade abaixo de 7\n");
    printf("0 - Sair\n");
    printf("Escolha: ");
}

int main() {
    TipoLista lista;
    InicializaLista(&lista);

    int entrada;
    TipoItem novo;
    int opcao;

    printf("Digite valores inteiros (-1 para encerrar):\n");
    while (1) {
        scanf("%d", &entrada);
        if (entrada == -1) break;
        novo.valor = entrada;
        Insere(novo, &lista);
    }

    do {
        menu();
        scanf("%d", &opcao);

        system("cls"); 

        switch (opcao) {

            case 1:
                mostraQuantidade(&lista);
                break;

            case 2:
                mostraOrdemNormal(&lista);
                break;

            case 3:
                mostraOrdemInversa(&lista);
                break;

            case 4:
                printf("\nSoma = %d\n", somaValores(&lista));
                break;

            case 5:
                printf("\nMédia = %.2f\n", mediaValores(&lista));
                break;

            case 6:
                valoresAcimaMedia(&lista);
                break;

            case 7:
                valoresAbaixoDe7(&lista);
                break;

            case 0:
                printf("\nPrograma encerrado. Obrigado!\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

        if (opcao != 0) {
            printf("\n");
            system("pause");  
            system("cls");    
        }

    } while (opcao != 0);

    return 0;
}*/

    //---------------------------------QUESTÃO 5---------------------------------------------------
    #include <stdio.h>
    #include <stdlib.h>
    
    #define InicioArranjo 1
    #define MaxTam 5   
    
    typedef int Apontador;
    
    typedef struct {
        int resposta;   
    } TipoItem;
    
    typedef struct {
        TipoItem Item[MaxTam];
        Apontador Primeiro;
        Apontador Ultimo;
    } TipoLista;

    void InicializaLista(TipoLista *L) {
        L->Primeiro = InicioArranjo;
        L->Ultimo = L->Primeiro;
    }
    
    int Insere(TipoItem x, TipoLista *L) {
        if (L->Ultimo > MaxTam) 
            return 0;
        L->Item[L->Ultimo - 1] = x;
        L->Ultimo++;
        return 1;
    }

    void LimpaLista(TipoLista *L) {
        L->Ultimo = L->Primeiro;
    }
    

    void fazerPerguntas(TipoLista *L) {
        TipoItem temp;
    
        LimpaLista(L);  
    
        printf("Responda com 1 (Sim) ou 0 (Nao)\n\n");

        do {
            printf("1. Telefonou para a vítima? ");
            if (scanf("%d", &temp.resposta) != 1) { fflush(stdin); temp.resposta = -1; }
        } while (temp.resposta != 0 && temp.resposta != 1);
        Insere(temp, L);
    
        do {
            printf("2. Esteve no local do crime? ");
            if (scanf("%d", &temp.resposta) != 1) { fflush(stdin); temp.resposta = -1; }
        } while (temp.resposta != 0 && temp.resposta != 1);
        Insere(temp, L);
    
        do {
            printf("3. Mora perto da vítima? ");
            if (scanf("%d", &temp.resposta) != 1) { fflush(stdin); temp.resposta = -1; }
        } while (temp.resposta != 0 && temp.resposta != 1);
        Insere(temp, L);
    
        do {
            printf("4. Devia para a vítima? ");
            if (scanf("%d", &temp.resposta) != 1) { fflush(stdin); temp.resposta = -1; }
        } while (temp.resposta != 0 && temp.resposta != 1);
        Insere(temp, L);
    
        do {
            printf("5. Já trabalhou com a vítima? ");
            if (scanf("%d", &temp.resposta) != 1) { fflush(stdin); temp.resposta = -1; }
        } while (temp.resposta != 0 && temp.resposta != 1);
        Insere(temp, L);
    
        printf("\nPerguntas registradas!\n");
    }
    
    void mostrarRespostas(TipoLista *L) {
        if (L->Ultimo == L->Primeiro) {
            printf("\nNenhuma resposta registrada.\n");
            return;
        }
    
        printf("\nRespostas fornecidas (1 = Sim / 0 = Nao):\n");
        for (int i = L->Primeiro; i < L->Ultimo; i++)
            printf("Pergunta %d: %d\n", i, L->Item[i - 1].resposta);
    }
    
    void classificarPessoa(TipoLista *L) {
        if (L->Ultimo == L->Primeiro) {
            printf("\nNenhuma resposta registrada. Classificação indisponível.\n");
            return;
        }
    
        int soma = 0;
        for (int i = L->Primeiro; i < L->Ultimo; i++)
            soma += L->Item[i - 1].resposta;
    
        printf("\nTotal de respostas positivas: %d\n", soma);
    
        if (soma == 5)
            printf("Classificação: ASSASSINO\n");
        else if (soma >= 3)
            printf("Classificação: CÚMPLICE\n");
        else if (soma == 2)
            printf("Classificação: SUSPEITA\n");
        else
            printf("Classificação: INOCENTE\n");
    }

    void menu() {
        printf("\n=== MENU ===\n");
        printf("1 - Responder perguntas\n");
        printf("2 - Mostrar respostas\n");
        printf("3 - Classificar pessoa\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
    }

    int main() {
        TipoLista lista;
        InicializaLista(&lista);
        int opcao;
    
        do {
            menu();
            if (scanf("%d", &opcao) != 1) { 
                opcao = -1;
                fflush(stdin);
            }
    
            system("cls");
    
            switch (opcao) {
    
                case 1:
                    fazerPerguntas(&lista);
                    break;
    
                case 2:
                    mostrarRespostas(&lista);
                    break;
    
                case 3:
                    classificarPessoa(&lista);
                    break;
    
                case 0:
                    printf("\nEncerrando programa...\n");
                    break;
    
                default:
                    printf("\nOpção inválida!\n");
            }
    
            if (opcao != 0) {
                printf("\n");
                system("pause");
                system("cls");
            }
    
        } while (opcao != 0);
    
        return 0;
    }
    