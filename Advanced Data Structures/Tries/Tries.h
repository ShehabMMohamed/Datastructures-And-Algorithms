#include <string>
#ifndef TRIES_H
#define TRIES_H
#define ALPHA_SIZE 256

class TrieNode {
public:
	TrieNode *children[ALPHA_SIZE];    // size of the alphabet is 256.
	bool isEndOfWord;	// true if the node represents end of a word.
	TrieNode() : isEndOfWord(false) {
		for(int i = 0; i < ALPHA_SIZE; i++)
			children[i] = NULL;
	};
};

class Trie {
private:
    TrieNode *root;
    bool _search(TrieNode* root, std::string key) {
    	TrieNode* runner = root;
    	for(int i = 0; i < key.length(); i++) {
    		int indx = key[i] - 'a';
    		if(!runner->children[indx])
    			return false;
    		runner = runner->children[indx];
    	}
    	return (runner && runner->isEndOfWord);
    }

    void _insert(TrieNode* root, std::string key) {
    	TrieNode* runner = root;
    	for(int i = 0; i < key.length(); i++) {
    		int indx = key[i] - 'a';
    		if(!runner->children[indx])
    			runner->children[indx] = new TrieNode();
    		runner = runner->children[indx];
    	}
    	runner->isEndOfWord = true;
    }

    bool _have_children(TrieNode const* curr) {
    	for(int i = 0; i < ALPHA_SIZE; i++) {
    		if(curr->children[i])
    			return true;
    	}
    	return false;
    }

    bool _delete(TrieNode*& root, std::string key) {
    	if(!root)
            return false;
        if(key.length()) {
            int indx = key[0] - 'a';
            if(root && root->children[indx] && _delete(root->children[indx], key.substr(1))
                && !root->isEndOfWord) {
                if(!_have_children(root)) {
                    delete root;
                    root = NULL;
                    return true;
                } 
                else
                    return false;
            }
        }

        if(key.length() == 0 && root->isEndOfWord) {
            if(!_have_children(root)) {
                delete root;
                root = NULL;
                return true;
            }
            else {
                root->isEndOfWord = false;
                return false;
            }
        }
        return false;
    }

public:
	Trie() { root = new TrieNode();	}
    void Insert(std::string key) {	_insert(root, key);	}
    bool Search(std::string key) {	return _search(root, key);	}
    bool Delete(std::string key) {	return _delete(root, key);	}
    ~Trie() { delete root; }

};

#endif 
