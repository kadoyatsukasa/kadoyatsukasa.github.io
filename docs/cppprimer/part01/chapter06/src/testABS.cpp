#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::abs;

double myABS(double);

int main() {
	double num;

	cout << "输入一个数字" << endl;
	cin >> num;

	cout << "库函数abs()求绝对值 " << abs(num) << endl;
	cout << "自定义myABS()求绝对值 " << myABS(num) << endl;

	return 0;
}

double myABS(double num) {
	if (num < 0) return -num;
	else return num;
}