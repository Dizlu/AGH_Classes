#include <iostream>
#include <string>
using namespace std;

int wzorzec(string s, string wzor){
	int a = s.find(wzor);
	return a;
}

int main(){
	string tekst, wzorek;
	getline(cin, tekst);
	getline(cin, wzorek);

	cout << "Wzorzec by³ na pozycji: ";
	cout << wzorzec(tekst, wzorek) << "." << endl;
	system("pause");
}