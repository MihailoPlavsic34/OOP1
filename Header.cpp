#include "Header.h"
#include <iostream>
using namespace std;

Red::Red() {
	pop = 0;
	poc = kraj = new Ceo; // poziva default konstruktor Ceo?		
}

Red::~Red() {
	while (poc != nullptr) {
		Ceo* tek = poc;
		poc = poc->sledeci();
		delete tek;
	}
	pop = 0;
}

Red::Red(Red& const Red) { 
	pop = Red.pop;
	if (pop == 0) poc = kraj = nullptr;
	Ceo* tek = Red.poc;
	while (tek != nullptr) {
		kraj =((pop<1)? poc = new Ceo(tek->broj(), tek->sledeci()) : new Ceo(tek->broj(), tek->sledeci()));
		tek = tek->sledeci();
	}
}

Red::Red(Red&& Red) {
	pop = Red.pop;
	poc = Red.poc;
	kraj = Red.kraj;
	Red.poc = Red.kraj = nullptr;
}


void Red::dodaj() {
	int n; cin >> n;
	if (pop == 0) { poc->Ceo::promeni(n); ++pop; }
	else { Ceo* tek = kraj;
	kraj = new Ceo(n, nullptr);
	tek->Ceo::promeni(kraj);
	++pop; }
}

int Red::uzmi() {
	--pop;
	if (pop == 0 || pop < 0) { cout << "Greska! lista je prazna! \n"; pop = 0; exit(0); }
	Ceo* tek = poc;
	poc = (poc->Ceo::sledeci());
	return tek->Ceo::broj();
	delete tek;
}

void const Red::pisi() {
	Ceo* tek = poc;
	while (tek != nullptr) {
		string c = ((tek->sledeci() != nullptr)? "->" : "\n");
		cout << tek->broj(); cout << c;
		tek = tek->sledeci();
	}
}

int const Red::brelem() {
	cout << "\nBroj elemenata niza je: "; return pop; cout << "\n" ;
}
