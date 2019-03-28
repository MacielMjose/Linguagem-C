/***********************************************/ 
/* Lista Encadeada                             */
/* objetivo: cadastro de pessoas               */
/* programador: Daniela Bagatini               */
/* criado em: 01/04/2016                       */
/* data da ultima alteracao: 01/03/2019        */
/***********************************************/ 

#include <stdio.h>
// #include <conio.h>
#include <stdlib.h>		  // exit; malloc; system
#include <string.h>	  	  // strcmp
#include <time.h>
#include <locale.h>       // setlocale

//#include "MODELOENC.h"    // defini��o do registro

#define True 1

/***********************************************/ 
/* Defini��o dos Registros                     */
/**********************************************/

typedef struct {                   // registro para uma pessoa
       int  codigo;
       char nome[30];
}INFORMACAO;

typedef struct LISTA {
       INFORMACAO info;    // dados do registro
       struct LISTA *prox;          // ponteiro do tipo LISTA que aponta para o pr�ximo registro
}LISTAENC; 

/***********************************************/ 
/* Defini��o das Fun��es                       */
/***********************************************/ 
void    entrada_dados  ( LISTAENC *prox ); // leitura dos dados de entrada
void    imprime_lista  ( LISTAENC *aux ); // visualiza��o da lista em tela
void    cria_lista     ( LISTAENC* *l );  // inicializa lista com NULL
void    inclui_fim     ( LISTAENC* *l );  // inclui um novo registro no final da lista
void    inclui_inicio  ( LISTAENC* *l );  // inclui um novo registro no inicio da lista
LISTAENC*   procura_LISTAENC   ( LISTAENC* l, int cod ); // procura na lista por uma c�digo
void    exclui_LISTAENC    ( LISTAENC* *l );  // exclui um regitro por c�digo 
void    ordena_lista   ( LISTAENC* *l );  // ordena lista por c�digo
void    inclui_ordenado( LISTAENC* *l );  // inclui registro na lista ordenado por c�digo
void    inverte        ( LISTAENC* *l );  // inverte refer�ncia dos registros
void    consulta_nome  ( LISTAENC* l );   // consulta por um nome
void    inserir_antes  ( LISTAENC* *l );  // inserir um registro antes de uma c�digo de refer�ncia
void    inserir_depois ( LISTAENC* *l );  // inserir um registro depois de uma c�digo de refer�ncia
void    conta_LISTAENC     ( LISTAENC* *l );  // contar o n�mero de registros existentes na lista


