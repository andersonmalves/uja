#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
/*
    Trabalho apresentado a linguagem e t�cnica de programa��o para composi��o da nota AVA2
    Orientadores: Vitor da Mata Quintella e Barbara Alves de Jesus Amorim dos Santos
    Aluno: Anderson Moreira Alves - 183001621
*/

const char* arraySignos[] = {"CAPRIC�RNIO - 22/12 a 19/01", "AQU�RIO - 20/01 a 18/02", "PEIXES - 19/02 a 20/03", "�RIES - 21/03 a 19/04", "TOURO - 20/04 a 20/05", "G�MEOS - 21/05 a 21/06", "C�NCER - 22/06 a 22/07", "LE�O - 23/07 a 22/08", "VIRGEM - 23/08 a 22/09", "LIBRA - 23/09 a 22/10", "ESCORPI�O - 23/10 a 21/11", "SAGIT�RIO - 22/11 a 21/12", "CAPRIC�RNIO - 22/12 a 19/01"};

int menuPrincipal();
int limparTela();
int criaArquivo();
int informaSigno();
int fraseMotivacional();
int pegaFrase(char idFrase[]);

int main(){
    setlocale(LC_ALL, "Portuguese");
    #if defined _WIN32
        system("TITLE SIGNOS ZODIACAIS");
        system("COLOR 0A");
	#endif
    menuPrincipal();
}
//--------------------------------------------------------------
int limparTela(){
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}
//--------------------------------------------------------------
int menuPrincipal(){
	int opcMenuPrincipal;

	while (opcMenuPrincipal > 3) {
        limparTela();
        printf("\n	----------- SIGNOS DO ZOD�ACO -----------\n\n\n");
        printf("	0 - Cria arquivo com frases motivacionais\n");
        printf("	1 - Saber qual � o signo\n");
        printf("	2 - Frase motivacional do signo\n");
        printf("	3 - Sair\n\n\n");
        printf("            *** Entre com uma das op��es acima: ");
        fflush(stdin);
        scanf("%d", &opcMenuPrincipal);

	    switch (opcMenuPrincipal) {
			case 0:
				criaArquivo();
				break;
			case 1:
				informaSigno();
				break;
			case 2:
				fraseMotivacional();
				break;
			case 3:
				limparTela();
				printf("\n===> Obrigado por usar o programa SIGNOS ZODIACAIS\n");
				exit(0);
		}
	}
}
//--------------------------------------------------------------
int criaArquivo(){
	char frase[101];
	int idFrase = 11, tamanho;

	FILE *arquivotxt;
	arquivotxt = fopen("horoscopo.txt", "w");
	for(int i = 0; i <= 11; i++){
		tamanhoExcedido:
		limparTela();
		printf("\n                           *** CRIA ARQUIVO COM FRASES MOTIVACIONAIS ***\n\n\n");
		printf("Entre com a frase motivacional para o signo de %s", arraySignos[i]);
		printf("\n\n[-----------------------------------Tamanho m�ximo de 100 posi��es-----------------------------------]	\n");
		fflush(stdin);
        fgets(frase, 101, stdin);
		tamanho = strlen(frase);
		if(tamanho >= 100) {
            printf("\nATEN��O: a frase deve ter no m�ximo 100 caracteres!");
			getch();
			goto tamanhoExcedido;
		}
		fprintf(arquivotxt, "%d%s", idFrase++, frase);
	}
	fclose(arquivotxt);
	getch();
	menuPrincipal();
}
//--------------------------------------------------------------
int informaSigno(){
	int diaNascimentoInt, mesNascimentoInt, arrayDias[13] = {0,21,20,21,21,21,21,22,23,23,23,22,22};

	dataInvalida:
	limparTela();
	printf("\n			*** INFORMA O SIGNO ***\n\n\n");
	printf("Informe o dia e o m�s que voc� nasceu (DD/MM): ");
	fflush(stdout);
	scanf("%d/%d", &diaNascimentoInt, &mesNascimentoInt);

	if (diaNascimentoInt > 31 ||  mesNascimentoInt > 12) {
        printf("\nATEN��O: data inv�lida.");
        getch();
		goto dataInvalida;
	}

    if (diaNascimentoInt < arrayDias[mesNascimentoInt]){
		mesNascimentoInt = mesNascimentoInt - 1;
	}

	printf("\n\n==>> Voc� � do signo de *** %s", arraySignos[mesNascimentoInt]);
    printf(" ***");
	getch();
	menuPrincipal();
}
//--------------------------------------------------------------
int fraseMotivacional(){
    int opcFraseMotivacional;

	limparTela();
	printf("\n                   *** FRASE MOTIVACIONAL DO SIGNO ***\n\n");
	printf("*---------------------------------------------------------------------------*\n");
	printf("!                             Signos do Zod�aco                             !\n");
	printf("!                                                                           !\n");
	printf("!   (1) Capric�rnio   (4) �ries         (7) Cancer        (10) Libra        !\n");
	printf("!   (2) Aqu�rio       (5) Touro         (8) Le�o          (11) Escorpi�o    !\n");
	printf("!   (3) Peixes        (6) G�meos        (9) Virgem        (12) Sargit�rio   !\n");
	printf("!                                                                           !\n");
	printf("*---------------------------------------------------------------------------*\n\n\n");
	printf("    Digite o n�mero que representa o seu signo: ");
	fflush(stdin);
    scanf("%d", &opcFraseMotivacional);

    	switch (opcFraseMotivacional){
		case 1:
				pegaFrase("11");
				break;
		case 2:
			 	pegaFrase("12");
				break;
		case 3:
				pegaFrase("13");
				break;
		case 4:
				pegaFrase("14");
				break;
		case 5:
				pegaFrase("15");
				break;
		case 6:
				pegaFrase("16");
				break;
		case 7:
				pegaFrase("17");
				break;
		case 8:
				pegaFrase("18");
				break;
		case 9:
				pegaFrase("19");
				break;
		case 10:
				pegaFrase("20");
				break;
		case 11:
				pegaFrase("21");
				break;
		case 12:
				pegaFrase("22");
				break;
		default: printf("\nOp��o Inv�lida!");
	}
    getch();
	menuPrincipal();
}
//--------------------------------------------------------------
int pegaFrase(char idFrase[]){
    char data[512], data_copia[101] = { 0 };

    FILE *arquivotxt;
    arquivotxt = fopen("horoscopo.txt", "r");
    if (arquivotxt != NULL){
        while(fgets(data,512,arquivotxt)){
            if(strstr(data, idFrase) != NULL){
                data[strlen(data)-1] = '\0';
                memcpy(data_copia, &data[2], 101);
                printf("\n[ %s", data_copia);
                printf(" ]");
            }
        }
    } else {
        printf("\nO arquivo horoscopo.txt n�o foi encontrado.\nUse a op��o 0 do menu principal para criar um novo aquivo.");
	}
}
//--------------------------------------------------------------
