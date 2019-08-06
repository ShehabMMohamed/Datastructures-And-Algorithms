#include "RedBlackTrees.h"

using namespace std;

int main() {
	int test_case [20] = {20,23,3,7,10,26,41,15,17,21,12,14,16,19,30,28,38,35,47,39};
	RedBlackTree tree;
	for(int& key : test_case)
		tree.InsertKey(key);

	// Prints the sorted keys in the RBT.
	tree.InOrderTraversal();

	// writes a tree-like format in a .txt file called (tree_display.txt)
	tree.SaveTree();

	// Searching for keys.
	tree.SearchKey(16);
	tree.SearchKey(22);

	return 0;
}