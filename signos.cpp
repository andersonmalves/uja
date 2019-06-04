#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <conio.h>

using namespace std;

const char* arraySignos[] = {"CAPRICÓRNIO - 22/12 a 19/01", "AQUÁRIO - 20/01 a 18/02", "PEIXES - 19/02 a 20/03", "ÁRIES - 21/03 a 19/04", "TOURO - 20/04 a 20/05", "GÊMEOS - 21/05 a 21/06", "CÂNCER - 22/06 a 22/07", "LEÃO - 23/07 a 22/08", "VIRGEM - 23/08 a 22/09", "LIBRA - 23/09 a 22/10", "ESCORPIÃO - 23/10 a 21/11", "SAGITÁRIO - 22/11 a 21/12", "CAPRICÓRNIO - 22/12 a 19/01"};

void menuPrincipal(void);
void criaArquivo(void);
void informaSigno(void);
void fraseMotivacional(void);
void pegaFrase(char idFrase[]);
void limparTela(void);

int main(){
	setlocale(LC_ALL, "Portuguese");
	#if defined _WIN32
	system("TITLE SIGNOS ZODIACAIS");
	system("COLOR 0A");
	#endif
	menuPrincipal();
}
//-------------------------------------------------------------- 
void menuPrincipal(void){
	
	int opcMenuPrincipal;
	
	while (opcMenuPrincipal > 3) {
		limparTela();
	 	cout << "" << endl;	
		cout << "	----------- SIGNOS DO ZODÍACO -----------" << endl;
		cout << "" << endl;
		cout << "	0 - Cria arquivo com frases motivacionais" << endl;
		cout << "	1 - Saber qual é o signo" << endl;
		cout << "	2 - Frase motivacional do signo" << endl;
		cout << "	3 - Sair" << endl;
		cout << "" << endl;
	    cout << "            *** Entre com uma das opções acima: ";
	    cin >> opcMenuPrincipal;
	    
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
				cout << "Obrigado por usar o programa SIGNOS ZODIACAIS" << endl;	
				exit(0);	
		} 
	}
}
//-------------------------------------------------------------- 
void criaArquivo(void){
	
	char frase[101];	
	int idFrase = 11, tamanho;
	FILE *arquivotxt;
	arquivotxt = fopen("horoscopo.txt", "w");
	
	for(int i = 0; i <= 11; i++){ // valor default = 11
		tamanhoExcedido:
		limparTela();
		cout << "" << endl;
		cout << "							   *** CRIA ARQUIVO COM FRASES MOTIVACIONAIS ***" << endl;
		cout << "" << endl;
		cout << "" << endl;
		cout << "Entre com a frase motivacional para o signo de " << arraySignos[i] << endl;
		cout << "" << endl;
		cout << "[-----------------------------------Tamanho máximo de 100 posições-----------------------------------]	" << endl;
		fflush(stdin); // limpa buffer
		cin.ignore();
		cin.getline(frase,sizeof frase);
		cin.clear();
		
		tamanho = strlen(frase);
		if(tamanho >= 100) {
			cout << "\nATENÇÃO: a frase deve ter no máximo 100 caracteres!";
			getch();
			goto tamanhoExcedido;
		}
		fprintf(arquivotxt, "%d%s\n", idFrase++, frase);
	}
	fclose(arquivotxt);
	getch();
	menuPrincipal();	
}
//-------------------------------------------------------------- 
void informaSigno(void){
	
	string dataNascimento, diaNascimentoStr, mesNascimentoStr;
	int diaNascimentoInt, mesNascimentoInt, arrayDias[13] = {0,21,20,21,21,21,21,22,23,23,23,22,22};
	
	limparTela();
	cout << "" << endl;
	cout << "			*** INFORMA O SIGNO ***" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "Informe o dia e o mês que você nasceu (DDMM):	";
	cin >> dataNascimento;
	
	diaNascimentoStr = dataNascimento.substr(0,2);
	mesNascimentoStr = dataNascimento.substr(2,2);
	
	istringstream(diaNascimentoStr) >> diaNascimentoInt;
	istringstream(mesNascimentoStr) >> mesNascimentoInt;

	if (diaNascimentoInt < arrayDias[mesNascimentoInt]) {
		mesNascimentoInt = mesNascimentoInt - 1;
	}
		
	cout << "\n==>> Você é do signo de *** " << arraySignos[mesNascimentoInt] << " ***" << endl;
	getch();
	menuPrincipal();
}
//-------------------------------------------------------------- 
void fraseMotivacional(void){
	
	int opcFraseMotivacional;
	
	limparTela();
	cout << "" << endl;	
	cout << "                   *** FRASE MOTIVACIONAL DO SIGNO ***" << endl;
	cout << "" << endl;	
	cout << "*---------------------------------------------------------------------------*" << endl;
	cout << "!                             Signos do Zodíaco                             !" << endl;
	cout << "!                                                                           !" << endl;
	cout << "!   (1) Capricórnio   (4) Áries         (7) Cancer        (10) Libra        !" << endl;
	cout << "!   (2) Aquário       (5) Touro         (8) Leão          (11) Escorpião    !" << endl;
	cout << "!   (3) Peixes        (6) Gêmeos        (9) Virgem        (12) Sargitário   !" << endl;
	cout << "!                                                                           !" << endl;
	cout << "*---------------------------------------------------------------------------*" << endl;
	cout << "" << endl;	
	cout << "" << endl;	
	cout << "    Digite o número que representa o seu signo: ";
	cin >> opcFraseMotivacional;
	
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
		default: cout << "Opção Inválida!";
	}
	getch();
	menuPrincipal();
}
//--------------------------------------------------------------
void pegaFrase(char idFrase[]){

	char data[512];
	string frase;

	FILE *arquivotxt;
	arquivotxt = fopen("horoscopo.txt", "r");
	
	if (arquivotxt != NULL){
		while(fgets(data,512,arquivotxt)){
			if(strstr(data, idFrase) != NULL) {			
				data[strlen(data)-1] = '\0';
				frase += data;
				frase = frase.substr(2,100);
				cout << "\n[ " << frase << " ]" << endl;	
			}
		};
	} else {
		cout << "\nO arquivo horoscopo.txt não foi encontrado.\nUse a opção 0 do menu principal para criar um novo aquivo." << endl;
	}
}
//---------------------------------------------------------------
void limparTela(){
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}
