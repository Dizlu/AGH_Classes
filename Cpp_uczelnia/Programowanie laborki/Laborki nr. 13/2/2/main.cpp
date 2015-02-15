#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct samochod{
	string marka;
	string model;
	int rok;
	float pojemnosc;
	float spalanie;
	
};
int main(){
	fstream plik;
	plik.open("E:\\Dropbox\\Studia\\Programowanie laborki\\Laborki nr. 13\\2\\Debug\\plik.txt");
	if (!plik.eof()){
		cout << "Plik otworzony" << endl;
	}
	samochod tab[5];
	for (int i = 0; i < 5; i++){
		plik >> tab[i].marka >> tab[i].model >> tab[i].rok >> tab[i].pojemnosc >> tab[i].spalanie;
	}
	for (int i = 0; i < 5; i++){
		cout << "Samochod " << tab[i].marka << " " << tab[i].model << " z roku: " << tab[i].rok
			<< ". O pojemnosci: " << tab[i].pojemnosc << ". Oraz spalaniu: " << tab[i].spalanie << endl;
	}
	float ekonomiczny = 0, max = 0;
	int nr = 0;
	for (int i = 0; i < 5; i++){
		max = tab[i].pojemnosc * (100 / tab[i].spalanie);
		if (ekonomiczny <= max){
			ekonomiczny = max;
			nr = i;
		}
	}
	cout << "Najbardziej ekonomiczny jest samochod numer: " << nr << ", a przejedzie on: " << ekonomiczny << "km.";
	cout << endl;
	plik.close();
	if (plik.eof()){
		cout << "Plik zamkniety" << endl;
	}
	system("pause");

}