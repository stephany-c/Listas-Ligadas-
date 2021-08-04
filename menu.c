#include <stdio.h>
#include <stdlib.h>

int numero; //variavel para escolha no menu

struct lista {
	int matricula;
	char nome;
	float salario;
	struct lista*prox;
	struct lista*ant;
};

typedef struct lista Lista;
Lista *inicializa(void){
	return NULL;	
}

    
int menu()

{   printf("Lista duplamnete encadeada\n\n");
    printf("Menu de opcoes\n");
    printf("1- inclusao\n");
    printf("2- Remocao\n");
    printf("3- Busca\n");
    printf("4- Listagem\n");
    printf("5- Saida\n");
    printf("Escolha a opçao desejada:\n\n");  
	scanf("%d",&numero);  
	
switch(numero)
{case 1:
	
	break;
 case 2:
 
    break;
 case 3:
 
    break;
 case 4:
 	
   
    break;
 case 5:
 	exit(0);  //função de encerramento do programa 
     break;
  
} 
}

int main() {
	Lista *l; //declara lista
	l=inicializa();  //incializa
	menu(); 
	return 0;
}

   

