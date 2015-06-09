#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Timer.cpp"
#include <fstream>
#include <algorithm>
using namespace std;

void bubbleSort(int tab[], int n){
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n - i - 1; j++){
			if (tab[j]>tab[j + 1]){
				swap(tab[j], tab[j + 1]);
			}
		}
	}
}

void insertionSort(int tab[], int size){
	int temp, j;

	for (int i = 1; i < size; i++){
		temp = tab[i];

		for (j = i - 1; j >= 0 && tab[j] > temp; j--)
			tab[j + 1] = tab[j];

		tab[j + 1] = temp;
	}
}

void quickSort(int tab[], int left, int right)
{
	int i = left;
	int j = right;
	int x = tab[(left + right) / 2];
	do{
		while (tab[i] < x)
			i++;

		while (tab[j] > x)
			j--;

		if (i <= j){
			swap(tab[i], tab[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) quickSort(tab, left, j);

	if (right > i) quickSort(tab, i, right);

}

void print(int tab[], int n){
	for (int i = 0; i < n; i++){
		cout << tab[i] << ", ";
	}

}
void reset(int t[], int n, int max, int min){
	for (int i = 0; i < n; i++){
		t[i] = (rand() % max - min) + min;
	}
}

int main(){
	srand(time(NULL));

	const int size = 2e5;
	const int min = 50;
	const int max = 100;

	int *t = new int[size];
	for (int i = 0; i < size; i++){
		t[i] = (rand() % max - min) + min;
	}	//Mamy stworzona tablice liczb pseudolosowych
	Timer timer;

	fstream p;
	p.open("plik.txt");
	
	/*
	for (int i = 1; i < 11; i++){
		p << "Jedziemy z pierwsza iteracja sortow dla :" << size << endl;
		p << "Iteracja " << i << endl;
		//system("pause");
		timer.start_counter();
		quickSort(t, 1, 1e3);
		timer.stop_counter();		p << "Minelo: dla quick" << timer.get_elapsed_time() << " s." << endl;
		//system("pause");
		reset(t, size, min, max);
		timer.start_counter();
		insertionSort(t, 1e3);
		timer.stop_counter();		p << "Minelo: dla insertion" << timer.get_elapsed_time() << " s." << endl;
		//system("pause");
		reset(t, size, min, max);
		timer.start_counter();
		bubbleSort(t, 1e3);
		timer.stop_counter();		p << "Minelo: dla buble :/" << timer.get_elapsed_time() << " s." << endl;
		//system("pause");
	}
	*/

	// quickSort
	p << "quicksort:" << endl;
	for (int i = 1; i < 100; i++){
		//system("pause");
		timer.start_counter();
		quickSort(t, 1, size);
		timer.stop_counter();		p << timer.get_elapsed_time()<< endl;
	}
	p << "insertion" << endl;
	//insertion
	for (int i = 1; i < 100; i++){
		reset(t, size, min, max);
		timer.start_counter();
		insertionSort(t, size);
		timer.stop_counter();
		p << timer.get_elapsed_time() << endl;
	}
	p << "buble " << endl;
	for (int i = 1; i < 100; i++){
		//buble
		reset(t, size, min, max);
		timer.start_counter();
		bubbleSort(t, size);
		timer.stop_counter();
		p << timer.get_elapsed_time() << endl;
	}
	//p << "sort" << endl;
	//for (int i = 1; i < 100; i++){
		//sort
		//reset(t, size, min, max);
		//timer.start_counter();
		//sort(t, size);
		//timer.stop_counter();
		//p << timer.get_elapsed_time() << endl;
	//}
	
}