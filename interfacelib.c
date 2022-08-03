#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#include "interfacelib.h"
#include "recipelib.h"

void LIVROdisplay(){
	int y = 0;
	int x = ((TAMtela / 2) - ( TAMmenu / 2 ));
	system("cls");
	printf("\n");
	printMENU(x, &y, "    _____________________________________________   _____________________________________________    \n");
	printMENU(x, &y, ".-||                                             | |                                             ||-.\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||                                              |                                              ||||\n");
	printMENU(x, &y, "||||_____________________________________________ | _____________________________________________||||\n");
	printMENU(x, &y, "|||==============================================| |==============================================|||\n");
	printMENU(x, &y, "''----------------------------------------------~___~----------------------------------------------''\n");
	printf("\n");
	SETcursor(168, 42);
}

void CAPAdisplay(){
	print(22 + ((TAMtela - TAMmenu) / 2), 6, "--=*==*=--");
	print(18 + ((TAMtela - TAMmenu) / 2), 8, "LIVRO DE RECEITAS!");
	print(23 + ((TAMtela - TAMmenu) / 2), 9, "OwO  OwO");
	print(22 + ((TAMtela - TAMmenu) / 2), 11, "--=*==*=--");
	SETcursor(168, 42);
	return;
}

void MENUdisplay(short int menu){
	int y;
	char s[50];
	switch (menu){
		case 1:
			y = 32;
			strcpy (s, "-~- MENU -~-");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			y++;
			strcpy (s, "A - Abrir livro.");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			strcpy (s, "F - Fechar programa.");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);

			SETcursor(168, 42);
			break;

		case 2:
			y = 32;
			strcpy (s, "-~- MENU -~-");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			y++;
			strcpy (s, "<- Navegação ->");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			strcpy (s, "A - Inserir receita.");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			strcpy (s, "X - Excluir receita.");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			strcpy (s, "C - Alterar receita.");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			strcpy (s, "Enter - Marcar utilização.");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			strcpy (s, "F - Fechar livro.");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);

			SETcursor(168, 42);
			break;

		case 3:
			y = 32;
			strcpy (s, "-~- ALTERAÇÃO DE RECEITA -~-");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			strcpy (s, "Selecione o que deseja alterar. ");
			printMENU(( (TAMtela / 2) - (strlen(s)/2) ), &y, s);
			y++;
			printMENU(( (TAMtela / 2) - 37/2 ), &y, "Título.             Tempo de preparo.");
			printMENU(( (TAMtela / 2) - 37/2 ), &y, "Ingredientes.       Modo de preparo. ");
			printMENU(( (TAMtela / 2) - 37/2 ), &y, "Nota.               Vezes preparada. ");
			printMENU(( (TAMtela / 2) - 37/2 ), &y, "Autor.              Sair.            ");

			SETcursor(168, 42);
			break;
	}
	fflush(stdin);
	return;
}

int MENUalteracoes(){
	int x = 1, y = 0;
	print(64, 35+y, "->");
	SETcursor(168, 42);

	while (true == true){
		for (int i = 0; i <= 3; i++){
			print(64, 35+i, "  ");
			print(84, 35+i, "  ");
		}
		if(x == 1){
			print(64, 35+y, "->");
		}
		if(x == 5){
			print(84, 35+y, "->");
		}
		SETcursor(168, 42);
		switch(getch()){
			case 224:
				switch ( getch() ){	//Getch setas.

					case 72:	//CIMA
						if(y > 0) y--;
						break;

					case 80:	//BAIXO
						if(y < 3) y++;
						break;

					case 77:	//DIREITA
						if(x < 5) x = 5;
						break;

					case 75:	//ESQUERDA
						if(x > 1) x = 1;
						break;
				}
				break;

			case 13:
				return x+y;
				break;
		}
	}
}

