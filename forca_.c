#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#define L 50
#define P 54 // quantidade pré-definida de palavras

// prot. functions
void header(); // painel >> FORCA
void menu(); // menu
void screen(); // mostrar menu na tela
void forca(); // jogo da forca
char *F(char name[], char c[]); //
void placar(int x, int y, int z);
void dev(); // opção de desenvolvedor >> mostrar todas as palavras - dev arquivos
void bordas(int a, int b, int x, int y); // borderline
void gotoxy(int x, int y); // coordenadas
void movexy(int x, int y, char *c); // coordenadas >> string
void textcolor(int c); // cores
void lines(int n); // linhas horizontais

// esquema de cores
enum cor {
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};

/* 	 
	09 de fevereiro de 2020	
    Departamento de T.I., UniProjeção (Taguatinga, Campus I)
    
    Sistemas de Informação (3º semestre)
    Autor: Yan Almeida Garcia 
    
  	00) jogo da forca
  		O jogo da forca é um jogo em que o jogador tem que acertar qual é a palavra proposta,
		tendo como dica o número de letras e o tema ligado à palavra. A cada letra errada, 
		é desenhada uma parte do corpo do enforcado.
*/

// global vars.
	int i = 0, j;
	char opt, senha[L], acess[L];
	
int main(){	
	screen();

	return 0;
}

// functions
	// painel >> FORCA
void header(){
	int f = 2, o = 9, r = 18, c = 26, a = 35, A = 7, B = 43;

    system("cls");
		// bordas
	bordas(A, B, 7, 3);
		// quadro >> forca - formada por linhas
    for(i = 0; i < A; i++){
    	gotoxy(8, 4 + i);
    	for(j = 0; j < B; j++){
    		textcolor(WHITE);
    		if(i == 1){ // linha 1
    			if(j == f || j == 3 || j == 4 || j == 5 || j == 6) printf("Û");
    			else if(j == 10 || j == 11 || j == 12 || j == 13 || j == 14) printf("Û");
    			else if(j == r || j == 19 || j == 20 || j == 21 || j == 22) printf("Û");
    			else if(j == 27 || j == 28 || j == 29 || j == 30 || j == 31) printf("Û");
    			else if(j == 36 || j == 37 || j == 38 || j == 39) printf("Û");
    			else printf(" ");
 
			}else if(i == 2){ // linha 2
				if(j == f) printf("Û");
				else if(j == o || j == 15) printf("Û");
				else if(j == r || j == 23) printf("Û");
				else if(j == c || j == 32) printf("Û");
				else if(j == a || j == 40) printf("Û");
				else printf(" ");
			}else if(i == 3){ // linha 3
				if(j == f || j == 3 || j == 4) printf("Û");
				else if(j == o || j == 15) printf("Û");
				else if(j == r || j == 19 || j == 20 || j == 21 || j == 22) printf("Û");
				else if(j == c) printf("Û");
				else if(j == a || j == 36 || j == 37 || j == 38 || j == 39 || j == 40) printf("Û");
				else printf(" ");
			}else if(i == 4){ // linha 4
    			if(j == f) printf("Û");
				else if(j == o || j == 15) printf("Û");
				else if(j == r || j == 21) printf("Û");
				else if(j == c || j == 32) printf("Û");
				else if(j == a || j == 40) printf("Û");
				else printf(" ");	
			}else if(i == 5){ // linha 5
				if(j == f) printf("Û");
				else if(j == 10 || j == 11 || j == 12 || j == 13 || j == 14) printf("Û");
				else if(j == r || j == 22) printf("Û");
				else if(j == 27 || j == 28 || j == 29 || j == 30 || j == 31) printf("Û");
				else if(j == a || j == 40) printf("Û");
				else printf(" ");
			}
		}
	}			
}
	// menu
void menu(){
	int a = 7, b = 20, c = 71;
		//bordas
	bordas(a, b, c, 3);	
		// texto
	textcolor(WHITE);
}
	// mostrar menu
