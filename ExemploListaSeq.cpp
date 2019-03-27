/***********************************************/
/* Lista Sequencial                            */
/* objetivo: controle de registros             */
/* programador: Daniela Bagatini               */
/* criado em: 20/08/2017                       */
/* data da ?ltima altera??o: 29/08/2018        */
/***********************************************/

#include <stdio.h>
#include <stdlib.h> // exit, system("cls")
#include <string.h> // strcmp
#include <locale.h> // setlocale
//#include <ctype.h>// toupper
#include <time.h>   // rand

//#include "MODELOSEQ.h" // biblioteca criada///

//#define N_MAX   1000  // n?mero m?ximo de registros

/***********************************************/ 
/* Defini??o dos Registros                     */
/***********************************************/ 

#define N_MAX   100

typedef struct {                   // registro para uma pessoa
       int  codigo;
       char nome[30];
}INFORMACAO;
       
typedef struct {
       INFORMACAO info[N_MAX];    // dados do registro
       int f;                     // n?mero de registro(s) ocupado(s) na estrutura
}NODO;                            // estrutura do tipo NODO

/***********************************************/
/* Defini??o das Fun??es                       */
/***********************************************/
void entrada_dados   ( INFORMACAO *aux ); // leitura dos dados de entrada
void imprime_lista   ( NODO lista );  // visualiza??o da lista em tela
void cria_lista      ( int *fim );    // inicializa lista com tamanho 0
void inclui_fim      ( NODO *lista ); // inclui um novo registro no final da lista
void inclui_inicio   ( NODO *lista ); // inclui um novo registro no in?cio da lista
int  procura_nodo    ( int cod, NODO lista ); // procura por um c?digo na lista
void inclui_antes    ( NODO *lista ); // inclui um novo registro antes de um c?digo de refer?ncia
void inclui_depois   ( NODO *lista ); // inclui um novo registro depois de um c?digo de refer?ncia
void exclui_nodo     ( NODO *lista ); // exclui um regitro por c?digo
void ordena_lista    ( NODO *lista ); // ordena por c?digo - ordem crescente 
void altera_nodo     ( NODO *lista ); // altera um regitro a partir de um c?digo de refer?ncia
void inclui_ordenado ( NODO *lista ); // inlcui em ordem crescente de c?digo
void busca_binaria   ( NODO lista );  // realiza busca bin?rios por c?digo
void compara_repetidos( NODO *lista );// verifica c?digos repetidos
void elimina_repetidos( NODO *lista );// verifica c?digos repetidos e exclui, se lista ordenada
int  aleatorio       ( int max );     // gera n?mero aleat?rio 
void gera_dados      ( NODO *lista ); // gera dados de forma autom?tica
int f ( NODO l );

