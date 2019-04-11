#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>		  // exit; malloc; system
#include <string.h>	  	  // strcmp
#include <time.h>
#include <locale.h>       // setlocale

//#include "MODELOENC.h"    // definição do registro

#define True 1


typedef struct node
{
	int codigo;
	node *prox;
	
}LISTA;

void inicia (node *LISTA);
void insere_Inicio (node *LISTA);


int main (void)
{
	node *LISTA = (node *) malloc(sizeof(node)); //cria um ponteiro do tipo node, que que recebe um espaço de memória para alocar.

	


return 0;
	
}


void inicia (node *LISTA);
{
	
	node->prox = NULL;
		
}


void insere_Inicio (node *LISTA);
{
	Agora devemos fazer dois passos: primeiros fazemos 
	LISTA->prox apontar para nosso novo nó, 
	depois fazemos nosso nó apontar para o próximo elemento da lista.

	Mas aqui temos um problema.
	Antes o 'LISTA->prox' apontava para um local de memória que tinha o próximo nó.
	Mas quando apontamos ele para o nó 'novo', perdemos essa referência.


	Vamos resolver isso criando um ponteiro para armazenar o local que está 'LISTA->prox' antes de inserirmos o novo nó.
	Vamos chamar de 'oldHead', pois era a cabeça antiga da lista:
	node *oldHead = LISTA->prox;
	
	Então, agora apontamos a cabeça da lista para nosso novo nó: LISTA->prox = novo;
	E apontamos nosso novo nó para o nó antigo: novo->prox = oldHead;
	
	
	node *novoNode = (*node)malloc(sizeof(node));
	
	novoNode = node->prox; 
		
	node *oldhead; //criado nó antigo para armezar o endereço anterior
	oldhead = node->prox; //
	
	
	





		
}



