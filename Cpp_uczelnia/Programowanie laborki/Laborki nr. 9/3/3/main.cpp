#include <iostream>
#include <string>
using namespace std;

void usun(string &s, string usuwany){
	int poz = s.find(usuwany), dl = usuwany.length();
	s.erase(poz, dl);
	string nowy;
	//Zamienimy go od razu na nowy
	cout << "Na co chcesz go zamieniæ?" << endl;
	getline(cin, nowy);
	s.insert(poz, nowy);
}
void wstaw(int a, string &s){
	cout << "Na co zamieniamy? \n";
	string zmiana;
	getline(cin, zmiana);
	s.insert(a, zmiana);
}
int main(){
	string tekst;
// Wprowadzenie jakies zmiennej do stringa getlinem zeby pominac biale znaki
	getline(cin, tekst);
	//Usuwamy wprowadzony napis
	string usuwany;
	cout << "Jaki wyraz chcesz usunac?";
	getline(cin, usuwany);
	usun(tekst, usuwany);
	cout << tekst << endl;
	system("PAUSE");
}