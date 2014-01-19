#include"binarytree.h"

void main()
{
	node* root = createtree();
	preorder_iter(root);
	_getch();
}