void screen(){
	int posX = 73, posY = 5, c = 71, cmp; // posição incial : >> 
	   
    system("title MENU PRINCIPAL");
    system("color 3F");
		// painel >> FORCA
	header();
		// menu móvel
	menu();
	movexy(c + 5, 5, " JOGAR ");
	movexy(c + 5, 7, " DESENVOLVEDOR ");
	movexy(c + 5, 9, " SAIR ");
	
	movexy(posX, posY, ">>");
	do{
		opt = toupper(getch());
		
		switch(opt){
				// seta pra CIMA
			case 72: 
				if(posY > 5){ // LIM 5
					movexy(posX, posY, "  ");
					posY -= 2;
					movexy(posX, posY, ">>");
					_beep(400, 100);
				}
			break;
				// seta pra BAIXO
			case 80: 
				if(posY < 8){ // LIM 8
					movexy(posX, posY, "  ");
					posY += 2;
					movexy(posX, posY, ">>");
					_beep(420, 100);
				}
			break;
				// seta pra DIREITA >> selecionar opção
			case 77: 
					// acessa >> jogo da forca
				if(posY == 5) forca();
					// acessa >> modo desenvolvedor
				if(posY == 7){
					do{
						strcpy(senha, "MK18410");
						
						movexy(15, 15, " SENHA: ");
						scanf(" %s", &acess);
							// 'toupper' não funcionará dentro do 'strcmp' >> usa-se strupr
						cmp = strcmp(strupr(acess), senha);
						
						if(cmp == 0) dev();
						else{
							movexy(11, 17, " > acess denied < ");
							Sleep(550);
							screen();
						} 
					}while(1);
				}
					// acessa >> encerra o programa
				if(posY == 9){
					system("cls");
					exit(2);
				}				
			break;	
		}
		
	}while(1);
}	
	// jogo 
