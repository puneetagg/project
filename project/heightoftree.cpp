#include"binarytree.h"
#include<queue>

int heightoftree(node *root)
{
	if (root == NULL)
		return 0;
	queue<node*> q;
	q.push(root);
	int count;
	node* t = NULL;
	int height=0;
	while (1)
	{
		count = q.size();
		if (count == 0)
			return height;
		while (count > 0)
		{
			t = q.front();
			q.pop();
			if (t->l)
				q.push(t->l);
			if (t->r)
				q.push(t->r);
			count--;
		}
		height++;
	}
}

void main()
{
	node *root = createtree();
	int h=heightoftree(root);
	cout << "Height of a tree: " << h;
	getch();
}