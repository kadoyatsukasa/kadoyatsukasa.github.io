#include "chapter06.h"
using std::cout;
using std::endl;
using std::cin;

int main() {
	uint64_t num;
	cout << "����һ������:" << endl;
	cin >> num;
	cout << num << "! = " << fact(num) << endl;
	return 0;
}
