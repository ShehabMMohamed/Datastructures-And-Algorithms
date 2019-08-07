#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <functional>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void shuffle(std::vector<int>& A) {
	for(int i = 0; i < A.size(); i++) {
		int j = rand() % A.size();
		swap(A[j], A[i]);
	}
}

int main() {
	std::vector<int> test_case = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	auto print = [](int& e) {
		std::cout<<e<<" ";
	};
	std::for_each(test_case.begin(), test_case.end(), print);
	std::cout<<std::endl;
	shuffle(test_case);
	std::for_each(test_case.begin(), test_case.end(), print);
	std::cout<<std::endl;
	return 0;

}