receita* getINFOS(receita* aux, char selecao){

	if (selecao == '1' || selecao == 'a'){
		LIVROdisplay();
		PRINTtitulo(TITULO(aux), 'm');
		INSERIRtitulo(aux);
	}
	if (selecao == '2' || selecao == 'a'){
		LIVROdisplay();
		PRINTtitulo(TITULO(aux), 'i');
		PRINTingredientes(aux, 'm');
		INSERIRingred(aux);
	}
	if (selecao == '5' || selecao == 'a'){
		LIVROdisplay();
		PRINTtitulo(TITULO(aux), 'i');
		PRINTingredientes(aux, 'b');
		PRINTtempo(aux, 'm');
		INSERIRtempo(aux);
	}
	if (selecao == '6' || selecao == 'a'){
		LIVROdisplay();
		PRINTtitulo(TITULO(aux), 'i');
		PRINTingredientes(aux, 'b');
		PRINTtempo(aux, 'b');
		PRINTpreparo(aux, 'm');
		INSERIRpreparo(aux);
	}
	if (selecao == '4' || selecao == 'a'){
		LIVROdisplay();
		PRINTtitulo(TITULO(aux), 'i');
		PRINTingredientes(aux, 'b');
		PRINTtempo(aux, 'b');
		PRINTpreparo(aux, 'b');
		PRINTautor(AUTOR(aux), 'm');
		INSERIRautor(aux);
	}
	if (selecao == '3'){
		do{
			LIVROdisplay();
			PRINTtitulo(TITULO(aux), 'i');
			PRINTingredientes(aux, 'b');
			PRINTtempo(aux, 'b');
			PRINTpreparo(aux, 'b');
			PRINTautor(AUTOR(aux), 'b');
			PRINTnota(NOTA(aux), 'm');
			INSERIRnota(aux);
		} while (*NOTA(aux) > 10 || *NOTA(aux) < 0);
	}
	if (selecao == '7'){
		LIVROdisplay();
		PRINTtitulo(TITULO(aux), 'i');
		PRINTingredientes(aux, 'b');
		PRINTtempo(aux, 'b');
		PRINTpreparo(aux, 'b');
		PRINTautor(AUTOR(aux), 'b');
		PRINTnota(NOTA(aux), 'b');
		PRINTuso(USO(aux), 'm');
		INSERIRuso(aux);
	}
	return aux;
}

void ADDnota(receita* receita){

	float nota = *(NOTA(receita));
	float* notareceita = NOTA(receita);
	getINFOS(receita, '3');

	*notareceita = ((nota * USO(receita)) + (*(NOTA(receita))) ) / (USO(receita) + 1);
	return;

}


void PRINTtitulo(char* titulo, char selecao){

	int espacos;
	if (selecao == 'i' || selecao == 'b'){
		espacos = ((TAMtela - TAMmenu) / 2) + (TAMpagina * 0.5 + 4) - ( strlen(titulo) / 2 );
		print(espacos, 3, titulo);
	}
	if (selecao == 'm' || selecao == 'b'){
		espacos = ((TAMtela - TAMmenu) / 2) + (TAMpagina * 0.5 + 4) - ( strlen("(título)") / 2 );
		print(espacos, 4, "(título)");
		SETcursor(((TAMtela - TAMmenu) / 2) + 8, 3);
	}

	return;
}

void PRINTingredientes(receita* receita, char selecao){

	int espacos;
	if	(selecao == 'm' || selecao == 'b'){
		espacos = ((TAMtela - TAMmenu) / 2) + (TAMpagina * 0.5 + 4) - ( strlen("Ingredientes: ") / 2 );
		print(espacos, 5, "Ingredientes:");
		espacos = ((TAMtela - TAMmenu) / 2) + 7;
		SETcursor(espacos, 7);
	}
	if	(selecao == 'i' || selecao == 'b'){
		espacos = ((TAMtela - TAMmenu) / 2) + 7;
		char aux[LINingrediente][TAMingrediente];
		INGREDIENTES(receita, aux);

		for (int i = 0; i < LINingrediente; i++){
			if (strcmp(aux[i], "\n") == 0){
				break;
			}
			printS(espacos, 7+i, aux[i]);
		}

	}

	return;
}

