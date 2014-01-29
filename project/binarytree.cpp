
#include "binarytree.h"
#include <queue>
#include <stack>
using namespace std;

node* createtree()
{
	cout << "*********************************************************************\n";
	cout << "Navigation--- l = left insert, r = right insert, p = goto parent\n";
	cout << "x = goto left child, y = goto right child\n";
	cout << "*********************************************************************\n";


	node *root = new node;
	root->l = NULL;
	root->r = NULL;
	root->p = NULL;
	char c;

	int val;
	cout << "Enter root node value: ";
	cin >> val;
	root->v = val;

	node *t = new node;
	t = root;
	node *s;

	while (1)
	{
		c = getchar();
		if (c == 'n')
			break;
		else if (c == '\n')
			continue;
		switch (c)
		{
		case 'l':
			goto insl;
		case 'r':
			goto insr;
		case 'p':
			goto parent;
		case 'x':
			goto lchild;
		case 'y':
			goto rchild;
		}
	insl:
		s = new node;
		cin >> val;
		s->v = val;
		t->l = s;
		s->p = t;
		s->l = NULL;
		s->r = NULL;
		continue;
	insr:
		s = new node;
		cin >> val;
		s->v = val;
		t->r = s;
		s->p = t;
		s->l = NULL;
		s->r = NULL;
		continue;
	parent:
		if (t->p != NULL)
			t = t->p;
		else
			cout << "Not valid\nEnter again: ";
		continue;
	lchild:
		if (t->l != NULL)
			t = t->l;
		else
			cout << "Not valid\nEnter again: ";
		continue;
	rchild:
		if (t->r != NULL)
			t = t->r;
		else
			cout << "Not valid\nEnter again: ";
		continue;


	}
	cout << "Inorder: ";
	inorder(root);
	cout << endl;
	return root;
}

node* createtree_from_post_in(string in, string post)
{
	if (in.size() == 0)
		return NULL;
	if (post.size() == 0)
		return NULL;

	char p = post[post.size() - 1];
	int i = 0, j = 0;
	while (in[i] != p)
	{
		i++;
		j++;
	}
	i = 0;
	node *t = new node;
	t->v = p;
	t->l = NULL;
	t->r = NULL;

	t->l = createtree_from_post_in(in.substr(0, j - i), post.substr(0, j - i));
	t->r = createtree_from_post_in(in.substr(j + 1), post.substr(j, in.substr(j + 1).size()));

	return t;
}

node* createtree_from_pre_in(string in, string pre)
{
	if (in.size() == 0)
		return NULL;
	if (pre.size() == 0)
		return NULL;

	// bool a[256];
	int i = 0;
	node *t = new node;
	// for(i=0;i<256;i++)
	//   a[i]=false;

	char p = pre[0];

	t->v = p;
	//    cout<<t->v;
	t->l = NULL;
	t->r = NULL;

	i = 0;
	int j = 0;
	while (p != in[i])
	{
		i++;
		j++;
	}
	i = 0;
	t->l = createtree_from_pre_in(in.substr(i, j - i), pre.substr(i + 1, j - i));
	t->r = createtree_from_pre_in(in.substr(j + 1), pre.substr(j + 1));

	return t;

}

void inorder(node* t)
{
	if (t != NULL)
	{
		inorder(t->l);
		cout << t->v << " ";
		inorder(t->r);
	}
}



void postorder(node *root)
{
	if (root != NULL)
	{
		postorder(root->l);
		postorder(root->r);
		cout << root->v;
	}
}

void preorder(node *root)
{
	if (root != NULL)
	{
		cout << root->v;
		preorder(root->l);
		preorder(root->r);
	}
}


void print_t_dll(node* head)
{
	node* t = head;
	while (t != NULL)
	{

		cout << t->v << " ";
		t = t->r;
	}
}


void level_order_traversal(node *root)
{
	if (root == NULL)
		return;
	queue<node*> q;
	q.push(root);
	int count;
	node* t = NULL;
	cout << "Level Order: ";
	while (q.size())
	{
		count = q.size();
		while (count > 0)
		{
			t = q.front();
			q.pop();
			cout << t->v << " ";
			if (t->l)
				q.push(t->l);
			if (t->r)
				q.push(t->r);
			count--;
		}
		cout << endl;
	}
}


void preorder_iter(node *root)
{
	if (root == NULL)
		return;
	node *t = root;
	stack<node*> st;
	while (t != NULL)
	{
		cout << t->v << " ";
		if (t->r != NULL)
			st.push(t->r);

		t = t->l;
		if (t == NULL && st.size())
		{
			t = st.top();
			st.pop();
		}
	}
}

void inorder_iter(node *root)
{
	if (root == NULL)
		return;
	stack<node*> st;
	while (root)
	{
		st.push(root);
		root = root->l;
		while (!root && st.size())
		{
			root = st.top();
			st.pop();
			cout << root->v << " ";

			root = root->r;
			if (root)
				break;
		}
	}

}

void postorder_iter_2(node *root)	//Using 2 stacks
{
	if (!root)
	{
		return;
	}
	stack<node*> st1, st2;
	st1.push(root);
	node *t;
	while (st1.size())
	{
		t = st1.top();
		st1.pop();
		st2.push(t);

		if (t->l)
			st1.push(t->l);
		if (t->r)
			st1.push(t->r);
	}
	while (st2.size())
	{
		t = st2.top();
		st2.pop();
		cout << t->v << " ";
	}
}

void postorder_iter(node* root)
{
	if (root == NULL)
		return;
	cout << "Iterative postorder using 1 stack: ";
	stack<node*> st;

	do
	{
		while (root)
		{
			if (root->r)
				st.push(root->r);
			st.push(root);
			root = root->l;
		}

		root = st.top();
		st.pop();
		if (st.size() && root->r != NULL && root->r == st.top())
		{
			st.pop();
			st.push(root);
			root = root->r;
		}
		else
		{
			cout << root->v << " ";
			root = NULL;
		}
	} while (st.size());

}


