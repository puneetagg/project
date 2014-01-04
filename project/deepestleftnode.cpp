#include<iostream>
#include<conio.h>
#include "binarytree.h"

void deepestleftnode(int lvl, int *maxlvl,node *root, bool isleft, node **res)
{
	if(root==NULL)
		return;
	if(isleft && lvl>*maxlvl && root->l==NULL && root->r==NULL)
	{
		*maxlvl=lvl;
		*res=root;
	}
	deepestleftnode(lvl+1,maxlvl,root->l,true,res);
	deepestleftnode(lvl+1,maxlvl,root->r,false,res);
}

void main()
{
	node *root=createtree();
	node *t=new node;
	node **res;
	*res=t;
	int lvl=0,maxlvl=0;
	deepestleftnode(lvl,&maxlvl,root,true,res);
	cout<<(*res)->v;
	getch();
}