#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>		  // exit; malloc; system
#include <string.h>	  	  // strcmp
#include <time.h>
#include <locale.h>       // setlocale

//#include "MODELOENC.h"    // defini��o do registro

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
	node *LISTA = (node *) malloc(sizeof(node)); //cria um ponteiro do tipo node, que que recebe um espa�o de mem�ria para alocar.

	


return 0;
	
}


void inicia (node *LISTA);
{
	
	node->prox = NULL;
		
}


void insere_Inicio (node *LISTA);
{
	Agora devemos fazer dois passos: primeiros fazemos 
	LISTA->prox apontar para nosso novo n�, 
	depois fazemos nosso n� apontar para o pr�ximo elemento da lista.

	Mas aqui temos um problema.
	Antes o 'LISTA->prox' apontava para um local de mem�ria que tinha o pr�ximo n�.
	Mas quando apontamos ele para o n� 'novo', perdemos essa refer�ncia.


	Vamos resolver isso criando um ponteiro para armazenar o local que est� 'LISTA->prox' antes de inserirmos o novo n�.
	Vamos chamar de 'oldHead', pois era a cabe�a antiga da lista:
	node *oldHead = LISTA->prox;
	
	Ent�o, agora apontamos a cabe�a da lista para nosso novo n�: LISTA->prox = novo;
	E apontamos nosso novo n� para o n� antigo: novo->prox = oldHead;
	
	
	node *novoNode = (*node)malloc(sizeof(node));
	
	novoNode = node->prox; 
		
	node *oldhead; //criado n� antigo para armezar o endere�o anterior
	oldhead = node->prox; //
	
	
	





		
}



