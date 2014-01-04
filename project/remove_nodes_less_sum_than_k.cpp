#include"binarytree.h"

node* removenodes(node* root, int *sum, int k)
{
	if (root == NULL)
		return NULL;
	int ls, rs;
	ls = *sum + root->v;
	rs = *sum + root->v;
	root->l=removenodes(root->l, &ls, k);
	root->r = removenodes(root->r, &rs, k);

	*sum = (ls > rs) ? ls : rs;
	if (*sum < k)
	{
		free(root);
		root = NULL;
	}
	return root;
}

void main()
{
	node* root = createtree();
	int sum;
	cout << "Enter Sum: ";
	cin >> sum;
	int k=0;
	root=removenodes(root, &k, sum);
	inorder(root);
	getch();
}