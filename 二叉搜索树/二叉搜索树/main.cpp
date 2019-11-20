#include "BSTree.h"
#include <iostream>
using namespace std;

int main()
{
	BinarySortTree<int> bst;
	bst.insert(5.0);
	bst.insert(2);
	bst.insert(8);
	bst.insert(0);
	bst.insert(1);
	bst.insert(4);
	bst.insert(7);
	bst.insert(9);
	bst.insert(3);
	bst.insert(6);
	bst.insert(1.8);

	bst.erase(5);
	return 0;
}