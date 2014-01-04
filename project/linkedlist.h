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
void print_t_ll(node *head);