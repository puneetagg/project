#include"binarytree.h"

void main()
{
	node* root = createtree();
	inorder_iter(root);
	_getch();
}