/***********************************************/ 
/* Programa Principal                          */
/***********************************************/ 
int main( void )
{
    int op;          // op��o do menu                               
    LISTAENC* l;         // declara��o da lista - ponteiro
    
    setlocale(LC_ALL, "Portuguese");	// alterar idioma para portugu�s
    
    cria_lista( &l );	// rotina cria lista  
    while( True ){
         printf( "\n /----------------------------------------------------/" );  // menu
         printf( "\n Programa de cadastro - Menu                           " );
         printf( "\n [1 ]  Cria lista                                      " );
         printf( "\n [2 ]  Inclui registro no final da lista               " );
         printf( "\n [3 ]  Inclui registro no in�cio da lista              " );
         printf( "\n [4 ]  Exclui registro                                 " );
         printf( "\n [5 ]  Ordena lista                                    " );
         printf( "\n [6 ]  Inlcui ordenado                                 " );
         printf( "\n [7 ]  Inverte lista                                   " );         
         printf( "\n [8 ]  Consulta nome                                   " );         
         printf( "\n [9 ]  Inserir antes                                   " );           
         printf( "\n [10]  Inserir depois                                  " );     
         printf( "\n [11]  Conta registros                                 " );           
         printf( "\n [12]                                                  " );  
         printf( "\n [13]  Imprime lista                                   " );  
         printf( "\n [0 ]  Para sair do programa                           " );
         printf( "\n /----------------------------------------------------/" );      
         printf( "\n Op��o: " );
         fflush( stdin );
         scanf("%d", &op); // tecla de op��o do menu
         

         switch( op ) {
            case 1: // rotina cria lista       
                    //cria_lista( &l );
                    break;
                                
            case 2:  // rotina inclui registro no final da lista
                    inclui_fim( &l );   
                    /*t= NULL; 
                    t= l;
                    printf( "\n Lista t");
                    imprime_lista( t ); */
                    break;
          
            case 3:  // rotina inclui registro no in�cio da lista
                    inclui_inicio( &l );
                    break;
                
            case 4:  // rotina exclui registro da lista
                    exclui_LISTAENC( &l );
                    break;
                  
            case 5:  // rotina ordena lista
                    ordena_lista( &l );
                    break;

            case 6:  // rotina inclui ordenado
                    inclui_ordenado( &l );
                    break;
                                                                                   
            case 7: // rotina inverte lista                 
                    inverte( &l ); 
                    break;                                
                    
            case 8: // rotina consultar por um nome                 
                    consulta_nome( l ); 
                    break;             

            case 9: // rotina inserir antes de um c�digo                 
                    inserir_antes( &l ); 
                    break; 

            case 10: // rotina inserir depois de um c�digo                 
                    inserir_depois( &l ); 
                    break; 
                                                                               
            case 11: // rotina contar o n�mero de registros na lista                 
                    conta_LISTAENC( &l ); 
                    break; 

            case 12: // rotina ...                 
                    // crie sua rotina; 
                    break;

            case 13: // rotina imprime lista                 
                    imprime_lista( l ); 
                    break;                        
            case 0: // t�rmino do programa                                                 
                    exit( True ); 
                    break;
                
            default : 
                    printf( "\n Digite uma opcao!" ); // n�o foi digitado uma op��o v�lida
                    break;
         } // switch( op )
 
        printf( "\n\n" );
        system( "pause" ); // pausar programa
        system( "cls" ); // limpar tela
     } // fim do while( 1 )
} // fim do programa principal



/************************************************ 
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : LISTAENC (ponteiro para o novo espaco) *
 * saida   : LISTAENC com dados                     *
 ************************************************/
 
void entrada_dados( INFORMACAO *prox )
{	

	LISTAENC * no = (LISTAENC *)malloc(sizeof(LISTAENC)); //alocar memoria para um registro do tipo LISTAENC

   		
    	printf("\n informe o codigo:");		// limpa buffer do teclado, funciona junto com entrada de dados   
	 	fflush( stdin );  
		scanf("%i",&no->info.codigo);
		
	
		/*printf( "\n Digite o nome: " );
		fflush( stdin );  
		scanf("")*/
		   
}




/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * saida   : nenhuma                             *
 *************************************************/ 