/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main( void )
{
    int op, i;           // op??o do menu
    NODO lista;       // vari?vel do tipo lista sequencial = vetor de registros
    setlocale( LC_ALL, "Portuguese" );

    while( 1 ){
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Programa registro de pessoas - Menu                       " );
         printf( "\n [1 ] Cria lista                                           " );
         printf( "\n [2 ] Inclui registro no final da lista                    " );
         printf( "\n [3 ] Inclui registro no in?cio da lista                   " );
         printf( "\n [4 ] Inclui registro antes de um c?digo de refer?ncia     " );
         printf( "\n [5 ] Inclui registro depois de um c?digo de refer?ncia    " );
         printf( "\n [6 ] Exclui registro                                      " );
         printf( "\n [7 ] Ordena lista                                         " );
         printf( "\n [8 ] Altera registro                                      " );         
         printf( "\n [9 ] Inclui ordenado por c?digo                           " );                  
         printf( "\n [10] Busca bin?ria por c?digo                             " );
         printf( "\n [11] Compara repetidos                                    " );
         printf( "\n [12] Elimina repetidos                                    " );                  
         printf( "\n [13] Gera dados                                           " ); 
		 printf( "\n [14] Imprime lista                                        " );
         printf( "\n [0 ] Para sair do programa                                " );
         printf( "\n /--------------------------------------------------------/" );
         printf( "\n Op??o: " );
         fflush( stdin );   // limpa buffer do teclado, funciona antes da entrada de dados
         scanf( "%i", &op );// tecla de op??o do menu
         
         switch( op ) {
            case 1:  // rotina cria lista, inicializa a lista
                    cria_lista( &lista.f );
                    break;

            case 2:  // rotina inclui registro no final da lista, conforme indicado pelo gerenciados da lista (lista.f)
                    inclui_fim( &lista );
                    break;

            case 3:  // rotina inclui registro no in?cio da lista, posi??o 0
                    inclui_inicio( &lista );
                    break;

            case 4:  // rotina inclui registro antes de um c?digo de refer?ncia
                     inclui_antes( &lista );
                     break;

            case 5:  // rotina inclui registro depois de um c?digo de refer?ncia
                    inclui_depois( &lista );
                    break;

            case 6:  // rotina exclui registro conforme c?digo de refer?ncia
                    exclui_nodo( &lista );
                    break;

            case 7: // rotina ordena lista por c?digo
                    ordena_lista( &lista );
                    break;
                    
            case 8: // rotina altera registro com base no c?digo de refer?ncia
                    altera_nodo( &lista );
                    break;
                    
            case 9: // rotina inclui registro de forma ordenada na lista por c?digo
                    ordena_lista( &lista );  // ordena toda lista para garantir que ir? incluir o novo registro em ordem            
                    inclui_ordenado( &lista );
                    break;

            case 10: // rotina busca registro na lista por c?digo de forma bin?ria (em m?dia, reduz o n?mero de compara??es) 
                    ordena_lista( &lista );  // ordena toda lista para garantir que ir? buscar registro em lista ordenada, necess?rio para o algoritmo de busca bin?ria                      
                    busca_binaria( lista );   
                    break;            
                    
            case 11: // rotina compara registros com c?digo repetidos
                    compara_repetidos( &lista );
                    break;                     
                    
            case 12: // rotina exclui registros com c?digo repetido
                    ordena_lista( &lista );  // ordena toda lista para garantir que ir? eliminar repetidos                     
                    elimina_repetidos( &lista );
                    break;      

            case 13: // rotina gera dados de forma autom?tica para povoar a lista
                    gera_dados( &lista );
                    break;      
                                                               
            case 14: // rotina imprime todos os registros da lista
                    imprime_lista( lista );
                    i= f( lista );
                    printf("i: %i", i);
                    break;
                    
            case 0: // t?rmino do programa
                    exit( 1 );
                    break;

            default :
                    printf( "\n Digite uma op??o!" );
                    break;
        } // switch( op )
        printf( "\n\n" );
        system( "pause" );
        system( "cls" );
     } // fim do while( 1 )
 return 0;
} // fim do programa principal



/************************************************
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : registro aux (auxiliar)            *
 * sa?da   : aux atualizado com dados           *
 ************************************************/
void entrada_dados( INFORMACAO *aux )
{
    printf( "\n\n Digite o c?digo: " );
    fflush( stdin );                             // limpa buffer do teclado, funciona junto com entrada de dados
    scanf( "%d", &aux->codigo );

    printf( "\n Digite o nome: " );
    fflush( stdin );     
    gets( aux->nome );
}



/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * sa?da   : nenhuma, apenas em tela             *
 *************************************************/
