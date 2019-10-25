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
	Red.pop = pop;
	if (pop == 0) Red.poc = Red.kraj = nullptr;
	Ceo* tek = poc;
	while (tek != nullptr) {
		if (pop == 0) Red.poc = poc;
		Red.kraj =((pop<1)? Red.poc = new Ceo(tek->broj(), tek->sledeci()) : new Ceo(tek->broj(), tek->sledeci()));
	}
}

Red::Red(Red&& Red) {
	Red.pop = pop;
	Red.poc = poc;
	Red.kraj = kraj;
	poc = kraj = nullptr;
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
		cout << tek->broj();
		tek = tek->sledeci();
	}
}

int const Red::brelem() {
	cout << "\nBroj elemenata niza je: "; return pop; cout << "\n" ;
}
