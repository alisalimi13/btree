// In The Name Of Allah

#include <iostream>
#include "STK.h"

using namespace std;

class Queue
{
private:
	node *a[100];
	int size;
	int front;
	int back;

public:
	Queue();
	void push(node*);
	node* pop();
	int showFront();
	int showBack();
	node* showFrontValue();
	node* showBackValue();
};

Queue::Queue()
{
	size = 100;
	front = 0;
	back = -1;
}

void Queue::push(node* n)
{
	if (!n)
		return;

	if (back >= size - 1)
	{
		cout << "Queue is Full.";
		return;
	}

	a[++back] = n;
	return;
}

node* Queue::pop()
{
	if (front > back)
	{
		cout << "Queue is Empty.";
		node *t = nullptr;
		return t;
	}

	return a[front++];
}

int Queue::showFront()
{
	return front;
}

int Queue::showBack()
{
	return back;
}

node* Queue::showFrontValue()
{
	return a[front];
}

node* Queue::showBackValue()
{
	return a[back];
}