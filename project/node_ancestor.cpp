#include<iostream>
#include"binarytree.h"

bool ancestor(node *root, int val)
{
	if (root == NULL)
		return false;
	if (root->v == val)
		return true;
	if (ancestor(root->l, val) || ancestor(root->r, val))
	{
		cout << root->v << " ";
		return true;
	}
}

void main()
{
	node *root = createtree();
	int val;
	cin >> val;
	ancestor(root, val);
	getch();
}