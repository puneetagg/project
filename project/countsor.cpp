#include<iostream>

using namespace std;

void main()
{
int a[10]={0,4,2,4,3,1,0,2,4,1};
int b[10];

int c[5];
for(int i=0;i<5;i++)
	c[i]=0;

for(int i=0;i<10;i++)
	c[a[i]]+=1;

for(int i=0;i<4;i++)
	c[i+1]+=c[i];

for(int i=0;i<5;i++)
	cout<<c[i]<<" ";

cout<<"*******************************";

for(int i=9;i>=0;i--)
{
	b[c[a[i]]-1]=a[i];
	c[a[i]]--;
}


for(int i=0;i<5;i++)
	cout<<c[i]<<" ";
cout<<endl;

for(int i=0;i<10;i++)
	cout<<b[i]<<" ";

getchar();

}
