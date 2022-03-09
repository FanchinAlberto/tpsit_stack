#include <iostream>

using namespace std;

struct cell {

  char value;

  cell * next = nullptr;

};

void AddStack(cell *&r, char val, int &counter) //funzione per aggiungere un elemento allo stack
{

  cell *newCell = new cell; //creo un nuovo spazio in memoria per la cella
  newCell->value = val; //inserisco il valore della cella
	
  newCell -> next = r;
	r = newCell;
  counter++;
}

void PrintStack(cell * r) {

  for(cell* i = r; i != nullptr; i = i->next) { //stampo il valore della cella e faccio puntare p alla cella successiva
    cout << i -> value;
  }

}
void RemoveStack(cell *&r, int counter){
  for(int i = 0; i < counter; i++){
    cell *temp = r;
    r = temp->next;
    delete(temp);
  }
}
void RemoveChar(cell *&r, int &counter){
  cell *temp = r;
    r = temp->next;
    delete(temp);
    counter--;
}

int main() {
  int counter = 0;
  cell * r = nullptr;

  AddStack(r, 's', counter);

  AddStack(r, 'a',counter);

  AddStack(r, 's', counter);
  cout<<"Numero di celle:"<<counter<<endl;
  PrintStack(r);
  RemoveChar(r, counter);
  RemoveStack(r, counter);


}