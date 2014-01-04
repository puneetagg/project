
#include "linkedlist.h"

void print_t_ll(node* head)
{
	node* t = head;
	while (t != NULL)
	{

		cout << t->v << " ";
		t = t->r;
	}
}