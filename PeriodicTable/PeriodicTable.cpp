/*  Period Table Program
*/
#include <iostream.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <string.h>
//---------------------------------------------------------------------------
void Table(char Name[], double Number, int Group, int Period, char Formula[], char Charge[], double Mass, int Neutrons, char Special[])
{
	Neutrons = (Mass - Number);
	clrscr();
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
	getch();
	clrscr();
	gotoxy(1, 2);
}
//---------------------------------------------------------------------------
void Help()
{
	clrscr();
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
	getch();
	clrscr();
	gotoxy(1, 2);
}
//---------------------------------------------------------------------------
void Credits()
{
	char CreditsKey;
	clrscr();
	gotoxy(1, 2);
	cout << "CREDITS\n\n";
	cout << "I made the PERIODIC TABLE program near the end of 2000. I\n";
	cout << "had just discovered the world of C++ program, and was eager\n";
	cout << "to test it out. This is the result.\n";
	cout << "I have always enjoyed chemistry, and so it was no surprise to\n";
	cout << "me when a periodic table program was the first idea that\n";
	cout << "popped into my head.\n";
	cout << "I hope you have all enjoyed the program as an educational tool.\n";
	cout << "Enjoy the program, use it often, and my vision will be fufilled.\n\n";
	cout << "\tProgrammed by Carlo (completed 2001)\n";
	getch();
	clrscr();
	gotoxy(1, 2);
}
//---------------------------------------------------------------------------
void Prefix()
{
	clrscr();
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
	getch();
	clrscr();
	gotoxy(1, 2);
}
//---------------------------------------------------------------------------
int main()
{
	randomize();
	//Wait();
	int Color = 1 + random(8);
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
	clrscr();
	gotoxy(1, 11);
	cout << "\a\t\t\t       PERIODIC TABLE         \n";
	cout << "\a\t\t\t   *--------------------*     \n";
	cout << endl;
	cout << "\a\t\t\t      Program by Carlo        \n";
	cout << "\a\t\t\t          c.  2001            \n";
	gotoxy(35, 15);
	getch();
	textcolor(WHITE);
	textbackground(BLUE);
	clrscr();
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
		Neutrons,
		Number;
	//---------------------------------------------------------------------------
	do
	{
		cout << "Command: ";
		cin >> Command;
		if (strcmp(Command, "Help") || strcmp(Command, "HELP") || strcmp(Command, "help")) {
			Help();
		}
		else if (strcmp(Command, "Credits") || strcmp(Command, "CREDITS") || strcmp(Command, "credits")) {
			Credits();
		}
		else if (strcmp(Command, "Clear") || strcmp(Command, "CLEAR") || strcmp(Command, "clear")) {
			clrscr();
			gotoxy(1, 2);
		}
		else if (strcmp(Command, "Prefix") || strcmp(Command, "PREFIX") || strcmp(Command, "prefix")) {
			Prefix();
		}
		//---------------------------------------------------------------------------
		else if (strcmp(Command, "1") || strcmp(Command, "hydrogen") || strcmp(Command, "H")) {
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
		else if (strcmp(Command, "2") || strcmp(Command, "helium") || strcmp(Command, "He")) {
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
		else if (strcmp(Command, "3") || strcmp(Command, "lithium") || strcmp(Command, "Li")) {
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
		else if (strcmp(Command, "4") || strcmp(Command, "beryllium") || strcmp(Command, "Be")) {
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
		else if (strcmp(Command, "5") || strcmp(Command, "boron") || strcmp(Command, "B")) {
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
		else if (strcmp(Command, "6") || strcmp(Command, "carbon") || strcmp(Command, "C")) {
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
		else if (strcmp(Command, "7") || strcmp(Command, "nitrogen") || strcmp(Command, "N")) {
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
		else if (strcmp(Command, "8") || strcmp(Command, "oxygen") || strcmp(Command, "O")) {
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
		else if (strcmp(Command, "9") || strcmp(Command, "flourine") || strcmp(Command, "F")) {
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
		else if (strcmp(Command, "10") || strcmp(Command, "neon") || strcmp(Command, "Ne")) {
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
		else if (strcmp(Command, "11") || strcmp(Command, "sodium") || strcmp(Command, "Na")) {
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
		else if (strcmp(Command, "12") || strcmp(Command, "magnesium") || strcmp(Command, "Mg")) {
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
		else if (strcmp(Command, "13") || strcmp(Command, "aluminum") || strcmp(Command, "Al")) {
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
		else if (strcmp(Command, "14") || strcmp(Command, "silicon") || strcmp(Command, "Si")) {
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
		else if (strcmp(Command, "15") || strcmp(Command, "phosphorous") || strcmp(Command, "P")) {
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
		else if (strcmp(Command, "16") || strcmp(Command, "sulfur") || strcmp(Command, "S")) {
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
		else if (strcmp(Command, "17") || strcmp(Command, "chlorine") || strcmp(Command, "Cl")) {
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
		else if (strcmp(Command, "18") || strcmp(Command, "argon") || strcmp(Command, "Ar")) {
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
		else if (strcmp(Command, "19") || strcmp(Command, "potassium") || strcmp(Command, "K")) {
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
		else if (strcmp(Command, "20") || strcmp(Command, "calcium") || strcmp(Command, "Ca")) {
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
		else if (strcmp(Command, "21") || strcmp(Command, "scandium") || strcmp(Command, "Sc")) {
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
		else if (strcmp(Command, "22") || strcmp(Command, "titanium") || strcmp(Command, "Ti")) {
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
		else if (strcmp(Command, "23") || strcmp(Command, "vanadium") || strcmp(Command, "V")) {
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
		else if (strcmp(Command, "24") || strcmp(Command, "chromium") || strcmp(Command, "Cr")) {
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
		else if (strcmp(Command, "25") || strcmp(Command, "manganese") || strcmp(Command, "Mn")) {
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
		else if (strcmp(Command, "26") || strcmp(Command, "iron") || strcmp(Command, "Fe")) {
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
		else if (strcmp(Command, "27") || strcmp(Command, "cobalt") || strcmp(Command, "Co")) {
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
		else if (strcmp(Command, "28") || strcmp(Command, "nickel") || strcmp(Command, "Ni")) {
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
		else if (strcmp(Command, "29") || strcmp(Command, "copper") || strcmp(Command, "Cu")) {
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
		else if (strcmp(Command, "30") || strcmp(Command, "zinc") || strcmp(Command, "Zn")) {
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
		else if (strcmp(Command, "31") || strcmp(Command, "gallium") || strcmp(Command, "Ga")) {
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
		else if (strcmp(Command, "32") || strcmp(Command, "germanium") || strcmp(Command, "Ge")) {
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
		else if (strcmp(Command, "33") || strcmp(Command, "arsonic") || strcmp(Command, "As")) {
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
		else if (strcmp(Command, "34") || strcmp(Command, "selenium") || strcmp(Command, "Se")) {
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
		else if (strcmp(Command, "35") || strcmp(Command, "bromine") || strcmp(Command, "Br")) {
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
		else if (strcmp(Command, "36") || strcmp(Command, "krypton") || strcmp(Command, "Kr")) {
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
		else if (strcmp(Command, "37") || strcmp(Command, "rubidium") || strcmp(Command, "Rb")) {
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
		else if (strcmp(Command, "38") || strcmp(Command, "stronthum") || strcmp(Command, "Sr")) {
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
		else if (strcmp(Command, "39") || strcmp(Command, "ythrium") || strcmp(Command, "Y")) {
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
		else if (strcmp(Command, "40") || strcmp(Command, "zirconium") || strcmp(Command, "Zr")) {
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
		else if (strcmp(Command, "41") || strcmp(Command, "niobium") || strcmp(Command, "Nb")) {
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
		else if (strcmp(Command, "42") || strcmp(Command, "molybdenum") || strcmp(Command, "Mo")) {
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
		else if (strcmp(Command, "43") || strcmp(Command, "techenium") || strcmp(Command, "Tc")) {
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
		else if (strcmp(Command, "44") || strcmp(Command, "ruthenium") || strcmp(Command, "Ru")) {
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
		else if (strcmp(Command, "45") || strcmp(Command, "rhodium") || strcmp(Command, "Rh")) {
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
		else if (strcmp(Command, "46") || strcmp(Command, "palladium") || strcmp(Command, "Pd")) {
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
		else if (strcmp(Command, "47") || strcmp(Command, "silver") || strcmp(Command, "Ag")) {
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
		else if (strcmp(Command, "48") || strcmp(Command, "cadmium") || strcmp(Command, "Cd")) {
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
		else if (strcmp(Command, "49") || strcmp(Command, "indium") || strcmp(Command, "In")) {
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
		else if (strcmp(Command, "50") || strcmp(Command, "tin") || strcmp(Command, "Sn")) {
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
		else if (strcmp(Command, "51") || strcmp(Command, "antimony") || strcmp(Command, "Sb")) {
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
		else if (strcmp(Command, "52") || strcmp(Command, "tellurium") || strcmp(Command, "Te")) {
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
		else if (strcmp(Command, "53") || strcmp(Command, "iodine") || strcmp(Command, "I")) {
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
		else if (strcmp(Command, "54") || strcmp(Command, "xenon") || strcmp(Command, "Xe")) {
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
		else if (strcmp(Command, "55") || strcmp(Command, "cosium") || strcmp(Command, "Cs")) {
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
		else if (strcmp(Command, "56") || strcmp(Command, "barium") || strcmp(Command, "Ba")) {
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
		else if (strcmp(Command, "57") || strcmp(Command, "lanthanum") || strcmp(Command, "La")) {
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
		else if (strcmp(Command, "58") || strcmp(Command, "cerium") || strcmp(Command, "Ce")) {
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
		else if (strcmp(Command, "59") || strcmp(Command, "pruseodymium") || strcmp(Command, "Pr")) {
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
		else if (strcmp(Command, "60") || strcmp(Command, "neodymium") || strcmp(Command, "Nd")) {
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
		else if (strcmp(Command, "61") || strcmp(Command, "promethium") || strcmp(Command, "Pm")) {
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
		else if (strcmp(Command, "62") || strcmp(Command, "samarium") || strcmp(Command, "Sm")) {
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
		else if (strcmp(Command, "63") || strcmp(Command, "europium") || strcmp(Command, "Eu")) {
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
		else if (strcmp(Command, "64") || strcmp(Command, "gadolinium") || strcmp(Command, "Gd")) {
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
		else if (strcmp(Command, "65") || strcmp(Command, "terbium") || strcmp(Command, "Tb")) {
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
		else if (strcmp(Command, "66") || strcmp(Command, "dysprosium") || strcmp(Command, "Dy")) {
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
		else if (strcmp(Command, "67") || strcmp(Command, "helmium") || strcmp(Command, "Ho")) {
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
		else if (strcmp(Command, "68") || strcmp(Command, "erbium") || strcmp(Command, "Er")) {
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
		else if (strcmp(Command, "69") || strcmp(Command, "thulium") || strcmp(Command, "Tm")) {
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
		else if (strcmp(Command, "70") || strcmp(Command, "ytlerhium") || strcmp(Command, "Yb")) {
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
		else if (strcmp(Command, "71") || strcmp(Command, "lutelium") || strcmp(Command, "Lu")) {
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
		else if (strcmp(Command, "72") || strcmp(Command, "hefnium") || strcmp(Command, "Hf")) {
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
		else if (strcmp(Command, "73") || strcmp(Command, "tantalum") || strcmp(Command, "Ta")) {
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
		else if (strcmp(Command, "74") || strcmp(Command, "wolfrum") || strcmp(Command, "tungsten") || strcmp(Command, "W")) {
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
		else if (strcmp(Command, "75") || strcmp(Command, "rhenium") || strcmp(Command, "Re")) {
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
		else if (strcmp(Command, "76") || strcmp(Command, "osmium") || strcmp(Command, "Os")) {
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
		else if (strcmp(Command, "77") || strcmp(Command, "iridium") || strcmp(Command, "Ir")) {
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
		else if (strcmp(Command, "78") || strcmp(Command, "platinum") || strcmp(Command, "Pt")) {
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
		else if (strcmp(Command, "79") || strcmp(Command, "gold") || strcmp(Command, "Au")) {
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
		else if (strcmp(Command, "80") || strcmp(Command, "mercury") || strcmp(Command, "Mg")) {
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
		else if (strcmp(Command, "81") || strcmp(Command, "thallium") || strcmp(Command, "Tl")) {
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
		else if (strcmp(Command, "82") || strcmp(Command, "lead") || strcmp(Command, "Pb")) {
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
		else if (strcmp(Command, "83") || strcmp(Command, "bismuth") || strcmp(Command, "Bi")) {
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
		else if (strcmp(Command, "84") || strcmp(Command, "polonium") || strcmp(Command, "Po")) {
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
		else if (strcmp(Command, "85") || strcmp(Command, "asiatine") || strcmp(Command, "At")) {
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
		else if (strcmp(Command, "86") || strcmp(Command, "radon") || strcmp(Command, "Rn")) {
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
		else if (strcmp(Command, "87") || strcmp(Command, "fruncium") || strcmp(Command, "Fr")) {
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
		else if (strcmp(Command, "88") || strcmp(Command, "radium") || strcmp(Command, "Ra")) {
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
		else if (strcmp(Command, "89") || strcmp(Command, "actinium") || strcmp(Command, "Ac")) {
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
		else if (strcmp(Command, "90") || strcmp(Command, "thorlum") || strcmp(Command, "Th")) {
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
		else if (strcmp(Command, "91") || strcmp(Command, "protactinium") || strcmp(Command, "Pa")) {
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
		else if (strcmp(Command, "92") || strcmp(Command, "uranium") || strcmp(Command, "U")) {
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
		else if (strcmp(Command, "93") || strcmp(Command, "neplunium") || strcmp(Command, "Np")) {
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
		else if (strcmp(Command, "94") || strcmp(Command, "plutonium") || strcmp(Command, "Pu")) {
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
		else if (strcmp(Command, "95") || strcmp(Command, "americium") || strcmp(Command, "Am")) {
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
		else if (strcmp(Command, "96") || strcmp(Command, "curium") || strcmp(Command, "Cm")) {
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
		else if (strcmp(Command, "97") || strcmp(Command, "borkelium") || strcmp(Command, "Bk")) {
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
		else if (strcmp(Command, "98") || strcmp(Command, "californium") || strcmp(Command, "Cf")) {
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
		else if (strcmp(Command, "99") || strcmp(Command, "einsteinium") || strcmp(Command, "Es")) {
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
		else if (strcmp(Command, "100") || strcmp(Command, "formium") || strcmp(Command, "Fm")) {
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
		else if (strcmp(Command, "101") || strcmp(Command, "mendelevium") || strcmp(Command, "Md")) {
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
		else if (strcmp(Command, "102") || strcmp(Command, "nebelium") || strcmp(Command, "No")) {
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
		else if (strcmp(Command, "103") || strcmp(Command, "lawrencium") || strcmp(Command, "Lr")) {
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
			if (strcmpi(Command) != "Quit") && strcmpi(Command) != "QUIT") && strcmpi(Command) != "quit")) {
			cout << "Unrecognized strcmpi(Command).\n");
			}
		}
	} while (strcmpi(Command) != "Quit") && strcmpi(Command) != "QUIT") && strcmpi(Command) != "quit"));
	Color = 1 + random(8);
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
	textbackground(BLACK);
	clrscr();
	gotoxy(1, 2);
	return (0);
}
// END OF Table.cpp