// Labirinto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
#include <time.h>

using namespace std;

#define color_black      0	
#define color_dark_green 2
#define color_blue       9
#define color_green     10
#define color_red       12

#define LIN 10
#define COL 20
string trapTriggered = "X";

// Protótipos   
void Menu(char& resposta);
void escolhaPersonagem(string& personagem, int& corPersonagem);
void Labirinto1(string personagem, int corPersonagem, string trap);
boolean Labirinto2(string personagem, int corPersonagem, string trap);
void Labirinto3(string personagem, int corPersonagem, string trap);
void movimento(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas);
void cima(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas);
void esquerda(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas);
void baixo(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas);
void direita(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas);
void printLab(string lab[][COL], string personagem, int corPersonagem, string trap);
boolean validaTempo(clock_t tempoInicial, clock_t tempoAtual, clock_t& duracao, int tempoLimite);
void comoJogar();
void Saida();

int main()
{
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	char resposta;
	string personagem;
	int corPersonagem;
	string trap = "#";
	

	do
	{
		do
		{
			Menu(resposta);
			switch (resposta)
			{
			case 'a': escolhaPersonagem(personagem, corPersonagem); break;
			case 'b': comoJogar(); break;
			case 'c': Saida(); break;
			}

		} while (resposta != 'a');

			system("cls");
			Labirinto1(personagem, corPersonagem, trap);
			Sleep(2000);
			if (Labirinto2(personagem, corPersonagem, trap) == true)
			{
				Sleep(2000);
				Labirinto3(personagem, corPersonagem, trap);
			}
			
			

	} while (true);
	
	
}
//-----------------------------------------------------------------------------------------------
//Função para desenhar o menu
void Menu(char& resposta)
{
	system("cls");
	do
	{
		cout << "\n\t\t00000000000 Jogo Do Labirinto 00000000000";
		cout << "\n\t\t0\t\t\t\t\t0";
		cout << "\n\t\t0    (A) Jogar\t\t\t\t0";
		cout << "\n\t\t0    (B) Como Jogar\t\t\t0";
		cout << "\n\t\t0    (C) Sair\t\t\t\t0";
		cout << "\n\t\t0\t\t\t\t\t0";
		cout << "\n\t\t00000000000000000000000000000000000000000";
		cout << "\n\n\t\t Digite uma opção:  ";
		resposta = tolower(_getche());
		

		if (resposta == 'a' || resposta == 'b' || resposta == 'c')
		{
			break;
		}
		else
		{

			system("cls");
			cout << "\n\n\t\tErro! Por favor digite uma das opções!";
			Sleep(1000);
			system("cls");

		}
	} while (resposta != 'a' && resposta != 'b' && resposta != 'c');
}
//-----------------------------------------------------------------------------------------------
// Função para escolher caracter e cor
void escolhaPersonagem(string& personagem, int& corPersonagem)
{
	char resposta;
	char cor;
	char aux;
	bool boolaux = true;
	do
	{
		system("cls");
		cout << "\n\t\t00000000000 Jogo Do Labirinto 00000000000";
		cout << "\n\n\tEscolha uma letra para ser o seu personagem:  ";
		aux = toupper(_getche());
		if (isalpha(aux))
		{
			do
			{
				system("cls");
				cout << "\n\t\t00000000000 Jogo Do Labirinto 00000000000";
				cout << "\n\n\tEscolha uma cor para o seu personagem:  ";
				cout << "\n\n\t\t R = Vermelho";
				cout << "\n\t\t G = Verde";
				cout << "\n\t\t B = Azul";
				cout << "\n\n\t\t Cor:  ";
				cor = toupper(_getche());

				if (cor == 'R' || cor == 'G' || cor == 'B')
				{
					switch (cor)
					{
					case 'R': corPersonagem = 12; break;
					case 'G': corPersonagem = 10; break;
					case 'B': corPersonagem = 9; break;
					}
					boolaux = false;
				}
				else
				{
					system("cls");

				}

			} while (boolaux == true);
		}
		else
		{
			"\n\tErro! Por favor digite um caracter válido!";
			cin.clear();
			cin.ignore(100, '\n');

		}
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "\n\t\t00000000000 Jogo Do Labirinto 00000000000";
		cout << "\n\n\t Você escolheu ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), corPersonagem);
		cout << aux;
		cout << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		cout << "como sua personagem, prima Y para continuar ou N para escolher de novo.";
		resposta = toupper(_getche());


	} while (resposta != 'Y');

	personagem = aux;

}
//-----------------------------------------------------------------------------------------------
//Labirintos
void Labirinto1(string personagem, int corPersonagem, string trap)
{
	int vidas = 1;
	system("cls");
	cout << endl;
	
	string lab1[LIN][COL] = {
		{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"},
		{" "," "," "," "," ","0","0"," ","0"," "," "," "," "," ","0"," "," "," "," ","0"},
		{"0"," ","0","0"," "," "," "," "," "," ","0","0","0"," ","0"," "," ","0"," ","0"},
		{"0"," ","0","0","0","0"," ","0","0"," ","0"," ","0"," "," "," ","0"," "," "," "},
		{"0"," "," ","0","0"," "," ","0","0"," "," "," ","0","0","0","0","0"," ","0","0"},
		{"0","0"," "," "," "," ","0","0","0","0","0","0","0","0","0","0","0"," ","0","0"},
		{"0","0"," ","0"," "," "," "," "," ","0","0"," ","0","0"," "," "," "," "," ","0"},
		{"0","0"," ","0","0","0","0","0"," "," "," "," "," "," "," ","0","0","0","0","0"},
		{"0"," "," "," "," ","0","0","0","0","0","0","0","0","0"," "," "," ","0","0","0"},
		{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"}
	};

	int l = 1, c = 0;
	lab1[l][c] = personagem;
	int startL = 1, startC = 0;
	do
	{
		system("cls");
		printLab(lab1, personagem, corPersonagem, trap);
		movimento(lab1, l, c, personagem, trap ,startL, startC, vidas);
		if (l == 3 && c == 19)
		{
			system("cls");
			printLab(lab1, personagem, corPersonagem, trap);
			cout << "Parabéns! Venceu o 1º Labirinto. O próximo tem armadilhas " << "'" << trapTriggered << "'" << " ! Boa sorte!" << endl;
			break;
		}
		
	} while (true);
}
boolean Labirinto2(string personagem, int corPersonagem, string trap)
{
	int vidas = 3;
	system("cls");
	cout << endl;
	string lab2[LIN][COL] = {
	{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"},
	{"0"," "," "," "," ","0","0","0","0","0","0","0","0","0","0","#"," "," "," ","0"},
	{"0"," ","0","0"," "," "," "," ","0","0","0","0"," ","0"," "," ","0","0"," ","0"},
	{"0"," "," ","0","0","0","0"," ","0","0","0"," "," "," "," "," ","0","0"," ","0"},
	{"0","0"," ","0","0","0","0"," ","0"," "," ","#","0"," ","0"," "," "," "," "," "},
	{"0"," "," ","#"," "," "," "," "," "," ","0","0","0"," ","0","0","0","0","#","0"},
	{"0"," ","0","0","0"," ","0","0","0","0","0","0","0"," "," "," "," ","0"," ","0"},
	{"0"," ","0","0","0"," "," "," "," "," "," "," "," ","0","0","0"," ","0"," ","0"},
	{" "," ","0"," "," "," ","0","0","0","0","0","0"," "," "," "," "," "," "," ","0"},
	{"0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0","0"},
	};

	int l = 8, c = 0;
	int startL = 8, startC = 0;    //definir a posiçao inicial para quando o jogador pisa uma armadilha voltar ao inicio do jogo
	lab2[l][c] = personagem;;
	do
	{
		system("cls");
		printLab(lab2, personagem, corPersonagem, trap);
		cout << "\nVidas = " << vidas;
		movimento(lab2, l, c, personagem, trap, startL, startC, vidas);
		if (vidas == 0)
		{
			cout << "\n\tGAME OVER!";
			return false;

		}
		if (l == 4 && c == 19)
		{
			system("cls");
			printLab(lab2, personagem, corPersonagem, trap);
			cout << "\n\tParabéns! Venceu o 2º Labirinto. O próximo tem tempo limite! Boa sorte! " << endl;
			break;
		}

	} while (true);
	return true;
}
void Labirinto3(string personagem, int corPersonagem, string trap)
{
	int vidas = 5;
	system("cls");
	cout << endl;
	string lab3[LIN][COL] = {
		{"0","0","0","0","0","0","0","0","0"," ","0","0","0","0","0","0","0","0","0","0"},
		{"0"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","0"},
		{"0","#","0","0","0","0","0","0","0","#","0","0","0","0","0","0","0","0"," ","0"},
		{"0"," "," "," "," "," "," "," "," "," "," "," "," ","0"," "," "," "," "," ","0"},
		{"0"," "," ","0","0","0","0","0","0","#","0"," ","0","0","0"," ","0","0","#","0"},
		{"0","0"," "," ","0","0"," "," "," "," ","0"," "," "," ","#"," "," "," "," ","0"},
		{"0","0","0"," ","0","0"," ","0","0"," ","0","0"," ","0","0","0","0","0"," ","0"},
		{"0"," "," "," ","0"," "," "," ","#"," "," ","0"," "," "," "," "," "," "," ","0"},
		{"0","0"," "," "," "," "," "," ","0"," ","0","0","0","0","0","0","0","0","0","0"},
		{"0","0","0","0","0","0","0","0","0"," ","0","0","0","0","0","0","0","0","0","0"},
	};

	int l = 0, c = 9;
	lab3[l][c] = personagem;
	int startL = 0, startC = 9;
	clock_t tempoInicial = 0, tempoAtual = 0, duracao = 0;
	int tempoLimite = 40;
	do
	{
		system("cls");
		printLab(lab3, personagem, corPersonagem, trap);
		cout << "\nVidas: " << vidas;
		cout << "\nTempo limite: "<< tempoLimite - duracao << " segundos";
		movimento(lab3, l, c, personagem, trap, startL, startC, vidas);
		if (tempoInicial == 0)
		{
			tempoInicial = clock();
		}
		if (validaTempo(tempoInicial, tempoAtual, duracao, tempoLimite) == false)
		{
			system("cls");
			cout << "\n\tAcabou o tempo! GAME OVER!";
			Sleep(2000);
			break;
		}
		if (vidas == 0)
		{
			cout << "\n\tGAME OVER!";
			break;

		}
		if (l == 9 && c == 9)
		{
			system("cls");
			printLab(lab3, personagem, corPersonagem, trap);
			cout << "\n\tParabéns! Venceu o 3º Labirinto." << endl;
			break;
		}

		

	} while (true);

}
//-----------------------------------------------------------------------------------------------
// Função para dar print aos labirintos
void printLab (string lab[][COL], string personagem, int corPersonagem, string trap)
{
	for (int i = 0; i < LIN; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (lab[i][j] == personagem)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), corPersonagem);
				cout << lab[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else if (lab[i][j] == trap)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
				cout << lab[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else if (lab[i][j] == trapTriggered)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
				cout << lab[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else
			{
				cout << lab[i][j];
			}
		}
		cout << endl;
	}
}
//-----------------------------------------------------------------------------------------------
// Funções para movimentar o personagem
void movimento(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas)
{
	char tecla = tolower(_getch());

	if (tecla == 'w' || tecla == 'a' || tecla == 's' || tecla == 'd')
	{
		switch (tecla)
		{
		case 'w': cima(lab, l, c, personagem, trap, startL, startC, vidas); break;
		case 'a': esquerda(lab, l, c, personagem, trap, startL, startC, vidas); break;
		case 's': baixo(lab, l, c, personagem, trap, startL, startC, vidas);  break;
		case 'd': direita(lab, l, c, personagem, trap, startL, startC, vidas); break;
		}
	}

}
void cima(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas)
{
	if (lab[l - 1][c] == " ")
	{
		lab[l][c] = " ";
		lab[--l][c] = personagem;
	}
	else if (lab[l - 1][c] == trap)
	{
		lab[l - 1][c] = trapTriggered;
		lab[l][c] = " ";
		l = startL;
		c = startC;
		lab[l][c] = personagem;
		vidas--;
		cout <<"\nOuch pisou uma armadilha!Perdeu uma vida!";
		_getche();
 
	}

}
void esquerda(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas)
{
	if (lab[l][c - 1] == " ")
	{
		lab[l][c] = " ";
		lab[l][--c] = personagem;
	}
	else if (lab[l][c - 1] == trap)
	{
		lab[l][c - 1] = trapTriggered;
		lab[l][c] = " ";
		l = startL;
		c = startC;
		lab[l][c] = personagem;
		vidas--;
		cout << "\nOuch pisou uma armadilha!Perdeu uma vida!";
		_getche();
	}
}
void baixo(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas)
{
	if (lab[l + 1][c] == " ")
	{
		lab[l][c] = " ";
		lab[++l][c] = personagem;
	}
	else if (lab[l + 1][c] == trap)
	{
		lab[l + 1][c] = trapTriggered;
		lab[l][c] = " ";
		l = startL;
		c = startC;
		lab[l][c] = personagem;
		vidas--;
		cout << "\nOuch pisou uma armadilha!Perdeu uma vida!";
		_getche();
	}
}
void direita(string lab[][COL], int& l, int& c, string personagem, string trap, int startL, int startC, int& vidas)
{
	if (lab[l][c + 1] == " ")
	{
		lab[l][c] = " ";
		lab[l][++c] = personagem;
	}
	else if (lab[l][c + 1] == trap)
	{
		lab[l][c + 1] = trapTriggered;
		lab[l][c] = " ";
		l = startL;
		c = startC;
		lab[l][c] = personagem;
		vidas--;
		cout << "\nOuch pisou uma armadilha!Perdeu uma vida!";
		_getche();
	}
}
//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//Função das instruções
void comoJogar()
{
	char resposta;
	system("cls");
	do
	{
		cout << "\n\t\t---------- Como jogar ----------";
		cout << "\n\n\tMovimento:";
		cout << "\n\tW - Cima";
		cout << "\n\tA - Esquerda";
		cout << "\n\tS - Baixo";
		cout << "\n\tD - Direita";
		cout << "\n\n\tM - Desligar o som";
		cout << "\n\n\tESC - Sair do jogo";
		cout << "\n\n\tPressione qualquer tecla para sair deste menu";
		resposta = _getche();
		break;
	} while (true);
}

//-----------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
//Função para dar exit ao programa
void Saida()
{
	system("cls");
	cout << "\n\t\t---------- Jogo Do Labirinto ----------";
	cout << "\n\n\t\t\t     Volte Sempre!" << endl << endl;
	exit(0);
}
//-----------------------------------------------------------------------------------------------
//Função para validar o tempo
boolean validaTempo(clock_t tempoInicial, clock_t tempoAtual, clock_t& duracao, int tempoLimite)
{
	tempoAtual = clock();
	duracao = (tempoAtual - tempoInicial) / CLOCKS_PER_SEC;
	if (duracao >= tempoLimite)
	{
		return false;
	}
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
