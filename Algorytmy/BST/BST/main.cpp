#include <iostream>
#include "Timer.cpp"
using namespace std;



struct BSTNode{
	float key;
	BSTNode *parent;
	BSTNode *lson;
	BSTNode *rson;
};
/******************************/
struct BST{
	BSTNode *root;
	BST();
	//Dodatkowe
	BSTNode* frson(BSTNode*);	//OKS
	BSTNode* flson(BSTNode*);	//OKS
	BSTNode* nextBST(BSTNode*);
	BSTNode* prevBST(BSTNode*);
	//Metody
	void print(BSTNode*);	//OKS
	void add(float);	//OKS
	void del(BSTNode*);
	float max();	//OKS
	float min();	//OKS
	BSTNode* find(float);	//OKS
	int level(BSTNode*);
	void printSameLevel(BSTNode*, int);
};
/******************************/
BST::BST(){
	root = NULL;
}
/******************************/
void BST::printSameLevel(BSTNode* r,int n){	// Rekurencyjne, do poprawy (wykonanie bez argumentu wejsciowego?)
	if (n == 1){ 
		cout << root->key << "\t";
		return;
	}
	if (r->lson != NULL){
		printSameLevel(r->lson, n);
	}
	if (level(r) == n){
		cout << r->key << "\t";
	}
	if (r->rson != NULL){
		printSameLevel(r->rson, n);
	}
}
/******************************/
int BST::level(BSTNode* n){
	BSTNode *temp = n;
	int level = 1;
	while (temp != root){
		temp = temp->parent;
		level++;
	}
	return level;
}
/******************************/
BSTNode* BST::nextBST(BSTNode* x){
	if (x == NULL) { return x; }
	if (x->rson != NULL){ return flson(x->rson); }
	BSTNode* y = x->parent;
	while (y != NULL && x == y->rson){
		x = y;
		y = y->parent;
	}
	return y;
}
/******************************/
/*
void BST::del(BSTNode* x){
	BSTNode* y;
	BSTNode* z;
	if (x->lson == NULL || x->rson == NULL){ y = x; }
	else{ y = nextBST(x); }

	if (y->lson != NULL){ z = y->lson; }
	else{ z = y->rson; }

	if (z != NULL){ z->parent = y->parent; }
	

	if (y->parent != NULL){
		if (y == y->parent->lson){ y->parent->lson = z; }
		else { y->parent->rson = z; }
	}
	else{ root = z; }
	if (y != x){	// x=y?
		x->key = y->key;
		x->parent = y->parent;
		x->lson = y->lson;
		x->rson = y->rson;
	}
	delete y;
}
*/
/***********************************/
void BST::del(BSTNode* z){
	BSTNode* y;
	if (z->lson != NULL && z->rson != NULL){ y = nextBST(z); }
	else { y = z; }
	BSTNode* x;
	if (y->lson != NULL){ x = y->lson; }
	else { x = y->rson; }
	if (x != NULL){ x->parent = y->parent; }
	if (y->parent != NULL){
		if (y == y->parent->lson){ y->parent->lson = x; }
		else { y->parent->rson = x; }
	}
	else { root = x; }
	if (y != z){ z->key = y->key; }
	delete y;

}
/******************************/
BSTNode* BST::frson(BSTNode* r){
	BSTNode *temp = r;
	if (temp == NULL){ return temp; }
	while (temp->rson != NULL){
		temp = temp->rson;
	}
	return temp;
}
BSTNode* BST::flson(BSTNode* r){
	BSTNode *temp = r;
	if (temp == NULL){ return temp; }
	while (temp->lson != NULL){
		temp = temp->lson;
	}
	return temp;
}
/******************************/
float BST::max(){
	float a = frson(root)->key;
	return a;
}
/******************************/
float BST::min(){
	float a = flson(root)->key;
	return a;
}
/******************************/
void BST::print(BSTNode* r){	// Rekurencyjne, do poprawy (wykonanie bez argumentu wejsciowego?)
	if (root->rson == NULL && root->lson){
		if (root != NULL){
			cout << root->key << "\t";
		}
		return;
	}
	if (r->lson != NULL){
		print(r->lson);
	}
	cout << r->key << "\t";
	if (r->rson != NULL){
		print(r->rson);
	}
}
/******************************/
void BST::add(float k){
	BSTNode *w = new BSTNode;
	w->key = k;
	w->lson = NULL;
	w->rson = NULL;
	w->parent = NULL;
	BSTNode *p = root;
	if (p == NULL){
		root = w;
		w->parent = p;
		return;
	}
	while (1){
		if (k > p->key){
			if (p->rson == NULL){
				p->rson = w;
				w->parent = p;
				return;
			}
			p = p->rson;
		}
		else{
			if (p->lson == NULL){
				p->lson = w;
				w->parent = p;
				return;
			}
			p = p->lson;
		}
	}
}
/******************************/
BSTNode* BST::find(float n){
	if (root == NULL){ return root; }
	BSTNode *temp = root;
	while (temp != NULL && temp->key != n){
		if (n < temp->key){ temp = temp->lson; }
		else { temp = temp->rson; }
	}
	return temp;
}
/******************************/
float min(float t[], int n){
	float min = t[0];
	for (int i = 1; i < n; i++){
		if (t[i] < min) { min = t[i]; }
	}
	return min;
}
/******************************/
float max(float t[], int n){
	float max = t[0];
	for (int i = 1; i < n; i++){
		if (t[i] > max) { max = t[i]; }
	}
	return max;
}
/******************************/
int main(){
	BST cos;
	cos.add(50);
	cos.print(cos.root);
	cos.add(25);
	cos.add(75);
	cos.add(30);
	cos.add(45);
	cos.add(60);
	cos.add(80);
	float tab[7] = { 50, 25, 75, 30, 45, 60, 80 };
	cout << "\nNajwieksza wartosc w tablicy to: " << max(tab, 7) << endl;
	cout << "Najmniejsza wartosc w tablicy to: " << min(tab, 7) << endl;


	/******************************/
	cout << "Wartosci in-order w drzewie BST to: \n";
	cos.print(cos.root);
	cout << "\nNajwieksza wartosc w drzewie to: " << cos.max() << endl;
	cout << "Najmniejsza wartosc w drzewie to: " << cos.min() << endl;
	BSTNode* a = cos.find(50);	//Unikanie drukowania nieistniej¹cego key'a?
	cout << cos.nextBST(a)->key << endl;
	cos.print(cos.root);
	cout << endl;
	cos.del(a);
	cos.print(cos.root);
	cout <<endl << cos.root->key;
	cos.add(24);
	cos.add(20);
	cos.add(16);
	a = cos.find(60);
	cout << endl << cos.level(a) << endl;
	cos.printSameLevel(cos.root, 1);
	cout << endl;
	cos.printSameLevel(cos.root, 2);
	cout << endl;
	cos.printSameLevel(cos.root, 3);
	cout << endl;
	cos.printSameLevel(cos.root, 4);
	cout << endl;
	system("pause");
}