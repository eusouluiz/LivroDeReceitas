#ifndef RECIPELIB_H_INCLUDED
#define RECIPELIB_H_INCLUDED

#define TAMtitulo 39
#define TAMtempo 40
#define LINtempo 2
#define TAMingrediente 41
#define LINingrediente 16
#define TAMpreparo 41
#define LINpreparo 16
#define TAMautor 30
#define TAM 100

#define TAMtela 169
#define TAMmenu 101
#define TAMpagina 46

#define true 1
#define false 0

int getch();

typedef struct RECEITA receita;
typedef struct LISTA dadosLISTA;

/*
	Inicia a lista de tipo dadosLISTA definindo seus
	elementos para NULL e a quantidade de receitas
	para 0, retorna um ponteiro dadosLISTA*.
*/
dadosLISTA* INICIARlista();

/*
	Realizam o incremento ou decremento do número
	de receitas registradas contido no elemento
	de tipo dadosLISTA.
*/
void INCREMENTAR_Nreceitas(dadosLISTA* lista);
void DECREMENTAR_Nreceitas(dadosLISTA* lista);

/*
	Realizam a passagem para o elemento anterior
	ou seguinte do elemento atual da estrutura
	de controle dadosLISTA.
*/
void INCREMENTARlista(dadosLISTA* lista);
void DECREMENTARlista(dadosLISTA* lista);

/*
	Funções responsáveis por retornar ponteiros
	para elementos do tipo receita referenciados
	pela estrutura de controle dadosLISTA.
*/
receita* INICIOlista(dadosLISTA* lista);
receita* ANTlista(dadosLISTA* lista);
receita* ATUALlista(dadosLISTA* lista);
receita* PROXlista(dadosLISTA* lista);
receita* FIMlista(dadosLISTA* lista);

/*
	Define o ponteiro atual da estrutura de
	controle para o primeiro elemento da lista.
*/
void setATUALtoINICIO(dadosLISTA* lista);

/*
	Realiza o incremento do valor do elemento
	"uso" contido na receita referenciada pelo
	elemento atual em dadosLISTA* lista.
*/
void INCREMENTARuso(dadosLISTA* lista);


/*
	Funções responsáveis por retornar os elementos
	contidos dentro do TAD.
*/
char* TITULO(receita* receita);
void INGREDIENTES(receita* receita, char aux[][TAMingrediente]);
void TEMPO(receita* receita, char aux[][TAMtempo]);
void PREPARO(receita* receita, char aux[][TAMpreparo]);
char* AUTOR(receita* receita);
float* NOTA(receita* receita);
int USO(receita* receita);
int NRECEITAS(dadosLISTA* lista);

/*
	Realiza a alocação de memória para um
	elemento receita e retorna um ponteiro
	para o elemento alocado.
*/
receita* ALOCARlista();

/*
	Realiza a inserção ordenada alfabéticamente, com
	referência no elemento título, de um novo elemento
	receita à uma lista, ambos recebidos como parâmetro.
	Um elemento pode também ser reinserido à lista
	utilizando esta função.
*/
void INSERIRlista(dadosLISTA* lista, receita* NEW);


/*
	Funções responsáveis por receber informações
	inseridas pelo usuário no terminal e armazená-las
	na estrutura receita, recebida como parâmetro.
*/
void INSERIRtitulo (receita* receita);
void INSERIRtempo (receita* receita);
void INSERIRingred (receita* receita);
void INSERIRpreparo (receita* receita);
void INSERIRautor (receita* receita);
void INSERIRnota (receita* receita);
void INSERIRuso (receita* receita);

/*
	Realiza a exclusão da receita apontada
	pelo elemento "atual" na estutura de controle
	dadosLISTA, recebida como parâmetro.
*/
void EXCLUIRlista(dadosLISTA* lista);

/*
	Gravação e leitura binária dos dados em
	arquivo "RECIPEdata.bin.
*/
void LOADarquivos(dadosLISTA* lista);
void SAVEarquivos(dadosLISTA* lista);

/*
	Realiza o posicionamento do cursor
	em um ponto da tela definido pelas
	coordenadas x e y.
*/
void SETcursor(int x, int y);


#endif // RECIPELIB_H_INCLUDED
