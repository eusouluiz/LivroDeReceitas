#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#include "recipelib.h"

struct RECEITA	{
	char titulo[TAMtitulo];
	char tempo[LINtempo][TAMtempo];
	char ingredientes[TAMingrediente][TAMingrediente];
	char preparo[TAMpreparo][TAMpreparo];
	char autor[TAMautor];
	float nota;
	int uso;

	receita *ant;
	receita *prox;
};

struct LISTA	{
	receita *inicio;
	receita *atual;
	receita *fim;
	int Nreceitas;
};

dadosLISTA* INICIARlista()	{
	dadosLISTA* aux = (dadosLISTA*) malloc(sizeof(dadosLISTA));
	aux->atual = NULL;
	aux->inicio = NULL;
	aux->fim = NULL;
	aux->Nreceitas = 0;
	return aux;
}

void INCREMENTAR_Nreceitas(dadosLISTA* lista){
	lista->Nreceitas++;
	return;
}

void DECREMENTAR_Nreceitas(dadosLISTA* lista){
	lista->Nreceitas--;
	return;
}

void INCREMENTARlista(dadosLISTA* lista){
	lista->atual = lista->atual->prox;
	return;
}

void DECREMENTARlista(dadosLISTA* lista){
	lista->atual = lista->atual->ant;
	return;
}

receita* INICIOlista(dadosLISTA* lista){
	return lista->inicio;
}

receita* ANTlista(dadosLISTA* lista){
	return lista->atual->ant;
}

receita* ATUALlista(dadosLISTA* lista){
	return lista->atual;
}

receita* PROXlista(dadosLISTA* lista){
	return lista->atual->prox;
}

receita* FIMlista(dadosLISTA* lista){
	return lista->fim;
}

void setATUALtoINICIO(dadosLISTA* lista){
	lista->atual = lista->inicio;
	return;
}

void INCREMENTARuso(dadosLISTA* lista){
	lista->atual->uso++;
	return;
}

char* TITULO(receita* receita){
	if(receita != NULL){
		char* aux = (char*)malloc(sizeof(char) * TAMtitulo);
		strcpy(aux, receita->titulo);
		return aux;
	} else {
		return NULL;
	}
}

void INGREDIENTES(receita* receita, char aux[][TAMingrediente]){
	if(receita != NULL){
		for (int i = 0; i < LINingrediente; i++){
			strcpy(aux[i], receita->ingredientes[i]);
		}
	}
	return;
}


void TEMPO(receita* receita, char aux[][TAMtempo]){
	if(receita != NULL){
		for (int i = 0; i < LINtempo; i++){
			strcpy(aux[i], receita->tempo[i]);
		}
	}
	return;
}

void PREPARO(receita* receita, char aux[][TAMpreparo]){
	if(receita != NULL){
		for (int i = 0; i < LINpreparo; i++){
			strcpy(aux[i], receita->preparo[i]);
		}
	}
	return;
}

char* AUTOR(receita* receita){
	if(receita != NULL){
		char* aux = (char*)malloc(sizeof(char) * TAMautor);
		strcpy(aux, receita->autor);
		return aux;
	} else {
		return NULL;
	}
}

float* NOTA(receita* receita){
	if(receita != NULL){
		return &receita->nota;
	} else {
		return NULL;
	}
}

int USO(receita* receita){
	if(receita != NULL){
		return receita->uso;
	} else {
		return 0;
	}
}

int NRECEITAS(dadosLISTA* lista){
	return lista->Nreceitas;
}

receita* ALOCARlista(){
	receita* aux = (receita*)malloc(sizeof(receita));

	aux->nota = 0.00;
	aux->uso = 0;

	aux->ant = aux;
	aux->prox = aux;

	return aux;
}

void INSERIRlista(dadosLISTA* lista, receita* NEW){
	short int loop = false;

	if (lista->inicio == NULL){
		lista->inicio = NEW;
		lista->atual = NEW;
		lista->fim = NEW;
	} else

	if(lista->atual == NEW){
		if (lista->atual == lista->inicio && lista->atual == lista->fim){
			return;
		}
		if (lista->atual == lista->inicio){
			lista->inicio = lista->atual->prox;
		} else if (lista->atual == lista->fim){
			lista->fim = lista->atual->ant;
		}
		lista->atual->prox->ant = lista->atual->ant;
		lista->atual->ant->prox = lista->atual->prox;
	}

	lista->atual = lista->inicio;
	while ( strcmp(NEW->titulo, lista->atual->titulo) >= 0 && !loop){
		lista->atual = lista->atual->prox;
		if (lista->atual == lista->inicio){
			loop = true;
		}
	}
	if (lista->atual->ant == lista->fim && loop == true){
		lista->fim = NEW;
	} else if (lista->atual == lista->inicio){
		lista->inicio = NEW;
	}
	NEW->prox = lista->atual;
	NEW->ant = lista->atual->ant;
	lista->atual->ant = NEW;
	NEW->ant->prox = NEW;

	lista->atual = lista->atual->ant;
	return;
}

