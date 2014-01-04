#include"binarytree.h"
#include<stdio.h>

void leavestodll(node *root, node **t)
{
	if (root == NULL)
	{
		return;
	}
	if (root->l == NULL && root->r == NULL)
	{
		
		if (*t)
		{
			root->r = *t;
			(*t)->l = root;
		}
		*t = root;
		return;
	}
	leavestodll(root->r, t);
	leavestodll(root->l, t);
}


void main()
{
	node *root = createtree();
	node* t;
	t = NULL;
	leavestodll(root, &t);
	while (t)
	{
		cout << t->v << " ";
		t = t->r;
	}
	_getch();
}
