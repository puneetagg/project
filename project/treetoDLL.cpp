#include"binarytree.h"

void moveroottohead(node **root)
{
	while ((*root)->l != NULL)
		*root = (*root)->l;
}

void treetoDLL(node* root,node **prev)
{
	if (root == NULL)
		return;
	treetoDLL(root->l,prev);
	
	if (root->l != NULL)
		root->l = *prev;

	if ((*prev) != NULL)
		(*prev)->r = root;
	
	*prev = root;
	treetoDLL(root->r, prev);

}

void main()
{
	node *root = createtree();
	node* prev = NULL;
	treetoDLL(root,&prev);
	prev = NULL;
	delete prev;
	moveroottohead(&root);
	print_t_dll(root);
	getch();
}