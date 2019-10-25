#include <iostream>
#include "Header.h"
using namespace std;

int main() {
	Red* R = new Red; //napravi prazan red

	
	cout << "\n 1 za unos elemenata read " << "\n 2 za uzimanje jednog podatka iz reda " << "\n 3 za dodavanje jednog podatka u red " << "\n 4 za ispis reda " << "\n 5 za praznjenje reda ";
	cout << "\n 6 za prikaz broja elemenata reda " << "\n 7 za izlaz" << "\n Izbor: ";

	while (1) {
		cout << "\n Izbor: ";
		int unos; cin >> unos;
		switch (unos) {
		case 1: 
			cout << "\n Unesite broj elemenata reda: "; int n; cin >> n;
			cout << "\n Unesite elemente reda: \n";
			for (int i = 0; i < n; i++) R->dodaj();
			break;
		case 2: cout <<"\n"<< R->uzmi()<<"\n"; break;

		case 3:	cout << "\n Unesite element reda: \n"; R->dodaj(); break;

		case 4: cout << "\n Red: ";  R->pisi(); cout << "\n"; break;

		case 5: R->~Red(); break;

		case 6: cout << R->brelem(); cout << "\n"; break;

		case 7: exit(1);
		}
	}
	return 7;
}
