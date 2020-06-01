// In The Name Of Allah

#include <iostream>
#include "Node.h"

using namespace std;

class STK
{
private:
	int top;
	node *a[100];
	int size;

public:
	STK();
	~STK();
	void push(node*);
	node* pop();
	int showTop();
	node* showTopValue();
};

STK::STK()
{
	top = -1;
	size = 100;
}

STK::~STK()
{
	top = -1;
	size = 0;
}

void STK::push(node* n)
{
	if (!n)
		return;

	if (top >= size - 1)
	{
		cout << "OverFlow";
		return;
	}

	a[++top] = n;
	return;
}

node* STK::pop()
{
	if (top < 0)
	{
		cout << "Empty";
		return nullptr;
	}

	return a[top--];
}

int STK::showTop()
{
	return top;
}

node* STK::showTopValue()
{
	return a[top];
}