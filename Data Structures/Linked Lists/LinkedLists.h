#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include "../Stacks and Queues/Stacks.h"

template <typename T>
class ListNode {
public:
    T val;
    ListNode* next;
    ListNode() : next (NULL) {};
};

template <typename T>
class LinkedList {
private:
    ListNode* head;
    ListNode* createNode(T data) {
    	ListNode* node = new ListNode;
    	node->val = data;
    }
    void deleteNode(int pos) {
    	//TODO.
    }

public:
    LinkedList() : root(NULL) {};
    void InsertNode(const T& e) {
    	//TODO.
    };
    void DeleteNode(const T& e) {
    	//TODO.
    };
    void ReverseList() {
    	Stack<T> s;
    	ListNode* runner = head;
    	while(runner) {
    		s.push(runner->val);
    		runner = runner->next;
    	}
    	runner = head;
    	while(!s.isEmpty()) {
    		//TODO.
    	}
    };
    ~LinkedList() { delete head; };
};

#endif 
