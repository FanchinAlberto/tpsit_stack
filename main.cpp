
#include <iostream>

using namespace std;

template <typename T>
struct cell {

  T value;

  cell * next = nullptr;

};

template <typename T>
class stack{
    
    private:
        cell<T> *root;
        int count = 0;
    public:
    stack(){}
    stack(char val){
        root = new cell<T>;
        root->value = val;
    }
    ~stack(){delete root;}
    friend ostream& operator<< (ostream& os, stack& s);
    friend void operator<< (stack& s, char v);
    friend void operator>> (stack& s, char v);
    void push(char val){
      cell<T> *newCell = new cell<T>; //creo un nuovo spazio in memoria per la cella
      newCell->value = val; //inserisco il valore della cella
	
      newCell -> next = root;
	    root = newCell;
      count++;
    }
    char pop(){
      cell<T> *temp = root;
      root = temp->next;
      char val = temp -> value;
      delete(temp);
      count--;
      return val;
    }
    void PrintStack() {

      for(cell<T>* i = root; i != nullptr; i = i->next) { //stampo il valore della cella e faccio puntare p alla cella successiva
        cout << i -> value;
        cout << " Count: " << count << endl;
      }
    }
    
    
};

template <typename T>
ostream& operator<< (ostream& os, stack& s){
  s.PrintStack();
  return os;
}

template <typename T>
void operator<< (stack& s, T v){
  s.push(v);
}
template <typename T>
void operator>> (stack& s, T v){
  v = s.pop();
}
int main()
{
  stack<int> elenco_int(1);
  stack<string> elenco_stringhe('s');
  char v;

  elenco_int<<2;
  elenco_stringhe<<'a';
  return 0;
}