void forca(){
	char stg[L], cpyStg[L], trying[L], shot, c[L]; // palavra, copia da palavra, tentativa, passagem
	char stgA[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y' ,'z'}; // ALFABETO
	char cpyStgA[26], tryingA[L]; // letras usadas
	int stop = 0, correct, search; // limite, corretas, letra encontrada
	int n_try, lim_try; // num. de tentativa, limite
	int a = 10, b = 18; // coordenadas
	
	system("title JOGO DA FORCA");
    system("color 3F");
    
    do{
    		// limpando resultados anteriores
    	n_try = 0;
    	lim_try = 0;
    	correct = 0;
			// busca palavra >> lim. de tentativas
		strcpy(stg, F("forca.txt", c)); // maior palavra >> 10 dig. AAAAAAAAAA
		strcpy(cpyStg, stg);	
		
		strcpy(cpyStgA, stgA);
		
		for(i = 0; i < strlen(stg); i++) trying[i] = ' '; // limpando tentativas >> arq. txt
		for(i = 0; i < strlen(stgA); i++) tryingA[i] = ' '; // limpando tentativas >> alfabeto
		lim_try = strlen(stg) + 2;	// limite de tentativas >> tam. stg + 2
		
		do{				
				// painel >> FORCA
			header();	
			bordas(6, 43, 7, b - 2);	
			
			placar(lim_try, n_try, correct);
				// 
			textcolor(WHITE);
			gotoxy(a, b);
			for(i = 0; i < strlen(stg); i++) printf(" %c  ", toupper(trying[i]));
			
			movexy(22, 13, " LETRAS USADAS ");
			gotoxy(a - 6, 14);		
			for(i = 0; i < strlen(stgA); i++) printf("%c ", toupper(tryingA[i]));
			gotoxy(a, b + 1);
			for(i = 0; i < strlen(stg); i++) printf(" _  ");
			 
			movexy(a, b + 3, " LETRA: ");
			scanf(" %c", &shot);
			fflush(stdin);

				// percorre vetor verificando se há uma letra igual
			search = 0;
			for(i = 0; i < strlen(stg); i++){
				if(toupper(cpyStg[i]) == toupper(shot)){
					cpyStg[i] = '*'; // 
					trying[i] = toupper(shot);
					correct++;
					search = 1;
				}
			}
			
			for(i = 0; i < strlen(stgA); i++){
				if(toupper(cpyStgA[i]) == toupper(shot)){
					cpyStgA[i] = '*'; // 
					tryingA[i] = toupper(shot);
				}
			}
			
			if(search == 0) n_try++;
				// validar vitoria
			if(n_try >= lim_try || correct == strlen(stg)) stop = 1;
				// voltar ao menu	
		}while(stop == 0);
			// mostrar na tela a palavra + indicador >> vitoria
		if(correct == strlen(stg)){
			placar(lim_try, n_try, correct);
				// cadeia completa >> stg
			gotoxy(a, b);
			for(i = 0; i < strlen(stg); i++) printf(" %c  ", toupper(trying[i]));
				// cadeia completa >> ALFABETO
			gotoxy(a - 6, 14);		
			for(i = 0; i < strlen(stgA); i++) printf("%c ", toupper(tryingA[i]));
				// palavra >> arq. txt
			gotoxy(a, b + 3);
			printf(" A PALAVRA %c: [ %s ] ", 144, toupper(stg));
		}else if(n_try >= lim_try){
			placar(lim_try, n_try, correct);
				// palavra >> arq. txt
			gotoxy(a, b + 3);
			printf(" A PALAVRA CORRETA ERA: [ %s ] ", toupper(stg));
		}
	
		movexy(9, b + 7, "Deseja jogar novamente [S/N]: ");
		
		fflush(stdin);
		scanf(" %c", &opt);
		
		if(toupper(opt) == 'S') forca();
		else screen();
	}while(1);	
}
	//
char *F(char name[], char c[]){
	char LIN[P][L];
	int cont = 0, R;
	
	FILE *arq = fopen("forca.txt", "r");
	
	if(arq != NULL){
		do{
			fgets(c, P, arq);
				// remove quebras de linhas extras
			for(R = 0; R < strlen(c); R++) 
				if(c[R] == '\n') c[R] = '\0';
			
			if(strcmp(c, "")){//compara (!= NULL) e armazena no vetor
				strcpy(LIN[cont], c);
				cont++;
			}
		}while(! feof(arq));
	}else movexy(15, 15, "ERRO AO ABRIR ARQUIVO .TXT");
	fclose(arq);
	
	srand(time(NULL));
	R = rand() % cont + 1;
	
	strcpy(c, LIN[R]);
	return c;
}
	// pontos
void placar(int x, int y, int z){
	int c = 71;
	
	menu();
	
	gotoxy(c + 4, 6);
	printf(" RESTANTES: %.2d ", x - y);
	gotoxy(c + 4, 8);
	printf(" ACERTOS:   %.2d ", z);
}
	// opção de desenvolvedor >> mostrar todas as palavras - listar arquivos
void dev(){
	int id, c = 71, d = 17; // num de identificação && coordenadas
	int posX = 73, posY = 8; // coordenadas
	char item[30]; // nome do item
			
	system("title MODO DESENVOLVEDOR");
	system("color 8F");
		// abrindo arqs.
	FILE* FG = fopen("01_FG.txt", "r"); // frutas e vegetais >> num. 01
	FILE* AI = fopen("02_AI.txt", "r"); // animais e insetos >> num. 02
	FILE* BJ = fopen("03_BJ.txt", "r"); // brincadeiras e jogos >> num. 03
	FILE* PC = fopen("04_PC.txt", "r"); // paises e continentes >> num. 04
	FILE* C = fopen("05_C.txt", "r"); // cores >> num. 05
	FILE* M = fopen("06_M.txt", "r"); // cores >> num. 06
		
		// painel >> FORCA
	header();
		// menu 
	menu();
	movexy(c + 5, 6, " VER SENHA ");
	movexy(c + 5, 8, " VOLTAR ");
		// escopo >> palavras
	bordas(11, 84, 7, 15);			
		// abrindo arquivo >> FRUTAS E VERDURAS (1-9)
	textcolor(WHITE);
	if(FG != NULL){
		i = 0;
		while(fscanf(FG, "%d %[^\n]s", &id, item) != EOF){ // condição pra listar o conteúdo do arq.	
			gotoxy(10, d + i);
			textcolor(WHITE);
			printf("%d %s", id, item);
			i++;
		}
	}else movexy(10, d, " Error ");	
	fclose(FG);
		// abrindo arquivo >> ANIMAIS E INSETOS (1-9)
	if(AI != NULL){
		i = 0;
		while(fscanf(AI, "%d %[^\n]s", &id, item) != EOF){ // condição pra listar o conteúdo do arq.
			gotoxy(24, d + i);
			textcolor(WHITE);
			printf("%d %s", id, item);
			i++;
		}
	}else movexy(24, d, " Error ");	
	fclose(AI);
		// abrindo arquivo >> BRINCADEIRAS E JOGOS (1-9)
	if(BJ != NULL){
		i = 0;
		while(fscanf(BJ, "%d %[^\n]s", &id, item) != EOF){ // condição pra listar o conteúdo do arq.
			gotoxy(37, d + i);
			textcolor(WHITE);
			printf("%d %s", id, item);
			i++;		
		}
	}else movexy(37, d, " Error ");	
	fclose(BJ);
		// abrindo arquivo >> PAISES E CONTINENTES (1-9)
	if(PC != NULL){
		i = 0;
		while(fscanf(PC, "%d %[^\n]s", &id, item) != EOF){ // condição pra listar o conteúdo do arq.
			gotoxy(52, d + i);
			textcolor(WHITE);
			printf("%d %s", id, item);
			i++;		
		}
	}else movexy(52, d, " Error ");	
	fclose(PC);
		// abrindo arquivo >> CORES (1-9)
	if(C != NULL){
		i = 0;
		while(fscanf(C, "%d %[^\n]s", &id, item) != EOF){ // condição pra listar o conteúdo do arq.
			gotoxy(66, d + i);
			textcolor(WHITE);
			printf("%d %s", id, item);
			i++;		
		}
	}else movexy(66, d, " Error ");	
	fclose(C);
		// abrindo arquivo >> MESES (1-9)
	if(M != NULL){
		i = 0;
		while(fscanf(M, "%d %[^\n]s", &id, item) != EOF){ // condição pra listar o conteúdo do arq.
			gotoxy(79, d + i);
			textcolor(WHITE);
			printf("%d %s", id, item);
			i++;		
		}
	}else movexy(79, d, " Error ");	
	fclose(M);
		// menu interativo
	movexy(posX, posY, ">>");	
	do{
		opt = toupper(getch());
		
		switch(opt){
			case 72: // seta pra CIMA
				if(posY > 6){ // LIM 6
					movexy(posX, posY, "  ");
					posY -= 2;
					movexy(posX, posY, ">>");
					_beep(400, 100);
				}
			break;
			
			case 80: // seta pra BAIXO
				if(posY < 7){ // LIM 7
					movexy(posX, posY, "  ");
					posY += 2;
					movexy(posX, posY, ">>");
					_beep(420, 100);
				}
			break;
			
			case 77: // seta pra DIREITA >> selecionar opção
				if(posY == 6){
					bordas(1, 7, 57, 6);
					gotoxy(58, 7);
					textcolor(WHITE);
					printf("MK18410", senha);
					
					sleep(1);
					dev();
				}
				if(posY == 8){
					screen();
				}				
			break;	
		}
		
	}while(1);
	
	getch();	
}
	// borderline
void bordas(int a, int b, int x, int y){
	for(i = 0; i < a + 2; i++){
    	gotoxy(x, y + i);
    	for(j = 0; j < b + 2; j++){
    		textcolor(LIGHT_GRAY);
	    	if(i == 0) printf("Û");
	    	else if(j == 0) printf("Û");
	    	else if(j == b + 1) printf("Û");
	    	else if(i == a + 1) printf("Û");
	    	else printf(" ");
		}
	}
}
	// coordenadas 
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
	// coordenadas >> string
void movexy(int x, int y, char *c){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	printf("%s", c);
}	
	// cores
void textcolor(int c){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= c);
}
	// linhas horizontais
void lines(int n){
	for(i = 0; i < n; i++) printf("Û");
}
