#include <iostream>
using namespace std;

struct cell { //creo la struttura cella
	int value = 0;			
	cell* next = nullptr;	
};

struct queue { //creo la stuct queue per una più facile gestione della coda
	cell* firstItem = nullptr;	
	cell* lastItem = nullptr;	
};



int rimuoviItem(queue*&queue) //funzione di rimozione cella dalla coda
{
	if (queue->firstItem == nullptr)//controllo se la coda sia vuota, prima di effettuare qualsiasi operazione
	{
		Cout<<"La coda è vuota"<<endl;	
	}
	int value = queue->firstItem->value; //prendo il valore all'interno della cella		

	cell* tmp = queue->firstItem; //salvo in una variabile temporanea il primo item della coda			

	queue->firstItem = queue->firstItem->next; //sposto il first item	

	delete tmp; //cancello la cell temporanea						

	return value; //ritorno il valore della cella cancellata
}

int lunghezzaQueue(queue*&queue) //funzione per ottenere le dimensioni della coda
{
	int length = 0;
	if (queue->firstItem == nullptr) //se la coda è vuota ritorno 0		
	{
		return length;
	}
	for (cell* tmp = queue->firstItem; tmp != nullptr; tmp = tmp->next) //scorro tutta la coda con una cella temporanea, ogni volta che incontro una cella incremento lenght	
	{
		length++;		
	}
	return length; //ritorno la lunghezza della coda
}



void mostravalori(queue*& queue) //funzione per mostrare i valori della queue
{
	int i = 0;
	for (cell* tmp = queue->firstItem; tmp != nullptr; tmp = tmp->next) //scorro tutta la queue, stampandone mano a mano le celle
	{
		printf("cell[%d]: %d\n", i, tmp->value);		
		i++;
	}
}

void aggiungiItem(queue*& queue, int n) { //funzione per l'aggiunta di un oggetto alla coda
	cell* newCell = new cell; //cella temporanea		
	newCell->value = n; //prendo il valore passato come parametro				

	if (queue->firstItem == nullptr) //se la queue è vuota, allora la nuova cella è sia il primo che l'ultimo item della coda	
	{
		queue->firstItem = newCell;			
		queue->lastItem = newCell;
	}
	else //se la coda non è vuota l'ultimo item punta alla nuova cella, mentre la nuova cella divente l'ultimo item della coda
	{
		queue->lastItem->next = newCell;		
		queue->lastItem = newCell;			
	}
} 

void cancellaQueue(queue*& queue) //funzione per cancellare la coda
{
	int lenght = lunghezzaQueue(queue);	//prendo la lunghezza della coda
	for (int i = 0; i < lenght; i++) //scorro la coda e a mano a mano rimuovo i singoli item
	{
		rimuoviItem(queue);					
	}
}

int main() {
	queue* q = new queue;

	aggiungiItem(q, 1);
	aggiungiItem(q, 2);
	aggiungiItem(q, 3);
    	rimuoviItem(q);
	mostravalori(q);
    	lunghezzaQueue(q);
	cancellaQueue(q);
    	lunghezzaQueue(q)<<endl;
	return 0;
}
