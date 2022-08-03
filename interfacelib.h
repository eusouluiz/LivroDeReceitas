#ifndef INTERFACELIB_H_INCLUDED
#define INTERFACELIB_H_INCLUDED

#include "recipelib.h"

/*
	Insere à tela a moldura de livro centralizada.
*/
void LIVROdisplay();

/*
	Insere à tela o título da capa no livro.
*/
void CAPAdisplay();

/*
	Insere à tela menu de comandos.
		short int menu =	(1) Menu de livro fechado.
							(2) Menu de livro aberto.
							(3) Menu de alteração de receita.
*/
void MENUdisplay(short int menu);

/*
	Menu para seleção de dado a ser alterado na receita.
	Retorna um valor int para:	(1) Título.
								(2)	Ingredientes.
								(3)	Nota.
								(4)	Autor.
								(5)	Tempo de preparo.
								(6)	Modo de preparo.
								(7)	Usos.
*/
int MENUalteracoes();

/*
	Insere à tela o menu com informações para
	recebimento dos elementos da receita.
	Seleção:	(1) Título.
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
	Adiciona nota e realiza a média considerando
	o número de vezes que a receita foi preparada
	e a media anterior.
*/
void ADDnota(receita* receita);

/*
	Funções responsáveis pela inserção à tela
	dos elementos de receita ou informações
	complementares à estes.
	Seleção:	(m)	Informações de menu.
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
	Realiza a inserção à tela de todas as
	informações do elemento receita,
	recebido como parâmetro.
*/
void PRINTlista(receita* receita);

/*
	Print com definição de cordenadas para
	strings hardcode.
*/
void print(int x, int y, char* s);

/*
	Print com definição de cordenadas para
	strings armazenadas em variáveis.
*/
void printS(int x, int y, char* s);

/*
	Print com definição de cordenadas e
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