void imprime_lista( NODO lista ){
     
    int i;                                       // ?ndice do la?o

    if( lista.f == 0 )                           // lista vazia
        printf( "\n Lista vazia!" );

    for( i = 0 ; i < lista.f ; i++ ) {           // percorre a lista
         printf( "\n C?digo...: %d", lista.info[ i ].codigo );
         printf( "\n Nome.....: %s", lista.info[ i ].nome );
    }
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : fim da lista                       *
 * sa?da   : fim da lista atualizado, com 0     *
 ************************************************/
void cria_lista( int *fim ){
     
    *fim = 0;                                   // iniciliza lista, tamanho da lista = 0
    printf( "\n Lista criada!" );
}



/************************************************
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * sa?da   : lista com novo elemento            *
 ************************************************/
void inclui_fim( NODO *lista ){
     
    if( lista->f == N_MAX )                     // verifica se a lista est? cheia
        printf( "\n Lista cheia!" );
    else{
        INFORMACAO aux;                        // auxiliar para a entrada de dados
        entrada_dados( &aux );                 // l? dados, entrada
        lista->info[ lista->f ] = aux;         // inclui dados ao final da lista
        lista->f++;                            // incrementa o tamanho da lista
        printf( "\n Registro inclu?do no fim!" );
    }
}



/************************************************
 * inclui_in?cio                                *
 * objetivo: inserir no in?cio da lista         *
 * entrada : lista                              *
 * sa?da   : lista com novo elemento            *
 ************************************************/
void inclui_inicio( NODO *lista ){
     
    int i;                                      // i = ?ndice

    if( lista->f == N_MAX )                     // verifica se a lista esta cheia
        printf( "\n Lista cheia!" );
    else{
        INFORMACAO aux;                         // auxiliar para a entrada de dados
        entrada_dados( &aux );                  // l? dados
        for ( i = lista->f ; i > 0 ; i-- )      // desloca lista at? abrir esp?o no in?cio = posi??o 0
              lista->info[ i ] = lista->info[ i - 1 ]; // deslocamento
        lista->info[ 0 ] = aux;                 // insere na lista - outra op??o: mencpy(&lista.info[lista.f], &aux, sizeof(NODO));
        lista->f++;                             // incrementa o tamanho da lista  
        printf( "\n Registro inclu?do no in?cio!" );
    }
}



/************************************************
 * procura_nodo                                 *
 * objetivo: achar posi??o a partir de um campo *
 * entrada : c?digo de refer?ncia e lista       *
 * sa?da   : posi??o f?sica da refer?ncia ou -1 *
 ************************************************/
int procura_nodo( int cod, NODO lista ){
        
    int i= 0;                                   // i = ?ndice

    while(( i < lista.f ) && ( cod != lista.info[ i ].codigo )) // anda pela lista at? o final ou ate encontrar c?digo desejado
            i++;
    if( cod == lista.info[ i ].codigo )         // se encontou c?digo igual    
        return( i );                            // posi??o f?sica do nodo de refer?ncia
    else       
        return( -1 );                           // valor n?o encontrado
}



/************************************************
 * inclui_antes                                 *
 * objetivo: inserir antes de um c?digo         *
 * entrada : lista                              *
 * sa?da   : lista com novo elemento            *
 ************************************************/
void inclui_antes( NODO *lista ){
     
    if( lista->f == N_MAX )                     // verifica se a lista esta cheia
        printf( "\n Lista cheia!" );
    else{
        int i, cod, pf = 0;                     // i= ?ndice; cod= c?digo de refer?ncia; pf= posicao fisica do codigo de referencia         
        printf( "\n C?digo de refer?ncia: " );
        fflush( stdin );
        scanf( "%d", &cod );                   // limpa buffer do teclado, funciona junto com entrada de dados
        pf= procura_nodo( cod, *lista );       // procura c?digo de refer?ncia

        if( ( pf >= 0 ) && ( pf < lista->f ) && ( lista->info[ pf ].codigo == cod ) ){ // verifica se a posi??o e o codigo s?o v?lidos
              INFORMACAO aux;                         // auxiliar para a entrada de dados
              entrada_dados( &aux );                  // l? dados
              for( i = lista->f - 1 ; i >= pf ; i-- ) // desloca a lista at? abrir um espa?o antes do nodo de refer?ncia
                   lista->info[ i + 1 ]= lista->info[ i ];
              lista->info[ pf ] = aux;                // insere na lista
              lista->f++;                             // incrementa o tamanho da lista//mencpy(&lista.info[lista.f], &aux, sizeof(NODO));
              printf( "\n Registro incluido antes do nodo de refer?ncia!" );
         }else 
              printf( "\n Nodo de refer?ncia n?o existe!" );
    } 
}



/************************************************
 * inclui_depois                                *
 * objetivo: inserir depois de um c?digo        *
 * entrada : lista                              *
 * sa?da   : lista com novo elemento            *
 ************************************************/
void inclui_depois( NODO *lista ){
 
    if( lista->f == N_MAX )                     // verifica se a lista est? cheia
        printf( "\n Lista cheia!" );
    else{
        int i, cod, pf = 0;                     // i= ?ndice; cod= c?digo de refer?ncia; pf= posi??o f?sica do c?digo de refer?ncia         
        printf( "\n C?digo de refer?ncia: " );
        fflush( stdin );
        scanf( "%d", &cod );                    // limpa buffer do teclado, funciona junto com entrada de dados
        pf = procura_nodo( cod, *lista );       // procura c?digo de refer?ncia

        if( ( pf >= 0 ) && ( pf < lista->f ) && ( lista->info[ pf ].codigo == cod ) ){ // verifica se a posi??o e o c?digo s?o v?lidos
              INFORMACAO aux;                        // auxiliar para a entrada de dados
              entrada_dados( &aux );                 // l? dados
              for ( i = lista->f - 1 ; i > pf ; i-- )// desloca da lista at? abrir espa?o depois do nodo de refer?ncia
                    lista->info[ i + 1 ] = lista->info[ i ];
              lista->info[ pf + 1 ] = aux;           // insere na lista
              lista->f++;                            // incrementa o tamanho da lista //mencpy(&lista.info[lista.f], &aux, sizeof(NODO));
              printf( "\n Registro incluido depois do nodo de refer?ncia!" );
         }else 
              printf( "\n Nodo de refer?ncia nao existe!" );
    } 
}



/************************************************
 * exclui_nodo                                  *
 * objetivo: rotina para excluir registro       *
 * entrada : lista                              *
 * sa?da   : lista com um elemento removido     *
 ************************************************/
void exclui_nodo( NODO *lista ){
     
    if( lista->f == 0 )                        // verifica se a lista est? vazia
         printf( "\n Lista vazia!" );
    else{
        int i, cod, pf = 0;                    // i= indice; cod= c?digo de refer?ncia; pf= posi??o f?sica         
        printf( "\n C?digo de refer?ncia: " );
        fflush( stdin );
        scanf( "%d", &cod );                   // limpa buffer do teclado, funciona junto com entrada de dados
        pf = procura_nodo( cod, *lista );      // procura c?digo de refer?ncia, a fun??o devolve a posi??o na lista onde est? o c?digo (-1 se n?o encontrar)

        if( ( pf >= 0 ) && ( pf < lista->f ) && ( lista->info[ pf ].codigo == cod ) ){ // verifica se a posicao e o c?digo s?o v?lidos
              for ( i = pf; i < lista->f - 1 ; i++ ) // desloca a lista at? que fiquei cont?gua
                    lista->info[ i ] = lista->info[ i + 1 ]; // deslocamento
              lista->f--;                     // decrementa o tamanho da lista  //mencpy(&lista.info[lista.f], &aux, sizeof(NODO));
              printf( "\n Registro exclu?do!" );
        }else 
              printf( "\n Nodo de refer?ncia n?o existe!" );
    } 
}



/************************************************
* ordena_lista                                  *
* objetivo: rotina para ordenar lista por c?digo*
* entrada : lista                               *
* sa?da   : lista ordenada                      *
*************************************************/
void ordena_lista( NODO *lista ){              // Algoritmo M?todo Bolha - Bubble Sort
     
    if( lista->f == 0 )                        // verifica se a lista est? vazia
        printf( "\n Lista vazia!" );
    else
       if( lista->f == 1 )                     // verifica se a lista tem apenas um registro
           printf( "\n Lista com apenas um registro!" );
       else{
           int i, j;                           // i, j = ?ndices para percorrer a lista
           INFORMACAO aux;                     // auxiliar para a troca de dados
           for( i = 0; i < lista->f-1; i++ )   // percorre a lista realizando a compara??o entre registros
                for( j = i + 1; j < lista->f; j++ )
                     if( lista->info[ j ].codigo < lista->info[ i ].codigo ){ // se c?digo do sucessor for maior, troca
                         aux = lista->info[ j ]; // realiza a troca utilizando registro auxiliar
                         lista->info[ j ] = lista->info[ i ];
                         lista->info[ i ] = aux;
                     }
           printf( "\n Lista ordenada!" );
          }
}



/************************************************
 * altera_nodo                                  *
 * objetivo: rotina para alterar registro       *
 * entrada : lista                              *
 * sa?da   : lista com um elemento alterado     *
 ************************************************/
void altera_nodo( NODO *lista ){
        
    if( lista->f == 0 )                        // verifica se a lista est? vazia
        printf( "\n Lista vazia!" );
    else{
        int op, cod, pf = 0;                   // i= ?ndice; cod= c?digo de refer?ncia; pf= posi??o f?sica         
        printf( "\n C?digo de refer?ncia: " );
        fflush( stdin );                       // limpa buffer do teclado, funciona antes da entrada de dados
        scanf( "%d", &cod );                   // l? c?digo de refer?ncia
        pf= procura_nodo( cod, *lista );       // procura c?digo de refer?ncia
         
        if( ( pf >= 0 ) && ( pf < lista->f ) && ( lista->info[ pf ].codigo == cod ) ){ // verifica se a posi??o na lista ? v?lida e se existe o c?digo de refer?ncia
              printf( "\n Informe campo que ser? alterado:                         " );         
              printf( "\n [1] Nome                                                 " );                               
              printf( "\n /-------------------------------------------------------/" );
              printf( "\n Op??o: " );
              fflush(stdin);
              scanf("%d", &op);                // tecla de op??o do menu
                
              switch( op ) {
                      case 1:  // nome
                            printf("\n Nome: ");
                            fflush(stdin);
                            gets(lista->info[pf].nome); //ou usar gets(nome); outra op??o: strcpy(lista->info[pf].nome, nome); quando o nome for lido em outra vari?vel
                            break;
        
	                   //case 2:  // para outros campos
	                      //        printf( "\n CPF: " );
	                      //        fflush(stdin);                            
	                      //        gets(lista->info[pf].cpf);
	                      //        break;
	        
                      default:
                             printf( "\n Digite uma op??o!" );
                             break;
              } 
         }else
              printf( "\n Registro de refer?ncia n?o encontrado!" );
    }
}             



/************************************************
 * inclui_ordenado                              *
 * objetivo: rotina que inclui registro ordenado*
 * entrada : lista                              *
 * sa?da   : lista com novo elemento            *
 ************************************************/         
void inclui_ordenado ( NODO *lista ){
     
    if( lista->f == N_MAX )                    // verifica se a lista esta cheia
        printf( "\n Lista cheia!" );
    else{
        INFORMACAO aux;                       // auxiliar para a entrada de dados             
        entrada_dados( &aux );                // l? dados
        int i= lista->f-1;                    // iniciliza i para realizar o deslocamento dos registros e incluir novo registro na ordem             
        while( i >= 0 && aux.codigo < lista->info[ i ].codigo ){
               lista->info[ i + 1 ]= lista->info[ i ]; // deslocamento dos registros
               i--;                           // caminha pela lista at? encontrar posi??o ordenada
        }       
        lista->info[ i + 1 ]= aux;            // inclui na posi??o ordenada
        lista->f++;                           // incrementa o controle da lista
        printf( "\n Registro incluido no fim!" );
    }
}



/************************************************
 * busca_bin?ria                                *
 * objetivo: rotina busca bin?ria por c?digo    *
 * entrada : lista                              *
 * sa?da   : nenhuma                            *
 ***********************************************/    
void busca_binaria( NODO lista ){
        
    if( lista.f == 0 )                              // verifica se a lista est? vazia
        printf( "\n Lista vazia!" );
    else{
        int cod, meio, inicio= 0, fim= lista.f-1;   // iniciliza inicio e fim             
        printf( "\n C?digo de refer?ncia: " );
        fflush( stdin );                            // limpa buffer do teclado, funciona junto com entrada de dados
        scanf( "%d", &cod );                        // c?digo a ser buscado
        do{
               meio= ( int )( inicio + fim )/2;     // encontra o ?ndice do meio
               if( cod < lista.info[ meio ].codigo )// verifica se c?digo procurado ? menor do que aquele que est? na lista no ?ndice do meio
                   fim= meio - 1;                   // se c?digo menor, possiciona novo fim
               else    
                   inicio= meio + 1;                // se c?digo maior, possiciona novo in?cio
        }while( inicio <= fim && lista.info[ meio ].codigo != cod ); // enquanto in?cio n?o ultrapassar fim e n?o encontrar o c?digo, repete
             
        if( lista.info[ meio ].codigo == cod )      // verifica se encontrou o c?digo
            printf("\n Nome: %s", lista.info[ meio ].nome);
        else    
            printf("\n Registro n?o encontrado!"); 
    }
}



/************************************************
 * compara_repetidos                            *
 * objetivo: rotina compara registros           *
 * entrada : lista                              *
 * sa?da   : nenhuma                            *
 ************************************************/ 
void compara_repetidos ( NODO *lista ){   
     
    int i= 0, j, c= 0;

    while( i < lista->f-1 ){                   // enquanto i n?o chegar ao final da lista, compara
           j= i + 1;                           // posiciona j no sucessor de i
           while( j < lista->f ){              // enquanto j n?o chegar ao final da lista, compara
                  if( lista->info[ i ].codigo == lista->info[ j ].codigo ) // comapra de as posi??o i e j possuem o mesmo valor de c?digo
                      c++;                     // conta n?mero de repetidos
                  j++;                         // j anda pela lista
           }        
           i++;                                // i anda pela lista
    }
    printf("\n N?mero de repetidos: %i", c);   // mostra quantidade de c?digo repetidos que existem na lista
}



/************************************************
 * elimina_repetidos                            *
 * objetivo: rotina exclui registros repetidos  *
 * entrada : lista                              *
 * sa?da   : lista atualizada                   *
 ***********************************************/ 
void elimina_repetidos( NODO *lista ){ //FUN??O N?O VALIDADA COM NOME!!!!!!!!!!!!!!!!!!!!
    
    if( lista->f == 0 )                        // lista vazia 
        printf( "\n N?o h? registros cadastrados!" );
    else{   
         if ( lista->f == 1 )                  // lista com um registro
             printf( "\n Existe apenas um registro!" );
         else{     
               int i= 0;                       // posiciona i na lista no primeiro registro 
			   int temp;                       // temp = auxiliar para exclus?o do repetido 
               while( i < lista->f ){          // caminha at? o ?ltimo registro  
                     //if( strcmp( lista->info[ i ].nome, lista->info[ i + 1 ].nome ) == 0 ) { // verificar se nomes s?o iguais
					 if( lista->info[ i ].codigo == lista->info[ i + 1 ].codigo ) { // verificar se c?digos s?o iguais
                         temp= i + 1;          // posiciona o temp no registro repetido que ser? excluido
                         while( temp < lista->f ){
		  		                lista->info[ temp ]= lista->info[ temp + 1 ]; // ajusta a lista realizando o deslocamento dos registros posterior
		  		                temp++;
                         }
						 lista->f--;           // atualiza n?mero de registros na lista
                     }
                     else
                         i++;                  // i anda pela lista
               }
               printf( "\n Repetidos eliminados!" );        
         }
    }    
}


/************************************************
 * aleatorio                                    *
 * objetivo: rotina para gerar um n?mero        *
 * aleat?rio de um valor m?ximo estipulado      *
 * entrada : max                                *
 * sa?da   : n?mero aleat?rio                   *
 ************************************************/
int aleatorio( int max ){
	
	int ret = rand() % max; // gera n?mero com base em max = n?mero m?ximo
	return ret;
}


/************************************************
 * gera_dados                                   *
 * objetivo: rotina para ler dados dos registros*
 * entrada : lista                              *
 * sa?da   : lista atualizado com dados         *
 ************************************************/
void gera_dados( NODO *lista ){
	 
	char  nomeTemp[50];                        // armazena nome e sobrenome temporariamente
	int   i, x;                                // i= ?ndice da lista; x= armazena n?mero sorteado 
	float nota;                                // armazena nota temporariamente 
	
	//Fonte dos nomes: https://petitebox.com.br/blog/100-nomes-mais-comuns-no-brasil-em-2016/
	char *nomes[] = {"Miguel",
"Arthur",
"Davi",
"Bernardo",
"Heitor",
"Gabriel",
"Pedro",
"Lorenzo",
"Lucas",
"Matheus",
"Enzo",
"Theo",
"Benjamin",
"Rafael",
"Nicolas",
"Guilherme",
"Gustavo",
"Samuel",
"Henrique",
"Felipe",
"Murilo",
"Joaquim",
"Joao Pedro",
"Joao Miguel",
"Enzo Gabriel",
"Daniel",
"Isaac",
"Pietro",
"Pedro Henrique",
"Lucca",
"Eduardo",
"Benicio",
"Leonardo",
"Vitor",
"Joao Lucas",
"Bryan",
"Joao",
"Caua",
"Davi Lucca",
"Anthony",
"Vicente",
"Vinicius",
"Caio",
"Antonio",
"Davi Lucas",
"Bento",
"Joao Gabriel",
"Joao Vitor",
"Noah",
"Francisco",
"Calebe",
"Gael",
"Emanuel",
"Ian",
"Luiz Miguel",
"Enrico",
"Thiago",
"Augusto",
"Otavio",
"Joao Guilherme",
"Ryan",
"Yuri",
"Levi",
"Vitor Hugo",
"Erick",
"Bruno",
"Nathan",
"Raul",
"Henry",
"Davi Luiz",
"Luiz Felipe",
"Thomas",
"Rodrigo",
"Davi Miguel",
"Andre",
"Fernando",
"Alexandre",
"Pedro Lucas",
"Breno",
"Arthur Miguel",
"Carlos Eduardo",
"Kaique",
"Yago",
"Kaue",
"Luan",
"Igor",
"Luiz Henrique",
"Luiz Gustavo",
"Arthur Gabriel",
"Mathias",
"Lucas Gabriel",
"Pedro Miguel",
"Arthur Henrique",
"Ruan",
"Tomas",
"Danilo",
"Enzo Miguel",
"Luiz Otavio",
"Ricardo",
"Oliver",
"Alice",
"Sophia",
"Laura",
"Valentina",
"Helena",
"Isabella",
"Manuela",
"Julia",
"Luiza",
"Livia",
"Giovanna",
"Maria Luiza",
"Heloisa",
"Maria Eduarda",
"Maria Clara",
"Lara",
"Lorena",
"Beatriz",
"Mariana",
"Melissa",
"Cecilia",
"Ana Clara",
"Ana Julia",
"Yasmin",
"Maria Julia",
"Isadora",
"Rafaela",
"Emanuelly",
"Ana Luiza",
"Esther",
"Lavinia",
"Sarah",
"Isabelly",
"Elisa",
"Eloah",
"Nicole",
"Maria Alice",
"Gabriela",
"Maria",
"Rebeca",
"Leticia",
"Clara",
"Marina",
"Isis",
"Ana",
"Alicia",
"Liz",
"Antonella",
"Maria Cecilia",
"Agatha",
"Catarina",
"Ana Laura",
"Larissa",
"Ana Beatriz",
"Maria Fernanda",
"Maite",
"Luna",
"Olivia",
"Vitoria",
"Bianca",
"Lais",
"Allana",
"Maria Valentina",
"Emilly",
"Ana Sophia",
"Clarice",
"Milena",
"Pietra",
"Fernanda",
"Carolina",
"Amanda",
"Maria Vitoria",
"Maria Helena",
"Eduarda",
"Malu",
"Maria Sophia",
"Stella",
"Camila",
"Maya",
"Gabrielly",
"Mirella",
"Mariah",
"Ana Livia",
"Maria Flor",
"Ayla",
"Isabel",
"Sophie",
"Giulia",
"Luana",
"Bruna",
"Ana Vitoria",
"Joana",
"Maria Laura",
"Maria Isis",
"Louise",
"Perola",
"Natalia",
"Ana Cecilia",
"Aurora",
"Barbara"
};

	//Fonte dos nomes: http://www.tiltedlogic.org/Familia/surnames.php
	char *sobre[] = {"Altoe",
"Sossai",
"Agrizzi",
"De Angeli",
"Ferreira",
"da Silva",
"Della Coletta",
"Zampirolli",
"Fernandes",
"Braga",
"Alves",
"Costalonga",
"Botteon",
"Caliman",
"de Oliveira",
"Zanette",
"Salvador",
"Silva",
"Pesca",
"Zandonadi",
"Tosi",
"da Costa",
"Gomes",
"Calmon",
"de Souza",
"Sossai detto Pegorer",
"de Almeida",
"Pereira",
"Falqueto",
"Martins"};
	
	srand( time(NULL) );                 //iniciliar o gerador rand?mico com a hora atual
	
	for( i= 0; i < N_MAX; i++ ){         // la?o para gera??o aleat?ria dos nomes e notas
		 x = aleatorio( 199 );
	 	 strcpy( nomeTemp, nomes[ x ] ); // nome aleat?rio
		 strcat( nomeTemp, " ");         // espa?o entre nome e sobrenome 
		 x = aleatorio( 29 );
		 strcat( nomeTemp, sobre[ x ] ); // concatena no nome o sobrenome aleat?rio

		 strcpy( lista->info[ i ].nome, nomeTemp ); // registra nome completo na lista
		 //lista->info[ i ].codigo = i + 1;// gerar matr?cula autom?tica sequencial 	
		 lista->info[ i ].codigo = aleatorio( 199 ) + 1;// gerar matr?cula autom?tica sequencial
	}
	lista->f = i;                        // atualiza controle de n?mero de registros da lista
	printf( "\n Gerados %d registros ", lista->f );
}


int f ( NODO l ){
   int i=0, j, c=0;
   while( i < l.f-1 ){
          j= i + 1;
          while( j < l.f ){
                 if( l.info[ i ].codigo == l.info[ j ].codigo )
                     c++;
                 j++; 
          }
          i++;
   }
   return( c );
}
