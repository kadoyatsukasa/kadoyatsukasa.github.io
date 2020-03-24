#include <iostream>
using std::cout;
using std::endl;
using std::cin;

uint64_t fact(uint64_t val);

int main() {
	uint64_t num;
	cout << "输入一个整数:" << endl;
	cin >> num;
	cout << num << "! = " << fact(num) << endl;
	return 0;
}

uint64_t fact(uint64_t val) {
	uint64_t ret;

	for (ret=1;val>1;val--)
		ret *= val;

	return ret;
}