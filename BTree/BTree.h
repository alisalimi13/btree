// In The Name Of Allah

#include "Queue.h"

class BTree
{
private:
	node *root;
	int numOfVer;

public:
	BTree();
	~BTree();
	node* search(int);
	void addNode(int, int, bool);
	void delNode(int);
	void VLR(node*);
	void LVR(node*);
	void LRV(node*);
	void DFS(string);
	void BFS();
	int depth();
	void show();
};

BTree::BTree()
{
	root = nullptr;
	numOfVer = 0;
}

BTree::~BTree()
{
	root = nullptr;
	numOfVer = 0;
}

node* BTree::search(int data)
{
	STK stk;
	node *p;
	stk.push(root);
	p = root;

	while (p)
	{
		if (p->D == data)
			break;
		stk.push(p->R);
		stk.push(p->L);
		p = stk.pop();
	}

	return p;
}

void BTree::addNode(int data, int pdata, bool rol)
{
	if (!root)
	{
		root = new node;
		root->D = data;
		numOfVer++;
		return;
	}

	if (search(pdata))
	{
		((rol ? search(pdata)->R : search(pdata)->L) = new node)->D = data;
		numOfVer++;
	}

	return;
}

void BTree::VLR(node* n)
{
	if (n != nullptr)
	{
		cout << n->D << ' ';
		VLR(n->L);
		VLR(n->R);
	}
	return;
}

void BTree::LVR(node* n)
{
	if (n != nullptr)
	{
		LVR(n->L);
		cout << n->D << ' ';
		LVR(n->R);
	}
	return;
}

void BTree::LRV(node* n)
{
	if (n != nullptr)
	{
		LRV(n->L);
		LRV(n->R);
		cout << n->D << ' ';
	}
	return;
}

void BTree::DFS(string surveyMode)
{
	if (!root)
	{
		cout << "Tree is Empty.";
		return;
	}

	if (surveyMode == "VLR")
		VLR(root);
	else if (surveyMode == "LVR")
		LVR(root);
	else if (surveyMode == "LRV")
		LRV(root);

	return;
}

void BTree::BFS()
{
	if (!root)
	{
		cout << "Tree is Empty.";
		return;
	}

	Queue q;
	node *n;

	q.push(root);

	while (q.showFront() <= q.showBack())
	{
		n = q.pop();
		cout << n->D << ' ';
		q.push(n->L);
		q.push(n->R);
	}

	return;
}

int BTree::depth()
{
	int depth = -1;

	if (!root)
	{
		cout << "\nTree is Empty.\n";
		return -1;
	}

	Queue q;
	node *n;
	q.push(root);

	for (int j = 1; q.showFront() <= q.showBack(); j *= 2)
	{
		for (int i = 0; i < j && q.showFront() <= q.showBack(); i++)
		{
			n = q.pop();
			q.push(n->L);
			q.push(n->R);
		}
		depth++;
	}

	return depth;
}

void BTree::show()
{
	if (!root)
	{
		cout << "Tree is Empty.";
		return;
	}

	Queue q;
	node *n;
	q.push(root);

	for (int j = 1 ; q.showFront() <= q.showBack(); j *= 2)
	{
		for (int i = 0; i < j && q.showFront() <= q.showBack(); i++)
		{
			n = q.pop();
			cout << n->D << ' ';
			q.push(n->L);
			q.push(n->R);
		}
		cout << endl;
	}
}