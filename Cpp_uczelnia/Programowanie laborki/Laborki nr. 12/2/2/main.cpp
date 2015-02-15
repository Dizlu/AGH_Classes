#include <iostream>
#include <time.h>
using namespace std;

struct punkt{
	int n = 0;
	int *p;
	/*************************/
	void wprowadz(int a, int *b){
		for (int i = 0; i < a; i++){
			p[i] = rand() % (10 - 1) + 1;
		}
	}
	/************************/
	void wypisz(int, int*);
	void translacja(int, int*);
	void symetria(int, int*);
};
/***************************/
void punkt::wypisz(int n, int *tab){
	cout << "|";
	for (int i = 0; i < n; i++){
		cout << tab[i] << " ";
	}
	cout << "| \n";
}
/*****************************/
void punkt::translacja(int n, int *tab){
	cout << "Podaj kolejno wspolrzedne wektora o jaki wykonamy translacji \n";
	int *tab1 = new int[n];
	for (int i = 0; i < n; i++){
		cout << "Wektor " << i << " : ";
		cin >> *(tab1 + i);
	}
	for (int i = 0; i < n; i++){
		tab[i] += tab1[i];
	}
}
/****************************/
void punkt::symetria(int n, int *tab){
	cout << "Podaj kolejno wspolrzedne wektora o jaki wykonamy symetrii \n";
	int *tab1 = new int[n];
	for (int i = 0; i < n; i++){
		cout << "Wektor " << i << " : ";
		cin >> *(tab1 + i);
	}
	for (int i = 0; i < n; i++){
		if (tab[i] > tab1[i]){
			tab[i] = tab1[i] -  (tab[i] - tab1[i]);
		}
		else if (tab[i] < tab1[i]){
			tab[i] = tab1[i] +  (tab1[i] - tab[i]);
		}
		else{
			continue;
		}
	}
}
/****************************/
int main(){
	srand(time(NULL));
	punkt a;
	cin >> a.n;
	a.p = new int[a.n];
	a.wprowadz(a.n, a.p);
	a.wypisz(a.n, a.p);
	a.translacja(a.n, a.p);
	a.wypisz(a.n, a.p);
	a.symetria(a.n, a.p);
	a.wypisz(a.n, a.p);

	system("PAUSE");
}