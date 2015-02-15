#include <iostream>
using namespace std;

void licz(int liczba){
	int count0 = 0, count1 = 0;
	cout << "Podana liczba binarnie to : ";
	while (liczba){
		if (liczba % 2 == 0){
			count0++;
		}
		else if (liczba % 2 == 1){
			count1++;
		}
		cout << liczba % 2;
		liczba /= 2;
	}
	cout << " " << endl;
	cout << "Liczba zer: " << count0 << endl;
	cout << "Liczba jedynek: " << count1 << endl;
}

int main(){
	int liczba = 0;
	cout << "Podaj liczbe ktora zamienimy na ciag binarny i policzymy skladowe";
	cin >> liczba;
	licz(liczba);

	cin >> liczba;
	return 0;
}