#include"binarytree.h"

void main()
{
	node* root = createtree();
//	postorder_iter_2(root); //Using 2 stacks
	postorder_iter(root);	//Using 1 stack
	_getch();
}