#ifndef INTERFACELIB_H_INCLUDED
#define INTERFACELIB_H_INCLUDED

#include "recipelib.h"

/*
	Insere � tela a moldura de livro centralizada.
*/
void LIVROdisplay();

/*
	Insere � tela o t�tulo da capa no livro.
*/
void CAPAdisplay();

/*
	Insere � tela menu de comandos.
		short int menu =	(1) Menu de livro fechado.
							(2) Menu de livro aberto.
							(3) Menu de altera��o de receita.
*/
void MENUdisplay(short int menu);

/*
	Menu para sele��o de dado a ser alterado na receita.
	Retorna um valor int para:	(1) T�tulo.
								(2)	Ingredientes.
								(3)	Nota.
								(4)	Autor.
								(5)	Tempo de preparo.
								(6)	Modo de preparo.
								(7)	Usos.
*/
int MENUalteracoes();

/*
	Insere � tela o menu com informa��es para
	recebimento dos elementos da receita.
	Sele��o:	(1) T�tulo.
				(2)	Ingredientes.
				(3)	Nota.
				(4)	Autor.
				(5)	Tempo de preparo.
				(6)	Modo de preparo.
				(7)	Usos.
				(a) Todos.
*/
receita* getINFOS(receita* aux, char selecao);

/*
	Adiciona nota e realiza a m�dia considerando
	o n�mero de vezes que a receita foi preparada
	e a media anterior.
*/
void ADDnota(receita* receita);

/*
	Fun��es respons�veis pela inser��o � tela
	dos elementos de receita ou informa��es
	complementares � estes.
	Sele��o:	(m)	Informa��es de menu.
				(i)	Elemento da receita.
				(b)	Ambos.
*/
void PRINTtitulo(char* titulo, char selecao);
void PRINTingredientes(receita* receita, char selecao);
void PRINTtempo(receita* receita, char selecao);
void PRINTpreparo(receita* receita, char selecao);
void PRINTautor(char* autor, char selecao);
void PRINTnota(float* nota, char selecao);
void PRINTuso(int uso, char selecao);

/*
	Realiza a inser��o � tela de todas as
	informa��es do elemento receita,
	recebido como par�metro.
*/
void PRINTlista(receita* receita);

/*
	Print com defini��o de cordenadas para
	strings hardcode.
*/
void print(int x, int y, char* s);

/*
	Print com defini��o de cordenadas para
	strings armazenadas em vari�veis.
*/
void printS(int x, int y, char* s);

/*
	Print com defini��o de cordenadas e
	incremento de valor y.
*/
void printMENU(int x, int* y, char* s);

/*
	Realiza o posicionamento do cursor
	em um ponto da tela definido pelas
	coordenadas x e y.
*/
void SETcursor(int x, int y);

#endif // INTERFACELIB_H_INCLUDED
