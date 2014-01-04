
#include "linkedlist.h"
using namespace std;

void print(node* head)
{
	node* t = head;
	while (t != NULL)
	{
		cout << t->v << " ";
		t = t->r;
	}
}