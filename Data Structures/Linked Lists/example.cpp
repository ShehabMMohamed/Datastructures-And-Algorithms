#include "LinkedList.h"

int main() {

	LinkedList<int> list;
	int A[] = {1, 5, 10, 15, 24, 30};
	int N = sizeof(A)/sizeof(A[0]);

	for(int i = 0; i < N; i++)
		list.insert_node_from_head(A[i]);

	for(int i = 0; i < N/2; i++)
		list.insert_node_from_tail(A[i]);

	list.show_list();
	
	list.delete_node_from_nth(3);
	list.delete_node_from_nth(1);
	list.delete_node_from_tail();
	
	list.show_list();
	
	return 0;
}