void INSERIRtitulo (receita* receita){
	fgets(receita->titulo, TAMtitulo, stdin);

	for (int i = 0; i < TAMtitulo; i++) receita->titulo[i] = (char) toupper(receita->titulo[i]);

	fflush(stdin);
	return;
}

void INSERIRtempo (receita* receita){
	for (int i = 0; i < LINtempo; i++){
		char aux[TAMtempo];

		if (i == 0) fgets(aux, 23, stdin);
		else fgets(aux, TAMtempo, stdin);

		strcpy(receita->tempo[i], aux);

		if ( strcmp(aux, "\n") == 0 ) return;
		if(strlen(receita->tempo[i]) < 22) {
			strcpy(receita->tempo[i+1], "   ");
			break;
		}
	}
	fflush(stdin);
	return;
}

void INSERIRingred (receita* receita){
	for (int i = 0; i < LINingrediente; i++){
		char aux[TAMingrediente];
		fgets(aux, TAMingrediente, stdin);
		if ( strcmp(aux, "\n") == 0 ){
			strcpy(receita->ingredientes[i], aux);
			return;
		} else {
			strcpy(receita->ingredientes[i], aux);
		}
		SETcursor( ((TAMtela - TAMmenu) / 2) + 7,  8+i);
	}
	fflush(stdin);
	return;
}

void INSERIRpreparo (receita* receita){
	for (int i = 0; i < LINpreparo; i++){
		char aux[TAMpreparo];
		fgets(aux, TAMpreparo, stdin);
		if ( strcmp(aux, "\n") == 0 ){
			strcpy(receita->preparo[i], aux);
			return;
		} else {
			strcpy(receita->preparo[i], aux);
		}
		SETcursor ( (TAMtela / 2) + 4, 7+i);
	}
	fflush(stdin);
	return;
}

void INSERIRautor (receita* receita){
	fgets(receita->autor, TAMautor, stdin);
	fflush(stdin);
	return;
}

void INSERIRnota (receita* receita){
	scanf("%f", &receita->nota);
	fflush(stdin);
	return;
}

void INSERIRuso (receita* receita){
	scanf("%d", &receita->uso);
	fflush(stdin);
	return;
}

void EXCLUIRlista(dadosLISTA* lista){
	if (lista->atual == lista->inicio && lista->atual == lista->fim){
		free(lista->atual);
		lista->inicio = NULL;
		lista->atual = NULL;
		lista->fim = NULL;
		return;
	}
	if (lista->atual == lista->inicio){
		lista->inicio = lista->atual->prox;
	} else if (lista->atual == lista->fim){
		lista->fim = lista->atual->ant;
	}
	lista->atual->prox->ant = lista->atual->ant;
	lista->atual->ant->prox = lista->atual->prox;
	free(lista->atual);
	lista->atual = lista->inicio;
}

void LOADarquivos(dadosLISTA* lista){
	FILE * arq = fopen ("RECIPEdata.bin" , "rb");
	lista->Nreceitas = 0;
	if (arq == NULL){
		arq = fopen ("RECIPEdata.bin" , "wb");
	} else {
		fread(&lista->Nreceitas, sizeof(int), 1, arq);
		if (lista->Nreceitas == 0){
			fclose(arq);
			return;
		} else {
			for (int i = 0; i < lista->Nreceitas; i++){
				receita* aux = (receita*)malloc(sizeof(receita));
				lista->atual = aux;

				fread(lista->atual, sizeof(receita), 1, arq);

				if (i == 0){
					aux->prox = aux;
					aux->ant = aux;
					lista->inicio = aux;
					lista->atual = aux;
					lista->fim = aux;
				} else {
					aux->prox = lista->inicio;
					aux->ant = lista->fim;

					lista->inicio->ant = aux;

					lista->fim->prox = aux;

					lista->fim = aux;
				}
			}
		}
	}
	fclose(arq);
	return;
}

void SAVEarquivos(dadosLISTA* lista){
	FILE * arq = fopen ("RECIPEdata.bin" , "wb");
	fwrite(&lista->Nreceitas, sizeof(int), 1, arq);
	lista->atual = lista->inicio;
	for (int i = 0; i < lista->Nreceitas; i++){

		fwrite(lista->atual, sizeof(receita), 1, arq);

		if (i == lista->Nreceitas-1){
			free(lista->atual);
		} else {
			lista->atual = lista->atual->prox;
			free(lista->atual->ant);
		}

	}
	fclose(arq);
	return;

}
