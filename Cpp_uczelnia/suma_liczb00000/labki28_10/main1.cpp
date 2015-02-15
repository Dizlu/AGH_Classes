#include <iostream>
using namespace std;


int s_l(int liczba)
{
	int count1 = 0;
	for (int a = 10000; a < 100000; a++)
	{
		int b = a;
		while (b)
		{
			count1 += b % 10;
			b /= 10;
		}
		if (count1 == liczba)
		{
			return a;
		}
		else
		{
			continue;
		}
	}
}


int main()
{
	int liczba;
	cout << "Podaj swoja liczbe" << endl;
	cin >> liczba;
	cout << s_l(liczba) << endl;
	cin >> liczba;
	return 0;
}

