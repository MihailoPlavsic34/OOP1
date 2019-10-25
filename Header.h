#include <iostream>

class Ceo { // znam da bi lakse bilo koristeci strukture ali po mom misljenju je ovako bolje za vezbu
public:
	Ceo() {
		i = 0;
		sled = nullptr;
	};
	Ceo(int i_, Ceo* sledeci_) {
		i = i_;
		sled = sledeci_;
	};
	void promeni(int n) { i = n; };
	void promeni(Ceo* pk) { sled = pk; };
	Ceo* const sledeci() { return sled; };
	int const broj() { return i; };
private:
	int i;
	Ceo* sled;
}; // da li je dobro sto sam ove jednostavne funkcije definisao ovde (dobri kandidati za inlajning?) ili sam i njih trebao da definisem u posebnom fajlu?
// kako nema diamickih tipova podataka nema potrebe za kopirajucim tj premestajucim konstruktorom i destruktorom

class Red { // ideja je da postoji jedan glavni "Red", koji pokazuje na listu tipa Ceo 

public:
	Red();
	~Red();
	Red(Red& const Red);
	Red(Red&& Red);
	void dodaj();
	int uzmi();
	void const pisi();
	int const brelem();

private:
	int pop;
	Ceo* kraj;
	Ceo* poc;
};
