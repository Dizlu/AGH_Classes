using namespace std;
#include <iostream>
#include <string>



int main(){
	string teksty[5];

	for (int i = 0; i < 5; i++){
		getline(cin, teksty[i]);
	}
	cout << "Na samogloske zaczynaja sie:" << endl;
	for (int i = 0; i < 5; i++){
		if (teksty[i][0] == 'a' || teksty[i][0] == '¹' || teksty[i][0] == 'e' || teksty[i][0] == 'ê' ||
			teksty[i][0] == 'o' || teksty[i][0] == 'ó' || teksty[i][0] == 'u' || teksty[i][0] == 'y' ||
			teksty[i][0] == 'i'){
			cout << teksty[i] << endl;
		}
	}

	system("pause");
}