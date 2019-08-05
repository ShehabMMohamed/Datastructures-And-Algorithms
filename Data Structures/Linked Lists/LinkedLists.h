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

/*  Singly Linked List Implementation  */
/*
    insert_node_from_head()
    insert_node_from_nth()
    insert_node_from_tail()
    delete_node_from_head()
    delete_node_from_nth()
    delete_node_from_tail()
    reverse_list()
    show_list()
*/
template <typename T>
class LinkedList {
private:
    ListNode<T>* head;
    ListNode<T>* _create_node(T val) {
        return new ListNode<T>(val);
    }

public:
    LinkedList() : head(NULL) {};
    void insert_node_from_head(T val) {
        std::cout<<"Inserting node from head...\n";
        ListNode<T>* temp = _create_node(val);
        temp->next = head;
        head = temp;
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
    }
    void insert_node_from_tail(T val) {
        std::cout<<"Inserting node from tail...\n";
        ListNode<T>* runner = head;
        while(runner->next) 
            runner = runner->next;
        runner->next = _create_node(val);
    }

    void delete_node_from_head() {
        std::cout<<"Deleting node from head...\n";
        ListNode<T>* fwd = head;
        head = head->next;
        delete fwd;
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
    ~LinkedList() {
        delete head;
    }

};


#endif 
