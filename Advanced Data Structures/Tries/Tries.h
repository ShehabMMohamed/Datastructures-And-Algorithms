#ifndef TRIES_H
#define TRIES_H

#define ALPHABET_SIZE 256

class TrieNode {
public:
	TrieNode *children = new TrieNode[ALPHABET_SIZE];
	bool isLead;
	TrieNode() {};
};

class MyTrie {
private:
    TrieNode *root;

public:
    void insertNode(const char *key);
    bool searchFor(const char *key);

};


#endif 
