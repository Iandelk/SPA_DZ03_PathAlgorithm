#include<iostream>
#include<string>
#include "igra.h"

using namespace std;


int main() {

	igra game;
	game.inicijalizacija();
	game.print();
	game.kretanje_stupci();
	game.kretanje_redci();



	return 0;
}