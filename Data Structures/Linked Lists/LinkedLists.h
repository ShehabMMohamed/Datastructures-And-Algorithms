#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include <iostream>

template <typename T>
class ListNode {
public:
    T val;
    ListNode* next;
    ListNode(T _val) : val(_val), next (NULL) {};
};

/*      Singly Linked List Implementation       */

template <typename T>
class LinkedList {
private:
    ListNode<T>* head;
    ListNode<T>* _create_node(T val) {
        return new ListNode<T>(val);
    }
    int len;

public:
    LinkedList() : head(NULL), len(0) {};
    void insert_node_from_head(T val) {
        std::cout<<"Inserting node from head...\n";
        ListNode<T>* temp = _create_node(val);
        temp->next = head;
        head = temp;
        len++;
    }
    void insert_node_from_nth(int position, T val) {
        if (position == 1) {
            insert_node_from_head(val);
            return;
        }
        std::cout<<"Inserting node from ("<<position<<") position...\n";
        ListNode<T>* runner = head;
        ListNode<T>* prev = NULL;
        while(position != 1 && runner) {
            prev = runner;
            runner = runner->next;
            position--;
        }
        prev->next = _create_node(val);
        prev->next->next = runner;
        len++;
    }
    void insert_node_from_tail(T val) {
        std::cout<<"Inserting node from tail...\n";
        ListNode<T>* runner = head;
        while(runner->next) 
            runner = runner->next;
        runner->next = _create_node(val);
        len++;
    }

    void delete_node_from_head() {
        std::cout<<"Deleting node from head...\n";
        ListNode<T>* fwd = head;
        head = head->next;
        delete fwd;
        len--;
    }
    void delete_node_from_nth(int position) {
        if(position == 1) {
            delete_node_from_head();
            return;
        }
        std::cout<<"Deleting node from ("<<position<<") position...\n";
        ListNode<T>* runner = head;
        ListNode<T>* prev = NULL;
        while(position != 1 && runner) {
            prev = runner;
            runner = runner->next;
            position--;
        }
        prev->next = runner->next;
        runner->next = NULL;
        delete runner;
        len--;
    }
    void delete_node_from_tail() {
        std::cout<<"Deleting node from tail...\n";
        ListNode<T>* runner = head;
        ListNode<T>* prev = NULL;
        while(runner->next) {
            prev = runner;
            runner = runner->next;
        }
        prev->next = NULL;
        delete runner;
        len--;
    }
    void show_list() {
        ListNode<T>* runner = head;
        std::cout<<"Showing current list...\n";
        while(runner) {
            std::cout<<runner->val<<" -> ";
            runner = runner->next;
        }
        std::cout<<"NULL\n";
    }
    bool is_empty() {
        return len == 0;
    }
    int get_size() {
        return len;
    }
    ~LinkedList() {
        delete head;
    }
};

#endif 