void PRINTtempo(receita* receita, char selecao){

	int espacos;
	if (selecao == 'm' || selecao == 'b'){
		espacos = ((TAMtela - TAMmenu) / 2) + 7;
		SETcursor(espacos, 24);
		fputs("Tempo de preparo: ", stdout);
	}
	if (selecao == 'i' || selecao == 'b'){
		espacos = ((TAMtela - TAMmenu) / 2) + 25;
		char aux[LINtempo][TAMtempo];
		TEMPO(receita, aux);


		for (int i = 0; i < LINtempo; i++){
			if (strcmp(aux[i], "\n") == 0){
				break;
			}
			printS(espacos, 24+i, aux[i]);
			espacos = ((TAMtela - TAMmenu) / 2) + 7;
		}
	}

	return;
}

void PRINTpreparo(receita* receita, char selecao){

	int espacos;
	if (selecao == 'm' || selecao == 'b'){
		espacos = (TAMtela / 2) + (TAMpagina / 2) - ( strlen("Modo de preparo:") / 2 );
		print(espacos, 4, "Modo de preparo:");
		espacos = (TAMtela / 2) + 4;
		SETcursor(espacos, 6);
	}
	if (selecao == 'i' || selecao == 'b'){
		espacos = (TAMtela / 2) + 4;
		char aux[LINpreparo][TAMpreparo];
		PREPARO(receita, aux);

		SETcursor(espacos, 6);
		for (int i = 0; i < LINpreparo; i++){
			if (strcmp(aux[i], "\n") == 0){
				break;
			}
			printS(espacos, 6+i, aux[i]);
		}
	}

	return;
}

void PRINTautor(char* autor, char selecao){

	int espacos;
	if (selecao == 'm' || selecao == 'b'){
		espacos = (TAMtela / 2) + 4;
		SETcursor(espacos, 23);
		fputs("Autor: ", stdout);
	}
	if (selecao == 'i' || selecao == 'b'){
		espacos = (TAMtela / 2) + 11;
		printS(espacos, 23, autor);
	}

	return;
}

void PRINTnota(float* nota, char selecao){

	int espacos;
	if (selecao == 'm' || selecao == 'b'){
		espacos = (TAMtela / 2) + 4;
		SETcursor(espacos, 25);
		fputs("Nota: ", stdout);
	}
	if (selecao == 'i' || selecao == 'b'){
		espacos = (TAMtela / 2) + 10;
		SETcursor(espacos, 25);
		printf("%02.2f", *nota);
	}

	return;
}

void PRINTuso(int uso, char selecao){

	int espacos;
	if (selecao == 'm' || selecao == 'b'){
		espacos = (TAMtela / 2) + 4 + (TAMpagina / 3);
		SETcursor(espacos, 25);
		fputs("Vezes preparada: ", stdout);
	}
	if (selecao == 'i' || selecao == 'b'){
		espacos = (TAMtela / 2) + 21 + (TAMpagina / 3);
		SETcursor(espacos, 25);
		printf("%02d", uso);
	}

	return;
}

void PRINTlista(receita* receita){
	int espacos;
	if (receita != NULL){

		PRINTtitulo(TITULO(receita), 'i');
		PRINTingredientes(receita, 'b');
		PRINTtempo(receita, 'b');
		PRINTpreparo(receita, 'b');
		PRINTautor(AUTOR(receita), 'b');
		PRINTnota(NOTA(receita), 'b');
		PRINTuso(USO(receita), 'b');

	} else {
		espacos = (TAMtela / 2) + (TAMpagina / 2) - ( strlen("Nenhuma receita cadastrada.") / 2 );
		print(espacos, 6,"Nenhuma receita cadastrada.");
		SETcursor(0, 0);
	}

	SETcursor(168, 42);
}


void print(int x, int y, char* s){
	SETcursor(x, y);
	fputs(s, stdout);
}

void printS(int x, int y, char* s){
	SetConsoleCP(1252);
	SETcursor(x, y);
	fputs(s, stdout);
	SetConsoleCP(850);
}

void printMENU(int x, int* y, char* s){
	print(x, *y, s);
	(*y)++;
}

void SETcursor(int x, int y){
    HANDLE handle;
    COORD cordenadas;
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    cordenadas.X = x;
    cordenadas.Y = y;
    SetConsoleCursorPosition ( handle , cordenadas );
}
