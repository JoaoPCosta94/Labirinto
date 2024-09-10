// testarLabs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;
#define color_black      0	
#define color_blue       9
#define color_green     10
#define color_red       12

#define LIN 10
#define COL 20
int main()
{
	string trap = "#";
	string lab2[LIN][COL] = {
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

	for (int i = 0; i < LIN; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			

			if (lab2[i][j] == "@")
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << lab2[i][j];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			else if (lab2[i][j] == trap)
			{
				if (lab2[i][j] == trap)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
					cout << lab2[i][j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				}
			}
			else
			{
				cout << lab2[i][j];
			}
		}
		cout << endl;
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
