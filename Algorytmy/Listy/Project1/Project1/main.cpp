#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node{
	Node *next;
	float v;
};

struct List{
	Node *head;
	List();
	void add(float, float);
	Node* find(float);
	float del(float);
	void write(string);
	void read(string);
	void print();
	Node* tail();
	void addEnd(float);
	List fusion(List);
	List* divide(float);
	void addBeg(float);
	Node* reverse();
	List sameEl(List);
	void delDif(List);
	void add1(float w);
};
List::List(){
	head = NULL;
}

void List::add(float s, float v){
	Node *node = new Node;
	node->next = NULL;
	node->v = v;

	if (head == NULL){
		head = node;
	}
	else{
		Node *w = find(s);
		if (w != NULL){
			node->next = w->next;
			w->next = node;
		}
		else{
			node->next = head;
			head = node;
		} // Jesli chcemy dodac element wczesniej mozemy dopisac wartosc do kolejnego i zamienic wartosci
	}
}


Node* List::find(float s){
	Node *t = head;
	while (t != NULL){
		if (t->v == s){
			return t;
		}
		t = t->next;
	}
	return NULL;
}

float List::del(float s){
	Node *node = find(s);
	float temp;
	if (node != NULL){	// 3 -> (10) -> 4 -> 5
		temp = node->v;
		node->v = node->next->v;
		node->next->v = temp;
		node->next = node->next->next;
		return temp;
	}
	else{
		float a = head->v; //Tak zebysmy mogli ladnie zwroci head->v z przed zamiany.
		head = head->next;
		return a;
	}
}

void List::write(string file){
	fstream strumien;
	strumien.open(file.c_str());
	Node *t = head;
	while (t != NULL){
		strumien << t->v;
		strumien << " ";
		t = t->next;
	}
	strumien.close();
}
void List::read(string file){
	fstream strumien;
	strumien.open(file.c_str());
	float a;

	cout << "\nLista: - \t";
	while (!strumien.eof()){
		strumien >> a;
		cout << a;
		add(a, a);

	}
	cout << "\n";
	strumien.close();
}

void List::print(){
	Node *t = head;
	while (t != NULL){
		cout << t->v;
		t = t->next;
	}
	cout << endl;
}

//2 Laboratoria



Node* List::tail(){
	Node *t = head;
	while (t->next != NULL){ //Szukamy konca naszej listy
		t = t->next;
	}
	return t;
}
//Nie uzywamy jednak

void List::addEnd(float n){
	Node *t = tail();
	Node *node = new Node;
	if (t != NULL){
		node->v = n;
		t->next = node;
	}
}

void List::add1(float n){
	Node *node = new Node;
	node->v = n;
	node->next = NULL;
	if (head == NULL)
		head = node;
	else
	{
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;

	}
}

List List::fusion(List a){
	List ab;
	Node* w_a = a.head;
	Node* w_b = head;
	while (w_a != NULL || w_b != NULL){
		ab.addBeg(w_a->v);		// Tu wyskakuje blad przy kompilacji
		ab.addBeg(w_b->v);

		w_a = w_a->next;
		w_b = w_b->next;
	}
	if (w_a != NULL){
		while (w_a != NULL){
			ab.addBeg(w_a->v);


			w_a = w_a->next;	// Dodajemy elemetny z listy A do końca
		}
	}
	else if (w_b != NULL){
		while (w_b != NULL){
			ab.addBeg(w_b->v);

			w_b = w_b->next;	// Dodajemy elementy z listy B do końca
		}
	}
	return ab;		// Wynikowo otrzymujemy polaczona liste
}

List* List::divide(float n){
	List a, b;
	Node *h = head;
	while (h != NULL){
		if (h->v >= n){
			a.addBeg(h->v);
		}
		else if (h->v < n){
			b.addBeg(h->v);
		}
		h = h->next;
	}
	List *both = new List[2];
	both[0] = a;
	both[1] = b;

	return both;
}

void List::addBeg(float n){
	Node *node = new Node;
	node->v = n;
	node->next = head;
	head = node;
}

Node* List::reverse(){
	List temp;
	Node *h = head;
	while (h != NULL){
		temp.add(tail()->v, h->v);
		h = h->next;	//Dostajemy odwróconą listę <- Mamy odwrocona smieciowa liste
	}
	head = temp.head;		// Mamy stara odwrocona liste
	return head;
}

List List::sameEl(List a){
	List c;
	Node *h = head;
	Node *h_a = a.head;
	Node *h_c = c.head;
	while (h != NULL){
		while (h_a != NULL){
			if (h->v == h_a->v){
				c.add1(h->v);
			}
			h_a = h_a->next;
		}
		h_a = a.head;
		h = h->next;
	}
	return c;
}

void List::delDif(List a){
	Node *h = head;
	Node *h_a = a.head;

	while (h != NULL){
		bool counter = 0;
		while (h_a != NULL){
			if (h->v == h_a->v){
				counter = 1;
				break;
			}
			h_a = h_a->next;
		}
		if (counter == 0){
			del(h->v);
		}
		h_a = a.head;
		h = h->next;
	}
	
}

int main(){
	List cos, ktos;
	cos.read("plik.txt");
	ktos.read("plik1.txt");
	system("pause");
	List ab = cos.fusion(ktos);
	cout << "\nLista po fusion" << endl;
	ab.print();
	system("pause");
	cout << "\nLista po sameEl: ";
	List nowa = cos.sameEl(ktos);
	nowa.print();
	cout << endl;
	system("pause");
	cout << "\nCos przed: ";
	cos.print();
	cout << "\nA po odwroceniu: ";
	cos.reverse();
	cos.print();
	cout << "Lista po delDif";
	cos.delDif(ktos);
	cos.print();
	system("pause");


	List *dwie = new List[2];
	dwie = cos.divide(4);
	dwie[0].print();
	cout << endl;
	dwie[1].print();

	system("pause");
}