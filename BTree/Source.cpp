// In The Name Of Allah

#include "BTree.h"
#include <conio.h>

int main()
{
	BTree BT;

	BT.addNode(1, 0, true);
	BT.addNode(2, 1, false);
	BT.addNode(3, 1, true);
	BT.addNode(4, 2, false);
	BT.addNode(5, 2, true);
	BT.addNode(6, 3, false);
	BT.addNode(7, 3, true);
	BT.addNode(8, 4, false);
	BT.addNode(9, 4, true);
	BT.addNode(10, 5, false);
	BT.addNode(11, 5, true);
	BT.addNode(12, 6, false);
	BT.addNode(13, 6, true);
	BT.addNode(14, 7, false);
	BT.addNode(15, 7, true);

	cout << "\nDepth Of Binary Tree :\t" << BT.depth() << "\n\n" << endl;

	cout << "BFS :\t";
	BT.BFS();
	cout << "\n\n" << endl;

	cout << "\t/ VLR :\t  ";
	BT.DFS("VLR");
	cout << endl << endl;
	cout << "DFS\t- LVR :\t  ";
	BT.DFS("LVR");
	cout << endl << endl;
	cout << "\t\\ LRV :\t  ";
	BT.DFS("LRV");
	cout << "\n\n" << endl;

	cout << "\nLevel Show :\n" << endl;
	BT.show();
	cout << endl << endl;

	cout << "\nPress any key to exit...";
	while (!_kbhit());
	return EXIT_SUCCESS;
}