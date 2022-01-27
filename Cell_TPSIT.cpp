#include <iostream>

using namespace std;
struct cell {
	char value = ' ';
	cell* next = nullptr;
};

void AddStack(cell*r, char val) //funzione per aggiungere un elemento allo stack
{
	cell* newCell = new cell; //creo un nuovo spazio in memoria per la cella
	r = newCell; //la mia root punta alla cella
	newCell->value = val; //inserisco il valore della cella
	newCell->next = newCell;
}

void RemoveStack(cell* r) 
{
	char tmp = r->value; //rimuovo il valore dallo stack
	r = r->next; //sposto la root alla prossima cella
	cout << tmp;
	r->value = NULL; //cancello la cella
}

int main() {
	cell* r = nullptr;
	cout << "Hello world" << endl;
	AddStack(r, 's');
	AddStack(r, 'a');
	AddStack(r, 's');

	RemoveStack(r);

}