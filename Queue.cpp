#include <iostream>
using namespace std;

struct cell {
	int value = 0;			
	cell* next = nullptr;	
};

struct queue {
	cell* firstItem = nullptr;	
	cell* lastItem = nullptr;	
};



int rimuoviItem(queue*&queue)
{
	if (queue->firstItem == nullptr)
	{
		throw invalueid_argument("The queue is empty");	
	}
	int value = queue->firstItem->value;		

	cell* tmp = queue->firstItem;			

	queue->firstItem = queue->firstItem->next;	

	delete tmp;						

	return value;
}

int lunghezzaQueue(queue*&queue)
{
	int length = 0;
	if (queue->firstItem == nullptr)		
	{
		return length;
	}
	for (cell* tmp = queue->firstItem; tmp != nullptr; tmp = tmp->next)	
	{
		length++;		
	}
	return length;
}



void mostravalori(queue*& queue)
{
	int i = 0;
	cout << endl;
	for (cell* tmp = queue->firstItem; tmp != nullptr; tmp = tmp->next)
	{
		printf("cell[%d]: %d\n", i, tmp->value);		
		i++;
	}
}

void aggiungiItem(queue*& queue, int n) {
	cell* newCell = new cell;			
	newCell->value = n;					

	if (queue->firstItem == nullptr)	
	{
		queue->firstItem = newCell;			
		queue->lastItem = newCell;
	}
	else
	{
		queue->lastItem->next = newCell;		
		queue->lastItem = newCell;			
	}
} 

void cancellaQueue(queue*& queue)
{
	int lenght = lunghezzaQueue(queue);	
	for (int i = 0; i < lenght; i++)
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