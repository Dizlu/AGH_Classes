using namespace std;
#include <iostream>
#include <string>

void w(string t, int a = 1){
	int dl = t.size();
	if (a == 1){
		for (int i = 0, j = dl - 1; i < dl; i++, j--){
			cout << t[j];
		}
		cout << endl;
	}
	else{
		cout << t << endl;
	}
}

int main(){
	string tekst;
// Wprowadzamy ze spacjami danego stringa
	getline(cin, tekst);
// Drukujemy z funkcji
	w(tekst, 2);
	w(tekst);

	system("PAUSE");
}