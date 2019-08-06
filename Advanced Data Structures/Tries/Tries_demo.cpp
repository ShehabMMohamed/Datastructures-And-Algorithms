#include <iostream>
#include <string>
#include "Tries.h"

int main() {

	std::string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	int n = sizeof(keys) / sizeof(keys[0]);

	Trie* head = new Trie();
	for(std::string& key : keys)
		head->Insert(key);

	std::cout<<"Is the key \"the\" in the current trie?\n";
	std::cout<<std::boolalpha<<head->Search("the")<<std::endl;

	std::cout<<"Is the key \"these\" in the current trie?\n";
	std::cout<<std::boolalpha<<head->Search("these")<<std::endl;

	std::cout<<"Is the key \"a\" in the current trie?\n";
	std::cout<<std::boolalpha<<head->Search("a")<<std::endl;

	

	return 0;
}