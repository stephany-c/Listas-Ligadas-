#include <stdio.h>
#include <stdlib.h>

#define tamanhoPadraoString 16

int numero; //variavel para escolha no menu

struct lista
{
    int matricula;
    char *nome;
    float salario;
    struct lista *prox;
    struct lista *ant;
};

typedef struct lista Lista;
Lista *inicializa(void)
{
    return NULL;
}

Lista *inserirLista(Lista *l, int matricula, char *nome, float salario)
{
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->matricula = matricula;
    novo->nome = nome;
    novo->salario = salario;
    novo->ant = NULL;
    novo->prox = l;
    if (l != NULL)
        l->ant = novo;

    return novo;
}

void limparInput(){
  char temp;
  while((temp = getchar()) != '\n' && temp != EOF){}
}

char *obterStringTamanhoDinamico()
{
    limparInput();
    char caractereAtual;
    int comprimentoAtual = 0;
    int comprimentoMaximo = tamanhoPadraoString;
    char *stringDinamica = malloc(tamanhoPadraoString); // inicia string com tamanho fixo caracteres

    while (1)
    {
        scanf("%c", &caractereAtual);
        if (caractereAtual == '\n')
            break; //Apertou enter, sai do loop

        if (comprimentoAtual == comprimentoMaximo - 1)
        { //Dobra o tamanho da string ao atingir o tamanho maximo
            comprimentoMaximo *= 2;
            stringDinamica = realloc(stringDinamica, comprimentoMaximo);
        }
        stringDinamica[comprimentoAtual] = caractereAtual;
        stringDinamica[comprimentoAtual + 1] = '\0';
        comprimentoAtual++;
    }
    return stringDinamica;
}

Lista *inserirNovoFuncionario(Lista *l)
{
    int matricula;
    float salario;
    char *nome;
    printf("Digite o numero de matricula: ");
    scanf("%d", &matricula);

    printf("\nDigite o nome do funcionario: ");
    nome = obterStringTamanhoDinamico();

    printf("\nDigite o salario do funcionario: ");
    scanf("%f", &salario);

    return inserirLista(l, matricula, nome, salario);
}

Lista* removerItem(Lista *l,int matricula){
  Lista *aux; //Variavel auxiliar para percorrer a lista
  for(aux=l; aux != NULL; aux = aux->prox){
    if(aux->matricula == matricula){
        break;
    }
  }

  if(aux == NULL){
    printf("\n\nFuncionario nao encontrado.\n\n");
    return l;
  }

  if(aux->prox != NULL){ //aux nao e o ultimo elemento
    aux->prox->ant = aux->ant;
  }

  if(aux->ant != NULL){ //aux nao e o primeiro elemento da lista
    aux->ant->prox = aux->prox;
  }
  else{ //aux e o primeiro elemento
    l = aux->prox; //aponta para o prox como primeiro elemento
  }
  printf("\n\nFuncionario excluido com sucesso!\n\n");
  free(aux->nome); //apaga o nome da memoria
  free(aux); //apaga o elemento da memoria
  return l;
}

void imprime(Lista *l) { 
        Lista *p; //variável auxiliar
        for(p=l; p!= NULL; p = p->prox)	
	       printf("\nMatricula %d,nome %s,salario %0.2f\n",p->matricula,p->nome,p->salario);
}

void buscar(Lista *l, int matricula) { 
    Lista *p; //variável auxiliar
    int encontrou = 0;
    for(p=l; p!= NULL; p = p->prox)	{
      if(matricula == p->matricula) {
        encontrou = 1;
        printf("\nMatricula %d,nome %s,salario %0.2f\n",p->matricula,p->nome,p->salario);
      }
    }

    if(encontrou == 0)
        printf("\nA busca não encontrou nenhum resultado");
}

void menu(Lista *l)
{
    int busca;
    
    do
    {
        printf("Lista duplamente encadeada\n\n");
        printf("Menu de opcoes\n");
        printf("1- inclusao\n");
        printf("2- Remocao\n");
        printf("3- Busca\n");
        printf("4- Listagem\n");
        printf("5- Saida\n");
        printf("Escolha a opçao desejada:\n\n");
        scanf("%d", &numero);

        switch (numero)
        {
        case 1:
            l = inserirNovoFuncionario(l);
            break;
        case 2:
            printf("\n\nQual matricula deseja excluir?\n\n");
            scanf("%d", &busca);
            l = removerItem(l, busca);
            break;
        case 3:
              printf("\n\nPor qual matricula deseja buscar?\n\n");
              scanf("%d", &busca);
              buscar(l, busca);
            break;
        case 4:
            imprime(l);
            break;
        case 5:
            exit(0); //função de encerramento do programa
            break;
        }

    } while (numero != 5);
}

int main()
{
    Lista *l;         //declara lista
    l = inicializa(); //incializa
    menu(l);
    return 0;
}

