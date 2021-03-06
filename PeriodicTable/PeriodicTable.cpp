/*  Period Table Program
*/

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS_GLOBALS
//strcmpi fix
#include "stdafx.h"
#include <iostream> 
#include <stdlib.h>
#include <string.h>
#include <cstdio>
#include <windows.h>
#include <random>
#include <time.h>
#include <dos.h>

using namespace std;
//---------------------------------------------------------------------------

void clear_screen()
{
	DWORD n;                         /* Number of characters written */
	DWORD size;                      /* number of visible characters */
	COORD coord = { 0 };               /* Top left screen position */
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	/* Get a handle to the console */
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(h, &csbi);
	/* Find the number of characters to overwrite */
	size = csbi.dwSize.X * csbi.dwSize.Y;
	/* Overwrite the screen buffer with whitespace */
	FillConsoleOutputCharacter(h, TEXT(' '), size, coord, &n);
	GetConsoleScreenBufferInfo(h, &csbi);
	FillConsoleOutputAttribute(h, csbi.wAttributes, size, coord, &n);
	/* Reset the cursor to the top left position */
	SetConsoleCursorPosition(h, coord);
}

void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void Table(char Name[], double Number, int Group, int Period, char Formula[], char Charge[], double Mass, int Neutrons, char Special[])
{
	Neutrons = (Mass - Number);
	clear_screen();
	gotoxy(1, 2);
	cout << "Element Name:  " << Name << "\n\n";
	cout << "Formula:       " << Formula << "\n";
	cout << "Atomic Number: " << Number << "\n";
	cout << "Atomic Mass:   " << Mass << "\n";
	cout << "Group:         " << Group << "\n";
	cout << "Period:        " << Period << "\n";
	cout << "Charge:        " << Charge << "\n";
	cout << "Neutrons:      " << Neutrons << "\n";
	if (Special != "None") {
		cout << "Note:          " << Special << "\n";
	}
	cin.get();
	clear_screen();
	gotoxy(1, 2);
}
//---------------------------------------------------------------------------
void Help()
{
	clear_screen();
	gotoxy(1, 2);
	cout << "HELP\n\n";
	cout << "Help            - Opens this window.\n";
	cout << "Clear           - Clears current screen.\n";
	cout << "Prefix          - Lists prefix terms.\n";
	cout << "Element Formula - Displays information of element (eg: Sn).\n";
	cout << "Atomic Number   - Displays information of element (eg: 50).\n";
	cout << "Element Name    - Displays information of element (eg: tin).\n";
	cout << "Credits         - Information on the programmer.\n";
	cout << "Quit            - Quits the program.\n";
	cin.get();
	clear_screen();
	gotoxy(1, 2);
}
//---------------------------------------------------------------------------
void Credits()
{
	char CreditsKey;
	clear_screen();
	gotoxy(1, 2);
	cout << "CREDITS\n\n";
	/*
	cout << "I made the PERIODIC TABLE program near the end of 2000. I\n";
	cout << "had just discovered the world of C++ program, and was eager\n";
	cout << "to test it out. This is the result.\n";
	cout << "I have always enjoyed chemistry, and so it was no surprise to\n";
	cout << "me when a periodic table program was the first idea that\n";
	cout << "popped into my head.\n";
	cout << "I hope you have all enjoyed the program as an educational tool.\n";
	cout << "Enjoy the program, use it often, and my vision will be fufilled.\n\n";
	*/
	cout << "\tProgrammed by Aditya and Subhasis\n";
	cin.get();
	clear_screen();
	gotoxy(1, 2);
}
//---------------------------------------------------------------------------
void Prefix()
{
	clear_screen();
	gotoxy(1, 2);
	cout << "PREFIX\n\n";
	cout << "mono          - One (1)\n";
	cout << "di            - Two (2)\n";
	cout << "tri           - Three (3)\n";
	cout << "tetra         - Four (4)\n";
	cout << "penta         - Five (5)\n";
	cout << "hexa          - Six (6)\n";
	cout << "hepta         - Seven (7)\n";
	cout << "octa          - Eight (8)\n";
	cout << "nona or ennea - Nine (9)\n";
	cout << "deca          - Ten (10)\n";
	cin.get();
	clear_screen();
	gotoxy(1, 2);
}
//---------------------------------------------------------------------------
int main()
{
	srand(time(NULL));
	//Wait();
	int Color = 8 + rand()%8;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Color);
	/*
	if (Color == 1) {
		textcolor(RED);
	}
	else if (Color == 2) {
		textcolor(MAGENTA);
	}
	else if (Color == 3) {
		textcolor(BLUE);
	}
	else if (Color == 4) {
		textcolor(GREEN);
	}
	else if (Color == 5) {
		textcolor(WHITE);
	}
	else if (Color == 6) {
		textcolor(YELLOW);
	}
	else if (Color == 7) {
		textcolor(BROWN);
	}
	else if (Color == 8) {
		textcolor(CYAN);
	}
	*/
	clear_screen();
	gotoxy(1, 10);
	cout << "\a\t\t\t       PERIODIC TABLE         \n";
	cout << "\a\t\t\t   *--------------------*     \n";
	cout << endl;
	cout << "\a\t\t\t      Program by Aditya \n";
	cout << "\a\t\t\t          and Subhasis";
	gotoxy(35, 15);
	cin.get();
	//textcolor(WHITE);
	//textbackground(BLUE);
	clear_screen();
	gotoxy(1, 2);
	//---------------------------------------------------------------------------
	// VARIABLES
	char Formula[30],
		Name[30],
		Command[30],
		Charge[30],
		Special[30] = "None";
	int Group,
		Period;
	double Mass,
		Neutrons = 0,
		Number;
	//---------------------------------------------------------------------------
	do
	{
		cout << "Command: ";
		gets_s(Command);
		if (strcmpi(Command, "Help") || strcmpi(Command, "HELP") || strcmpi(Command, "help")) {
			Help();
		}
		else if (strcmpi(Command, "Credits") || strcmpi(Command, "CREDITS") || strcmpi(Command, "credits")) {
			Credits();
		}
		else if (strcmpi(Command, "Clear") || strcmpi(Command, "CLEAR") || strcmpi(Command, "clear")) {
			clear_screen();
			gotoxy(1, 2);
		}
		else if (strcmpi(Command, "Prefix") || strcmpi(Command, "PREFIX") || strcmpi(Command, "prefix")) {
			Prefix();
		}
		//---------------------------------------------------------------------------
		else if (strcmpi(Command, "1") || strcmpi(Command, "hydrogen") || strcmpi(Command, "H")) {
			strcpy(Name, "hydrogen");
			Number = 1;
			Group = 1;
			Period = 1;
			strcpy(Formula, "H");
			strcpy(Charge, "1+");
			Mass = 1.01;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "2") || strcmpi(Command, "helium") || strcmpi(Command, "He")) {
			strcpy(Name, "helium");
			Number = 2;
			Group = 18;
			Period = 1;
			strcpy(Formula, "He");
			strcpy(Charge, "0");
			Mass = 4.00;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "3") || strcmpi(Command, "lithium") || strcmpi(Command, "Li")) {
			strcpy(Name, "lithium");
			Number = 3;
			Group = 1;
			Period = 2;
			strcpy(Formula, "Li");
			strcpy(Charge, "1+");
			Mass = 6.94;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "4") || strcmpi(Command, "beryllium") || strcmpi(Command, "Be")) {
			strcpy(Name, "beryllium");
			Number = 4;
			Group = 2;
			Period = 2;
			strcpy(Formula, "Be");
			strcpy(Charge, "2+");
			Mass = 9.01;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "5") || strcmpi(Command, "boron") || strcmpi(Command, "B")) {
			strcpy(Name, "boron");
			Number = 5;
			Group = 13;
			Period = 2;
			strcpy(Formula, "B");
			strcpy(Charge, "3+");
			Mass = 10.81;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "6") || strcmpi(Command, "carbon") || strcmpi(Command, "C")) {
			strcpy(Name, "carbon");
			Number = 6;
			Group = 14;
			Period = 2;
			strcpy(Formula, "C");
			strcpy(Charge, "4+");
			Mass = 12.01;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "7") || strcmpi(Command, "nitrogen") || strcmpi(Command, "N")) {
			strcpy(Name, "nitrogen");
			Number = 7;
			Group = 15;
			Period = 2;
			strcpy(Formula, "N");
			strcpy(Charge, "3-");
			Mass = 14.01;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "8") || strcmpi(Command, "oxygen") || strcmpi(Command, "O")) {
			strcpy(Name, "oxygen");
			Number = 8;
			Group = 16;
			Period = 2;
			strcpy(Formula, "O");
			strcpy(Charge, "2-");
			Mass = 16.00;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "9") || strcmpi(Command, "flourine") || strcmpi(Command, "F")) {
			strcpy(Name, "fluorine");
			Number = 9;
			Group = 17;
			Period = 2;
			strcpy(Formula, "F");
			strcpy(Charge, "1-");
			Mass = 19.00;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "10") || strcmpi(Command, "neon") || strcmpi(Command, "Ne")) {
			strcpy(Name, "neon");
			Number = 10;
			Group = 18;
			Period = 2;
			strcpy(Formula, "Ne");
			strcpy(Charge, "0");
			Mass = 20.18;
			strcpy(Special, "Noble Gas");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "11") || strcmpi(Command, "sodium") || strcmpi(Command, "Na")) {
			strcpy(Name, "sodium");
			Number = 11;
			Group = 1;
			Period = 3;
			strcpy(Formula, "Na");
			strcpy(Charge, "1+");
			Mass = 22.99;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "12") || strcmpi(Command, "magnesium") || strcmpi(Command, "Mg")) {
			strcpy(Name, "magnesium");
			Number = 12;
			Group = 2;
			Period = 3;
			strcpy(Formula, "Mg");
			strcpy(Charge, "2+");
			Mass = 24.31;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "13") || strcmpi(Command, "aluminum") || strcmpi(Command, "Al")) {
			strcpy(Name, "aluminum");
			Number = 13;
			Group = 13;
			Period = 3;
			strcpy(Formula, "Al");
			strcpy(Charge, "3+");
			Mass = 26.98;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "14") || strcmpi(Command, "silicon") || strcmpi(Command, "Si")) {
			strcpy(Name, "silicon");
			Number = 14;
			Group = 14;
			Period = 3;
			strcpy(Formula, "Si");
			strcpy(Charge, "4+");
			Mass = 28.09;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "15") || strcmpi(Command, "phosphorous") || strcmpi(Command, "P")) {
			strcpy(Name, "phosphorus");
			Number = 15;
			Group = 15;
			Period = 3;
			strcpy(Formula, "P");
			strcpy(Charge, "3-");
			Mass = 30.97;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "16") || strcmpi(Command, "sulfur") || strcmpi(Command, "S")) {
			strcpy(Name, "sulfur");
			Number = 16;
			Group = 16;
			Period = 3;
			strcpy(Formula, "S");
			strcpy(Charge, "2-");
			Mass = 32.06;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "17") || strcmpi(Command, "chlorine") || strcmpi(Command, "Cl")) {
			strcpy(Name, "chlorine");
			Number = 17;
			Group = 17;
			Period = 3;
			strcpy(Formula, "Cl");
			strcpy(Charge, "1-");
			Mass = 35.45;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "18") || strcmpi(Command, "argon") || strcmpi(Command, "Ar")) {
			strcpy(Name, "argon");
			Number = 18;
			Group = 18;
			Period = 3;
			strcpy(Formula, "Ar");
			strcpy(Charge, "0");
			Mass = 39.95;
			strcpy(Special, "Noble Gas");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "19") || strcmpi(Command, "potassium") || strcmpi(Command, "K")) {
			strcpy(Name, "potassium");
			Number = 19;
			Group = 1;
			Period = 4;
			strcpy(Formula, "K");
			strcpy(Charge, "1+");
			Mass = 39.10;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "20") || strcmpi(Command, "calcium") || strcmpi(Command, "Ca")) {
			strcpy(Name, "calcium");
			Number = 20;
			Group = 2;
			Period = 4;
			strcpy(Formula, "Ca");
			strcpy(Charge, "2+");
			Mass = 40.08;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "21") || strcmpi(Command, "scandium") || strcmpi(Command, "Sc")) {
			strcpy(Name, "scandium");
			Number = 21;
			Group = 3;
			Period = 4;
			strcpy(Formula, "Sc");
			strcpy(Charge, "3+");
			Mass = 44.96;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "22") || strcmpi(Command, "titanium") || strcmpi(Command, "Ti")) {
			strcpy(Name, "titanium");
			Number = 22;
			Group = 4;
			Period = 4;
			strcpy(Formula, "Ti");
			strcpy(Charge, "4+ \\ 3+");
			Mass = 47.88;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "23") || strcmpi(Command, "vanadium") || strcmpi(Command, "V")) {
			strcpy(Name, "vanadium");
			Number = 23;
			Group = 5;
			Period = 4;
			strcpy(Formula, "V");
			strcpy(Charge, "5+ \\ 4+");
			Mass = 50.94;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "24") || strcmpi(Command, "chromium") || strcmpi(Command, "Cr")) {
			strcpy(Name, "chromium");
			Number = 24;
			Group = 6;
			Period = 4;
			strcpy(Formula, "Cr");
			strcpy(Charge, "3+ \\ 2+");
			Mass = 52.00;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "25") || strcmpi(Command, "manganese") || strcmpi(Command, "Mn")) {
			strcpy(Name, "manganese");
			Number = 25;
			Group = 7;
			Period = 4;
			strcpy(Formula, "Mn");
			strcpy(Charge, "2+ \\ 4+");
			Mass = 54.94;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "26") || strcmpi(Command, "iron") || strcmpi(Command, "Fe")) {
			strcpy(Name, "iron");
			Number = 26;
			Group = 8;
			Period = 4;
			strcpy(Formula, "Fe");
			strcpy(Charge, "3+ \\ 2+");
			Mass = 55.85;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "27") || strcmpi(Command, "cobalt") || strcmpi(Command, "Co")) {
			strcpy(Name, "cobalt");
			Number = 27;
			Group = 9;
			Period = 4;
			strcpy(Formula, "Co");
			strcpy(Charge, "2+ \\ 3+");
			Mass = 58.93;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "28") || strcmpi(Command, "nickel") || strcmpi(Command, "Ni")) {
			strcpy(Name, "nickel");
			Number = 28;
			Group = 10;
			Period = 4;
			strcpy(Formula, "Ni");
			strcpy(Charge, "2+ \\ 3+");
			Mass = 58.69;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "29") || strcmpi(Command, "copper") || strcmpi(Command, "Cu")) {
			strcpy(Name, "copper");
			Number = 29;
			Group = 11;
			Period = 4;
			strcpy(Formula, "Cu");
			strcpy(Charge, "2+ \\ 1+");
			Mass = 63.55;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "30") || strcmpi(Command, "zinc") || strcmpi(Command, "Zn")) {
			strcpy(Name, "zinc");
			Number = 30;
			Group = 12;
			Period = 4;
			strcpy(Formula, "Zn");
			strcpy(Charge, "2+");
			Mass = 65.38;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "31") || strcmpi(Command, "gallium") || strcmpi(Command, "Ga")) {
			strcpy(Name, "gallium");
			Number = 31;
			Group = 13;
			Period = 4;
			strcpy(Formula, "Ga");
			strcpy(Charge, "3+");
			Mass = 69.72;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "32") || strcmpi(Command, "germanium") || strcmpi(Command, "Ge")) {
			strcpy(Name, "germanium");
			Number = 32;
			Group = 14;
			Period = 4;
			strcpy(Formula, "Ge");
			strcpy(Charge, "4+");
			Mass = 72.61;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "33") || strcmpi(Command, "arsonic") || strcmpi(Command, "As")) {
			strcpy(Name, "arsonic");
			Number = 33;
			Group = 15;
			Period = 4;
			strcpy(Formula, "As");
			strcpy(Charge, "3-");
			Mass = 74.92;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "34") || strcmpi(Command, "selenium") || strcmpi(Command, "Se")) {
			strcpy(Name, "selenium");
			Number = 34;
			Group = 16;
			Period = 4;
			strcpy(Formula, "Se");
			strcpy(Charge, "2-");
			Mass = 78.96;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "35") || strcmpi(Command, "bromine") || strcmpi(Command, "Br")) {
			strcpy(Name, "bromine");
			Number = 35;
			Group = 17;
			Period = 4;
			strcpy(Formula, "Br");
			strcpy(Charge, "1-");
			Mass = 79.90;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "36") || strcmpi(Command, "krypton") || strcmpi(Command, "Kr")) {
			strcpy(Name, "krypton");
			Number = 36;
			Group = 18;
			Period = 4;
			strcpy(Formula, "Kr");
			strcpy(Charge, "0");
			Mass = 83.80;
			strcpy(Special, "Noble Gas");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "37") || strcmpi(Command, "rubidium") || strcmpi(Command, "Rb")) {
			strcpy(Name, "rubidium");
			Number = 37;
			Group = 1;
			Period = 5;
			strcpy(Formula, "Rb");
			strcpy(Charge, "1+");
			Mass = 85.47;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "38") || strcmpi(Command, "stronthum") || strcmpi(Command, "Sr")) {
			strcpy(Name, "stronthum");
			Number = 38;
			Group = 2;
			Period = 5;
			strcpy(Formula, "Sr");
			strcpy(Charge, "2+");
			Mass = 87.62;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "39") || strcmpi(Command, "ythrium") || strcmpi(Command, "Y")) {
			strcpy(Name, "ythrium");
			Number = 39;
			Group = 3;
			Period = 5;
			strcpy(Formula, "Y");
			strcpy(Charge, "3+");
			Mass = 88.91;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "40") || strcmpi(Command, "zirconium") || strcmpi(Command, "Zr")) {
			strcpy(Name, "zirconium");
			Number = 40;
			Group = 4;
			Period = 5;
			strcpy(Formula, "Zr");
			strcpy(Charge, "4+");
			Mass = 91.22;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "41") || strcmpi(Command, "niobium") || strcmpi(Command, "Nb")) {
			strcpy(Name, "niobium");
			Number = 41;
			Group = 5;
			Period = 5;
			strcpy(Formula, "Nb");
			strcpy(Charge, "5+ \\ 3+");
			Mass = 92.91;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "42") || strcmpi(Command, "molybdenum") || strcmpi(Command, "Mo")) {
			strcpy(Name, "molybdenum");
			Number = 42;
			Group = 6;
			Period = 5;
			strcpy(Formula, "Mo");
			strcpy(Charge, "6+");
			Mass = 95.94;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "43") || strcmpi(Command, "techenium") || strcmpi(Command, "Tc")) {
			strcpy(Name, "techenium");
			Number = 43;
			Group = 7;
			Period = 5;
			strcpy(Formula, "Tc");
			strcpy(Charge, "7+");
			Mass = 98.91;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "44") || strcmpi(Command, "ruthenium") || strcmpi(Command, "Ru")) {
			strcpy(Name, "ruthenium");
			Number = 44;
			Group = 8;
			Period = 5;
			strcpy(Formula, "Ru");
			strcpy(Charge, "3+ \\ 4+");
			Mass = 101.07;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "45") || strcmpi(Command, "rhodium") || strcmpi(Command, "Rh")) {
			strcpy(Name, "rhodium");
			Number = 45;
			Group = 9;
			Period = 5;
			strcpy(Formula, "Rh");
			strcpy(Charge, "3+");
			Mass = 102.91;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "46") || strcmpi(Command, "palladium") || strcmpi(Command, "Pd")) {
			strcpy(Name, "palladium");
			Number = 46;
			Group = 10;
			Period = 5;
			strcpy(Formula, "Pd");
			strcpy(Charge, "2+ \\ 4+");
			Mass = 106.42;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "47") || strcmpi(Command, "silver") || strcmpi(Command, "Ag")) {
			strcpy(Name, "silver");
			Number = 47;
			Group = 11;
			Period = 5;
			strcpy(Formula, "Ag");
			strcpy(Charge, "1+");
			Mass = 107.87;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "48") || strcmpi(Command, "cadmium") || strcmpi(Command, "Cd")) {
			strcpy(Name, "cadmium");
			Number = 48;
			Group = 12;
			Period = 5;
			strcpy(Formula, "Cd");
			strcpy(Charge, "2+");
			Mass = 112.41;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "49") || strcmpi(Command, "indium") || strcmpi(Command, "In")) {
			strcpy(Name, "indium");
			Number = 49;
			Group = 13;
			Period = 5;
			strcpy(Formula, "In");
			strcpy(Charge, "3+");
			Mass = 114.82;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "50") || strcmpi(Command, "tin") || strcmpi(Command, "Sn")) {
			strcpy(Name, "tin");
			Number = 50;
			Group = 14;
			Period = 5;
			strcpy(Formula, "Sn");
			strcpy(Charge, "4+ \\ 2+");
			Mass = 118.69;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "51") || strcmpi(Command, "antimony") || strcmpi(Command, "Sb")) {
			strcpy(Name, "antimony");
			Number = 51;
			Group = 15;
			Period = 5;
			strcpy(Formula, "Sb");
			strcpy(Charge, "3+ \\ 5+");
			Mass = 121.75;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "52") || strcmpi(Command, "tellurium") || strcmpi(Command, "Te")) {
			strcpy(Name, "tellurium");
			Number = 52;
			Group = 16;
			Period = 5;
			strcpy(Formula, "Te");
			strcpy(Charge, "2-");
			Mass = 127.60;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "53") || strcmpi(Command, "iodine") || strcmpi(Command, "I")) {
			strcpy(Name, "iodine");
			Number = 53;
			Group = 17;
			Period = 5;
			strcpy(Formula, "I");
			strcpy(Charge, "1-");
			Mass = 126.90;
			strcpy(Special, "Diatomic");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "54") || strcmpi(Command, "xenon") || strcmpi(Command, "Xe")) {
			strcpy(Name, "xenon");
			Number = 54;
			Group = 18;
			Period = 5;
			strcpy(Formula, "Xe");
			strcpy(Charge, "0");
			Mass = 131.29;
			strcpy(Special, "Noble Gas");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "55") || strcmpi(Command, "cosium") || strcmpi(Command, "Cs")) {
			strcpy(Name, "cosiumn");
			Number = 55;
			Group = 1;
			Period = 6;
			strcpy(Formula, "Cs");
			strcpy(Charge, "1+");
			Mass = 132.91;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "56") || strcmpi(Command, "barium") || strcmpi(Command, "Ba")) {
			strcpy(Name, "barium");
			Number = 56;
			Group = 2;
			Period = 6;
			strcpy(Formula, "Ba");
			strcpy(Charge, "2+");
			Mass = 137.33;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "57") || strcmpi(Command, "lanthanum") || strcmpi(Command, "La")) {
			strcpy(Name, "lanthanum");
			Number = 57;
			Group = 3;
			Period = 6;
			strcpy(Formula, "La");
			strcpy(Charge, "3+");
			Mass = 138.91;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "58") || strcmpi(Command, "cerium") || strcmpi(Command, "Ce")) {
			strcpy(Name, "cerium");
			Number = 58;
			Group = 5;
			Period = 6;
			strcpy(Formula, "Ce");
			strcpy(Charge, "3+");
			Mass = 140.12;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "59") || strcmpi(Command, "pruseodymium") || strcmpi(Command, "Pr")) {
			strcpy(Name, "pruseodymium");
			Number = 59;
			Group = 6;
			Period = 6;
			strcpy(Formula, "Pr");
			strcpy(Charge, "3+");
			Mass = 140.91;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "60") || strcmpi(Command, "neodymium") || strcmpi(Command, "Nd")) {
			strcpy(Name, "neodymium");
			Number = 60;
			Group = 7;
			Period = 6;
			strcpy(Formula, "Nd");
			strcpy(Charge, "3+");
			Mass = 144.24;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "61") || strcmpi(Command, "promethium") || strcmpi(Command, "Pm")) {
			strcpy(Name, "promethium");
			Number = 61;
			Group = 8;
			Period = 6;
			strcpy(Formula, "Pm");
			strcpy(Charge, "3+");
			Mass = 145;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "62") || strcmpi(Command, "samarium") || strcmpi(Command, "Sm")) {
			strcpy(Name, "samarium");
			Number = 62;
			Group = 9;
			Period = 6;
			strcpy(Formula, "Sm");
			strcpy(Charge, "3+ \\ 2+");
			Mass = 150.40;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "63") || strcmpi(Command, "europium") || strcmpi(Command, "Eu")) {
			strcpy(Name, "europium");
			Number = 63;
			Group = 10;
			Period = 6;
			strcpy(Formula, "Eu");
			strcpy(Charge, "3+ \\ 2+");
			Mass = 151.97;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "64") || strcmpi(Command, "gadolinium") || strcmpi(Command, "Gd")) {
			strcpy(Name, "gadolinium");
			Number = 64;
			Group = 11;
			Period = 6;
			strcpy(Formula, "Gd");
			strcpy(Charge, "3+");
			Mass = 157.25;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "65") || strcmpi(Command, "terbium") || strcmpi(Command, "Tb")) {
			strcpy(Name, "terbium");
			Number = 65;
			Group = 12;
			Period = 6;
			strcpy(Formula, "Tb");
			strcpy(Charge, "3+");
			Mass = 158.93;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "66") || strcmpi(Command, "dysprosium") || strcmpi(Command, "Dy")) {
			strcpy(Name, "dysprosium");
			Number = 66;
			Group = 13;
			Period = 6;
			strcpy(Formula, "Dy");
			strcpy(Charge, "3+");
			Mass = 162.50;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "67") || strcmpi(Command, "helmium") || strcmpi(Command, "Ho")) {
			strcpy(Name, "helmium");
			Number = 67;
			Group = 14;
			Period = 6;
			strcpy(Formula, "Ho");
			strcpy(Charge, "3+");
			Mass = 164.93;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "68") || strcmpi(Command, "erbium") || strcmpi(Command, "Er")) {
			strcpy(Name, "erbium");
			Number = 68;
			Group = 15;
			Period = 6;
			strcpy(Formula, "Er");
			strcpy(Charge, "3+");
			Mass = 167.26;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "69") || strcmpi(Command, "thulium") || strcmpi(Command, "Tm")) {
			strcpy(Name, "thulium");
			Number = 69;
			Group = 16;
			Period = 6;
			strcpy(Formula, "Tm");
			strcpy(Charge, "3+");
			Mass = 168.94;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "70") || strcmpi(Command, "ytlerhium") || strcmpi(Command, "Yb")) {
			strcpy(Name, "ytlerhium");
			Number = 70;
			Group = 17;
			Period = 6;
			strcpy(Formula, "Yb");
			strcpy(Charge, "3+ \\ 2+");
			Mass = 173.04;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "71") || strcmpi(Command, "lutelium") || strcmpi(Command, "Lu")) {
			strcpy(Name, "lutelium");
			Number = 71;
			Group = 18;
			Period = 6;
			strcpy(Formula, "Lu");
			strcpy(Charge, "3+");
			Mass = 174.97;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "72") || strcmpi(Command, "hefnium") || strcmpi(Command, "Hf")) {
			strcpy(Name, "hefnium");
			Number = 72;
			Group = 4;
			Period = 6;
			strcpy(Formula, "Hf");
			strcpy(Charge, "4+");
			Mass = 178.49;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "73") || strcmpi(Command, "tantalum") || strcmpi(Command, "Ta")) {
			strcpy(Name, "tantalum");
			Number = 73;
			Group = 5;
			Period = 6;
			strcpy(Formula, "Ta");
			strcpy(Charge, "5+");
			Mass = 180.95;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "74") || strcmpi(Command, "wolfrum") || strcmpi(Command, "tungsten") || strcmpi(Command, "W")) {
			strcpy(Name, "wolfrum (tungsten)");
			Number = 74;
			Group = 6;
			Period = 6;
			strcpy(Formula, "W");
			strcpy(Charge, "6+");
			Mass = 183.85;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "75") || strcmpi(Command, "rhenium") || strcmpi(Command, "Re")) {
			strcpy(Name, "rhenium");
			Number = 75;
			Group = 7;
			Period = 6;
			strcpy(Formula, "Re");
			strcpy(Charge, "7+");
			Mass = 186.21;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "76") || strcmpi(Command, "osmium") || strcmpi(Command, "Os")) {
			strcpy(Name, "osmium");
			Number = 76;
			Group = 8;
			Period = 6;
			strcpy(Formula, "Os");
			strcpy(Charge, "4+");
			Mass = 190.2;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "77") || strcmpi(Command, "iridium") || strcmpi(Command, "Ir")) {
			strcpy(Name, "iridium");
			Number = 77;
			Group = 9;
			Period = 6;
			strcpy(Formula, "Ir");
			strcpy(Charge, "4+");
			Mass = 192.22;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "78") || strcmpi(Command, "platinum") || strcmpi(Command, "Pt")) {
			strcpy(Name, "platinum");
			Number = 78;
			Group = 10;
			Period = 6;
			strcpy(Formula, "Pt");
			strcpy(Charge, "4+ \\ 2+");
			Mass = 195.08;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "79") || strcmpi(Command, "gold") || strcmpi(Command, "Au")) {
			strcpy(Name, "gold");
			Number = 79;
			Group = 11;
			Period = 6;
			strcpy(Formula, "Au");
			strcpy(Charge, "3+ \\ 1+");
			Mass = 196.97;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "80") || strcmpi(Command, "mercury") || strcmpi(Command, "Mg")) {
			strcpy(Name, "mercury");
			Number = 80;
			Group = 12;
			Period = 6;
			strcpy(Formula, "Hg");
			strcpy(Charge, "2+ \\ 1+");
			Mass = 200.59;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "81") || strcmpi(Command, "thallium") || strcmpi(Command, "Tl")) {
			strcpy(Name, "thallium");
			Number = 81;
			Group = 13;
			Period = 6;
			strcpy(Formula, "Tl");
			strcpy(Charge, "1+ \\ 3+");
			Mass = 204.38;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "82") || strcmpi(Command, "lead") || strcmpi(Command, "Pb")) {
			strcpy(Name, "lead");
			Number = 82;
			Group = 14;
			Period = 6;
			strcpy(Formula, "Pb");
			strcpy(Charge, "2+ \\ 4+");
			Mass = 207.20;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "83") || strcmpi(Command, "bismuth") || strcmpi(Command, "Bi")) {
			strcpy(Name, "bismuth");
			Number = 83;
			Group = 15;
			Period = 6;
			strcpy(Formula, "Bi");
			strcpy(Charge, "3+ \\ 5+");
			Mass = 208.98;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "84") || strcmpi(Command, "polonium") || strcmpi(Command, "Po")) {
			strcpy(Name, "polonium");
			Number = 84;
			Group = 16;
			Period = 6;
			strcpy(Formula, "Po");
			strcpy(Charge, "2+ \\ 4+");
			Mass = 209;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "85") || strcmpi(Command, "asiatine") || strcmpi(Command, "At")) {
			strcpy(Name, "asiatine");
			Number = 85;
			Group = 17;
			Period = 6;
			strcpy(Formula, "At");
			strcpy(Charge, "1-");
			Mass = 210;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "86") || strcmpi(Command, "radon") || strcmpi(Command, "Rn")) {
			strcpy(Name, "radon");
			Number = 86;
			Group = 18;
			Period = 6;
			strcpy(Formula, "Rn");
			strcpy(Charge, "0");
			Mass = 222;
			strcpy(Special, "Noble Gas");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "87") || strcmpi(Command, "fruncium") || strcmpi(Command, "Fr")) {
			strcpy(Name, "fruncium");
			Number = 87;
			Group = 1;
			Period = 7;
			strcpy(Formula, "Fr");
			strcpy(Charge, "1+");
			Mass = 223;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "88") || strcmpi(Command, "radium") || strcmpi(Command, "Ra")) {
			strcpy(Name, "radium");
			Number = 88;
			Group = 2;
			Period = 7;
			strcpy(Formula, "Ra");
			strcpy(Charge, "2+");
			Mass = 226.03;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "89") || strcmpi(Command, "actinium") || strcmpi(Command, "Ac")) {
			strcpy(Name, "actinium");
			Number = 89;
			Group = 3;
			Period = 7;
			strcpy(Formula, "Ac");
			strcpy(Charge, "3+");
			Mass = 227.03;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "90") || strcmpi(Command, "thorlum") || strcmpi(Command, "Th")) {
			strcpy(Name, "thorlum");
			Number = 90;
			Group = 5;
			Period = 7;
			strcpy(Formula, "Th");
			strcpy(Charge, "4+");
			Mass = 232.04;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "91") || strcmpi(Command, "protactinium") || strcmpi(Command, "Pa")) {
			strcpy(Name, "protactinium");
			Number = 91;
			Group = 6;
			Period = 7;
			strcpy(Formula, "Pa");
			strcpy(Charge, "5+ \\ 4+");
			Mass = 231.04;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "92") || strcmpi(Command, "uranium") || strcmpi(Command, "U")) {
			strcpy(Name, "uranium");
			Number = 92;
			Group = 7;
			Period = 7;
			strcpy(Formula, "U");
			strcpy(Charge, "6+ \\ 4+");
			Mass = 238.03;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "93") || strcmpi(Command, "neplunium") || strcmpi(Command, "Np")) {
			strcpy(Name, "neplunium");
			Number = 93;
			Group = 8;
			Period = 7;
			strcpy(Formula, "Np");
			strcpy(Charge, "5+");
			Mass = 237.05;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "94") || strcmpi(Command, "plutonium") || strcmpi(Command, "Pu")) {
			strcpy(Name, "plutonium");
			Number = 94;
			Group = 9;
			Period = 7;
			strcpy(Formula, "Pu");
			strcpy(Charge, "4+ \\ 6+");
			Mass = 244;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "95") || strcmpi(Command, "americium") || strcmpi(Command, "Am")) {
			strcpy(Name, "americium");
			Number = 95;
			Group = 10;
			Period = 7;
			strcpy(Formula, "Am");
			strcpy(Charge, "3+ \\ 4+");
			Mass = 244;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "96") || strcmpi(Command, "curium") || strcmpi(Command, "Cm")) {
			strcpy(Name, "curium");
			Number = 96;
			Group = 11;
			Period = 7;
			strcpy(Formula, "Cm");
			strcpy(Charge, "3+");
			Mass = 247;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "97") || strcmpi(Command, "borkelium") || strcmpi(Command, "Bk")) {
			strcpy(Name, "borkelium");
			Number = 97;
			Group = 12;
			Period = 7;
			strcpy(Formula, "Bk");
			strcpy(Charge, "3+ \\ 4+");
			Mass = 247;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "98") || strcmpi(Command, "californium") || strcmpi(Command, "Cf")) {
			strcpy(Name, "californium");
			Number = 98;
			Group = 13;
			Period = 7;
			strcpy(Formula, "Cf");
			strcpy(Charge, "3+");
			Mass = 251;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "99") || strcmpi(Command, "einsteinium") || strcmpi(Command, "Es")) {
			strcpy(Name, "einsteinium");
			Number = 99;
			Group = 14;
			Period = 7;
			strcpy(Formula, "Es");
			strcpy(Charge, "3+");
			Mass = 252;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "100") || strcmpi(Command, "formium") || strcmpi(Command, "Fm")) {
			strcpy(Name, "formium");
			Number = 100;
			Group = 15;
			Period = 7;
			strcpy(Formula, "Fm");
			strcpy(Charge, "3+");
			Mass = 257;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "101") || strcmpi(Command, "mendelevium") || strcmpi(Command, "Md")) {
			strcpy(Name, "mendelevium");
			Number = 101;
			Group = 16;
			Period = 7;
			strcpy(Formula, "Md");
			strcpy(Charge, "2+ \\ 3+");
			Mass = 258;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "102") || strcmpi(Command, "nebelium") || strcmpi(Command, "No")) {
			strcpy(Name, "nebelium");
			Number = 102;
			Group = 17;
			Period = 7;
			strcpy(Formula, "No");
			strcpy(Charge, "2+ \\ 3+");
			Mass = 259;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		else if (strcmpi(Command, "103") || strcmpi(Command, "lawrencium") || strcmpi(Command, "Lr")) {
			strcpy(Name, "lawrencium");
			Number = 103;
			Group = 18;
			Period = 7;
			strcpy(Formula, "Lr");
			strcpy(Charge, "3+");
			Mass = 260;
			strcpy(Special, "None");
			Table(Name, Number, Group, Period, Formula, Charge, Mass, Neutrons, Special);
		}
		//---------------------------------------------------------------------------
		else {
			if (!(strcmpi(Command, "Quit") && strcmpi(Command, "QUIT") && strcmpi(Command, "quit"))) {
				cout << "Unrecognized Command.\n";
			}
		}
	} while (strcmpi(Command, "Quit") && strcmpi(Command, "QUIT") && strcmpi(Command, "quit"));
	Color = 8 + rand()%8;
	/*if (Color == 1) {
		textcolor(RED);
	}
	else if (Color == 2) {
		textcolor(MAGENTA);
	}
	else if (Color == 3) {
		textcolor(BLUE);
	}
	else if (Color == 4) {
		textcolor(GREEN);
	}
	else if (Color == 5) {
		textcolor(WHITE);
	}
	else if (Color == 6) {
		textcolor(YELLOW);
	}
	else if (Color == 7) {
		textcolor(BROWN);
	}
	else if (Color == 8) {
		textcolor(CYAN);
	}
	textbackground(BLACK);
	*/
	clear_screen();
	gotoxy(1, 2);
	return (0);
}
// END OF Table.cpp