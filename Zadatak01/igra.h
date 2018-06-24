#pragma once

#include <string>;

using namespace std;

class igra
{
private:
	static const int STUPCI = 40;
	static const int REDCI = 20;
	char ploca[REDCI][STUPCI];
	int a_redak;
	int a_stupac;
	int b_redak;
	int	b_stupac;
	int x_stupac;
	int x_redak;
	bool lijevo_desno;
	bool gore_dolje;

public:
	igra();
	void inicijalizacija();
	void print();
	void kretanje_stupci();
	void kretanje_redci();
};

