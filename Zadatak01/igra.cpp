#include "igra.h"
#include<iostream>
#include<Windows.h>



igra::igra()
{
	cout << "A redak: ";
	cin >> a_redak;
	cout << "A stupac: ";
	cin >> a_stupac;
	cout << "B redak: ";
	cin >> b_redak;
	cout << "B stupac: ";
	cin >> b_stupac;

	a_redak--;
	a_stupac--;
	b_redak--;
	b_stupac--;
	if (a_stupac < b_stupac) lijevo_desno = true; else lijevo_desno = false;
	if (a_redak < b_redak)gore_dolje = true; else gore_dolje = false;
}

void igra::inicijalizacija()
{

	for (int i = 0; i < REDCI; i++) {
		for (int j = 0; j < STUPCI; j++) {

		
			 ploca[i][j] = '-';

		}

	}
	ploca[a_redak][a_stupac] = 'A';
	ploca[b_redak][b_stupac] = 'B';
}

void igra::print()
{



	for (int i = 0; i < REDCI; i++) {
		for (int j = 0; j < STUPCI; j++) {

			cout << ploca[i][j];

		}

		cout << endl;

	}


}

void igra::kretanje_stupci()
{
	x_redak = a_redak;
	x_stupac = a_stupac;

	if (lijevo_desno)
	{
		
		while (x_stupac != b_stupac) {

			
			x_stupac++;
			
			if(ploca[x_redak][x_stupac - 1] != 'A')	ploca[x_redak][x_stupac - 1] = '-';
			
			
			
			ploca[x_redak][x_stupac] = 'X';

			
			Sleep(100);
			system("CLS");
			print();

		}
	
	}
	else {
		while (x_stupac != b_stupac) {

	

			x_stupac--;

			if (ploca[x_redak][x_stupac + 1] != 'A')ploca[x_redak][x_stupac + 1] = '-';
			ploca[x_redak][x_stupac] = 'X';

			
			Sleep(100);
			system("CLS");
			print();

		}

	}
}

void igra::kretanje_redci()
{

	if (gore_dolje)
	{
		
		while (x_redak != b_redak) {

			x_redak++;

			if (ploca[x_redak-1][x_stupac] != 'A')ploca[x_redak-1][x_stupac] = '-';
			ploca[x_redak][x_stupac] = 'X';

			
			Sleep(100);
			system("CLS");

			print();

		}
	}
	else {
		while (x_redak != b_redak) {

			x_redak--;

			if (ploca[x_redak + 1][x_stupac] != 'A')ploca[x_redak+1][x_stupac] = '-';
			ploca[x_redak][x_stupac] = 'X';


			Sleep(100);
			system("CLS");

			print();

		}

	}

}
