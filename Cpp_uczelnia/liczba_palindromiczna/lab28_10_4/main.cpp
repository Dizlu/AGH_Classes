#include <iostream>
using namespace std;
bool palindromiczna(int liczba)
{
	int dlugosc = 0, liczba1 = liczba, i = 0;
	int symetrycznosc[32];
	while (liczba1)
	{
		// tworzenie liczby w tablicy
		symetrycznosc[i] = liczba1 % 10;
		i++;
		//liczenie jej dlugosci
		liczba1 /= 10;
		dlugosc++;
	}
	cout << dlugosc << endl;
	bool wynik = 1;
	for (int a = 0, b = dlugosc - 1; a < b; a++, b--)
	{
		cout << "a = " << symetrycznosc[a] << "b =" << symetrycznosc[b] << endl;
		if (symetrycznosc[a] != symetrycznosc[b])
		{
			wynik = 0;
		}
	}
	return wynik;
}

int main()
{
	int licz = 0;
	cin >> licz;

	if (palindromiczna(licz) == true)
	{
		cout << "Liczba jest palindromiczna!" << endl;
	}
	else if (palindromiczna(licz) == false)
	{
		cout << "Liczba nie jest palindromiczna!" << endl;
	}
	cin >> licz;
	return 0;
}