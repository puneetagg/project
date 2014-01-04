#include"binarytree.h"

void leftview(node* root, int lvl, int *maxlvl)
{
	if (root == NULL)
		return;
	if (lvl > *maxlvl)
	{
		cout << root->v << " ";
		*maxlvl = lvl;
	}
	leftview(root->l, lvl + 1, maxlvl);
	leftview(root->r, lvl + 1, maxlvl);
}

void main()
{
	node* root = createtree();
	int lvl = 0;
	leftview(root, lvl+1, &lvl);
	getch();
}