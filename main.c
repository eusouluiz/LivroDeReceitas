#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "recipelib.h"
#include "interfacelib.h"

int main()
{
	setlocale(LC_ALL, "Portuguese");
	system("MODE con cols=169 lines=43");
	system("title Livro de Receitas!");

	dadosLISTA* lista;

	lista = INICIARlista();

	LOADarquivos(lista);
	LIVROdisplay();
	CAPAdisplay();
	MENUdisplay(1);


	while (true == true){
		short int loop = true;

		switch ( getch() ){

			case 'A':	//ABERTURA DO LIVRO
			case 'a':
				LIVROdisplay();
				setATUALtoINICIO(lista);
				PRINTlista(ATUALlista(lista));
				MENUdisplay(2);

				while (loop == true){
					MENUdisplay(2);

					switch ( getch() ){

						case 224:

							switch ( getch() ){	//Getch setas (Navegação).

								case 77:	//DIREITA
									if (ATUALlista(lista) != NULL && ATUALlista(lista) != PROXlista(lista)){
										INCREMENTARlista(lista);
										LIVROdisplay();
										PRINTlista(ATUALlista(lista));
									}
									break;

								case 75:	//ESQUERDA
									if (ATUALlista(lista) != NULL && ATUALlista(lista) != ANTlista(lista)){
										DECREMENTARlista(lista);
										LIVROdisplay();
										PRINTlista(ATUALlista(lista));
									}
									break;
							}
							break;

						case 'A':	//Inserção de receita
						case 'a':
							fflush(stdin);
							INSERIRlista(lista, getINFOS(ALOCARlista(), 'a'));
							INCREMENTAR_Nreceitas(lista);
							LIVROdisplay();
							PRINTlista(ATUALlista(lista));
							break;

						case 'X':	//Exclusão de receita
						case 'x':
							if (ATUALlista(lista) != NULL){
								EXCLUIRlista(lista);
								DECREMENTAR_Nreceitas(lista);
								LIVROdisplay();
								PRINTlista(ATUALlista(lista));
							}
							break;

						case 13:	//ENTER - Incremento de usos da receita
							if (ATUALlista(lista) != NULL){
								ADDnota(ATUALlista(lista));
								INCREMENTARuso(lista);
								LIVROdisplay();
								PRINTlista(ATUALlista(lista));
							}
							break;

						case 'C':	//Alteração de receita
						case 'c':
							if (ATUALlista(lista) != NULL){
								LIVROdisplay();
								PRINTlista(ATUALlista(lista));
								MENUdisplay(3);
								SETcursor(0, 0);

								switch (MENUalteracoes()){
									case 1:
										INSERIRlista(lista, getINFOS(ATUALlista(lista), '1'));
										break;
									case 2:
										getINFOS(ATUALlista(lista), '2');
										break;

									case 3:
										getINFOS(ATUALlista(lista), '3');
										break;

									case 4:
										getINFOS(ATUALlista(lista), '4');
										break;
									case 5:

										getINFOS(ATUALlista(lista), '5');
										break;
									case 6:
										getINFOS(ATUALlista(lista), '6');
										break;

									case 7:
										getINFOS(ATUALlista(lista), '7');
										break;
									case 8:
										break;
								}
								LIVROdisplay();
								PRINTlista(ATUALlista(lista));
								MENUdisplay(2);
							}
							break;

						case 'F':	//Fechamento do livro
						case 'f':
							LIVROdisplay();
							CAPAdisplay();
							MENUdisplay(1);
							loop = false;
							break;

						default:
							break;
					}
				}
				break;

			case 'F':	//Encerramento do programa
			case 'f':
				SAVEarquivos(lista);
				SETcursor(0, 38);
				return 0;

			default:
				break;
		}

	}
	return 1;
}