void imprime_lista( LISTAENC *aux ){
     
    if( aux == NULL )
        printf( "\n Lista vazia!" );
	else{
	    printf("\n\n ---- Relat�rio Geral ---- ");
        while( aux != NULL ){                            // ponteiro auxiliar para a lista
               //printf( "\n Nome..: %s", aux->info.nome );
               printf( "\n C�digo: %d", aux->info.codigo );
               aux = aux->prox;                          // aponta para o proximo registro da lista
		 } // fim while( aux != NULL )
	} // fim if( aux == NULL )
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : lista                              *
 * sa�da   : NULL (inicializa lista)            *
 ************************************************/ 
 
void cria_lista (LISTAENC * *l)
{
	
	LISTAENC * no = (LISTAENC *)malloc(sizeof(LISTAENC)); //alocar memoria para um registro do tipo LISTAENC
	 
	 if( no == NULL      ) //verifica se o valor do ender�o que no guarda � null, isso signifca que naoc onseguiu alocar memoria
	 {
		printf("Nao existe espa�o na maemoria para aloca��o!\n");
	 }
	 else
	 {
	 	//entrada_dados(no);             //pasa o no para a fun��oi de entrada de dados
	 	
	 	no->prox = NULL;
	 	
		
	}
}


/************************************************ 
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * saida   : lista com novo registro            *
 ************************************************/ 
void inclui_fim( LISTAENC* *l )

{
	
	LISTAENC * no = (LISTAENC *)malloc(sizeof(LISTAENC)); //alocar memoria para um registro do tipo LISTAENC

	     
	 	if(*l == NULL)  // lista vazia
	 	
	 		*l = no;   //l recebe o endere�o com espa�o na memoria fornecido pelo Maclloc
	 		
	 		else{                                    //achar o null da lista para verificar se chegou no fim
	 				 
	 				 LISTAENC *p = *l;   //~variavel do tipo LISTAENC para armazenar o endere�o de L para que o mesmo nao seja perdido
	 				
	 				 //p = *l;   
	 				 
	 				 while (p->prox != NULL)   //percorrer a lista enquanto p n�o encontrar o ultimo no caso NULL
	 				 
					  		p = p->prox; // p avan�a para o proximo registro
	 				 
	 				 p->prox = no; 				//novo registro foi inserido na lista, o proximo de p (p->prox) recebe no, que � NULL
	 				 	
			 }
	 		
	 		printf("\n Registro foi inserido!");
	 	
	 }
	    
  
     
/*************************************************** 
 * inclui_inicio                                   *
 * objetivo: rotina para inserir no inicio da lista*
 * entrada : referencia de lista                   *
 * sa�da   : referencia lista com novo registro    *
 ***************************************************/ 
void inclui_inicio( LISTAENC* *l ){
 
 
}



/************************************************ 
 * procura_LISTAENC                                 *
 * objetivo: achar um registro por c�digo       *
 * entrada : lista e c�digo a ser procurado     *
 * sa�da   : posi��o ou NULL (n�o encontrou)    *
 ************************************************/ 
LISTAENC* procura_LISTAENC( LISTAENC* p, int cod ){
           

}



/*************************************************** 
 * exclui_LISTAENC                                     *
 * objetivo: rotina para excluir LISTAENC da lista     *
 * entrada : lista                                 *
 * saida   : lista                                 *
 ***************************************************/ 
void exclui_LISTAENC( LISTAENC** l ){
     

}



/*************************************************** 
 * ordena_lista                                    *
 * objetivo: rotina para ordenar a lista           *
 * entrada : lista                                 *
 * saida   : lista ordenada por codigo             *
 ***************************************************/ 
void ordena_lista( LISTAENC** l ){
     
 
}



/*************************************************** 
 * inclui_ordenado                                 *
 * objetivo: rotina para inserir em ordem de codigo*
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inclui_ordenado( LISTAENC** l ){
     

}



/*************************************************** 
 * inverte referencia                              *
 * objetivo: rotina para inverter referencia do reg*
 * entrada : lista                                 *
 * saida   : lista com referencia invertida        *
 ***************************************************/ 
void inverte( LISTAENC** l ){
     

}



/*************************************************** 
 * consulta nome                                   *
 * objetivo: rotina para consultar                 *
 * entrada : lista                                 *
 * saida   : lista                                 *
 ***************************************************/ 
void consulta_nome( LISTAENC* l ){
 
}



/*************************************************** 
 * inserir antes                                   *
 * objetivo: rotina para inserir antes de uma matr *
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inserir_antes( LISTAENC** l ){
     
 
}



/*************************************************** 
 * inserir depois                                  *
 * objetivo: rotina para inserir antes de uma matr *
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inserir_depois( LISTAENC** l ){
     

}


/*************************************************** 
 * conta_LISTAENC                                      *
 * objetivo: rotina para contar numero de registros*
 * entrada : lista                                 *
 * saida   : nenhuma                               *
 **************************************************/ 
void conta_LISTAENC( LISTAENC** l ){
     

}
