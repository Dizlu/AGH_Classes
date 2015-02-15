#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	ifstream plik;
	plik.open("E:\\Dropbox\\Studia\\Programowanie laborki\\Laborki nr. 13\\1\\Debug\\plik.txt");
	if (!plik){
		cout << "Nie otworzono pliku";
	}
	else if (plik){
		cout << "Otworzono plik" << endl;
	}
	// Wczytujemy wymiary tablicy ze strumienia i tworzymy macierz
	int x, y;
	plik >> x >> y;
	cout << " X:" << x << "Oraz y:" <<  y << endl;
	float **tab = new float*[x];
	for (int i = 0; i < x; i++){
		tab[i] = new float[y];
	}
	for(int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			int a, b;
			plik >> a >> b;
			plik >> tab[a][b];
		}
	}
	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			cout << tab[i][j];
			cout << "\t";
		}
		cout << "\n";
	}

	system("pause");
}