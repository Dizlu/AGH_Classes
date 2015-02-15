#include <iostream>
using namespace std;

int ciag_rek(int n){
	if (n == 1){
		int r = -1;
		return r;}
	else if(n > 1){
		int a = -(ciag_rek(n - 1)) * (n - 3);
		return a;
	}
}

int main(){
	int wyraz = 0;
	cout << "Podaj ktory wyraz ciagu chcesz obliczyc: " << endl;
	cin >> wyraz;
	cout << "Ten wyraz ciagu wynosi: " << ciag_rek(wyraz) << endl;
	cin >> wyraz;
	return 0;

}