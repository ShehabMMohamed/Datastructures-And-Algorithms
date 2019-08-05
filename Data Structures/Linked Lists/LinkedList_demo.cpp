#include "LinkedLists.h"

int main() {
	LinkedList<int> list;
	for(int i = 1; i <= 5; i++)
		list.insert_node_from_head(i);
	list.show_list();
	list.delete_node_from_nth(3);
	list.show_list();
	list.delete_node_from_nth(1);
	list.show_list();
	list.delete_node_from_tail();
	list.show_list();
	return 0;
}