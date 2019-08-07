#include <iostream>
#include <vector>
#include <algorithm>

void bucket_sort(std::vector<float>& A) {
	int n = 10;
	std::vector<float> buckets[n];
	for(int i = 0; i <A.size(); i++) {
		int bi = n * A[i];
		buckets[bi].push_back(A[i]);
	}
	for(auto bucket : buckets)
		std::sort(bucket.begin(), bucket.end());

	int index = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < buckets[i].size(); j++)
			A[index++] = buckets[i][j];

}


int main() {
	std::vector<float> test_case = {0.23, 0.34, 0.44, 0.87, 0.91, 0.167};

	auto print = [](const float& f) {
		std::cout<<f<<" ";
	};

	std::cout<<"Unsorted list...\n";
	for_each(test_case.begin(), test_case.end(), print);
	std::cout<<std::endl;

	bucket_sort(test_case);

	std::cout<<"Sorted list...\n";
	for_each(test_case.begin(), test_case.end(), print);
	std::cout<<std::endl;

	return 0;
}