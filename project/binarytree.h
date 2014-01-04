#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<string>
using namespace std;
struct node
{
    int v;
    node *l;
    node *r;
    node *p;
};
node* createtree();
void inorder(node*);

node* createtree_from_pre_in(string , string);
node* createtree_from_post_in(string , string);
void postorder(node*);
void preorder(node*);
void print_t_dll(node *head);
void level_order_traversal(node* root);
