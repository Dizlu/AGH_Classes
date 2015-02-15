#include <iostream>
using namespace std;

void suma_pieciocyfrowych(int liczba){
	// liczenie sumy cyfr w liczbie
	/*
	// liczenie dla sumy cyfr podanej liczby
	int suma = 0, zmienna_dla_sumy = 0;
	zmienna_dla_sumy = liczba;
	while(zmienna_dla_sumy){
		suma += zmienna_dla_sumy % 10;
		zmienna_dla_sumy /= 10;
	}
	*/
	cout << "Liczby posiadajace ta sama sume cyfr co podana liczb: " << endl;
	for (int a = 10000; a < 100000; a++){
		// liczenie sum kolejnych cyfr w podanym przedziale
		int suma_ciag = 0, b = a;
		while (b){
			suma_ciag += b % 10;
			b /= 10;
		}
		// cout << "Sprawdzamy liczbe: " << a << endl;
		if (suma_ciag == liczba){
			cout << "Liczba" << a << "pasuje! " << endl;
		}
	}
}

int main(){
	register int liczba = 0;
	cout << "Podaj liczbe, a my wypiszemy \n wszystkie liczby spelniajace \n warunek sumy cyfr rowny podanej liczbie! " << endl;
	cin >> liczba;
	suma_pieciocyfrowych(liczba);


	cin >> liczba;
	return 0;
}