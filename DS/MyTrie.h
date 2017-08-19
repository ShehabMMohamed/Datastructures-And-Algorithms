#ifndef DATASTRUCTURES_MYTRIE_H
#define DATASTRUCTURES_MYTRIE_H

//TODO: finish Trie methods definition.
class MyTrie {
private:
    const ALPHABET_SIZE = 256;
    struct trieNode {
        bool isLeaf;
        trieNode *children = new trieNode[ALPHABET_SIZE];
    };
    trieNode *root;

    void createNode();

public:
    void insertNode(const char *key);

    bool searchFor(const char *key);

};


#endif //DATASTRUCTURES_MYTRIE_H
