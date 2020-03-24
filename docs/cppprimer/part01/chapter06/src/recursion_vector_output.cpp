#include<iostream>
#include<vector>

using std::cout;
using std::endl;
using std::vector;

void print_vector(vector<int> &ivec) {
	static auto sz = ivec.size();
	if (sz != 0) {
		cout << ivec[--sz];
		print_vector(ivec);
	}
}


int main() {
	vector<int> ivec{ 1,2,3,4,5 };

	print_vector(ivec);
	return 0;
}