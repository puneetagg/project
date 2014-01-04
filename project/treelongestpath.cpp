#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "binarytree.h"
#include<string>
using namespace std;


int max(int a, int b)
{
	return a>b?a:b;
}

int diameter(node* root, int *h)
{
	if(root==NULL)
		return 0;
	int lh=0,rh=0;
	int ld=diameter(root->l,&lh);
	int rd=diameter(root->r,&rh);
	*h = max(lh,rh)+1;
	return max(lh+rh+1,max(ld,rd));
}

void main()
{
	node* root=createtree();
	inorder(root);
	int h=0;
	int len=diameter(root,&h);
	cout<<endl<<"Diameter of a tree: "<<len<<endl;
	cout<<h;
	getch();
}