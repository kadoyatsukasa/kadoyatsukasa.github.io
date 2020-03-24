#include <iostream>
using std::cout;
using std::cin;
using std::endl;

uint64_t rfact(uint64_t);


int main() {
	uint64_t num;

	cout << "输入一个整数:" << endl;
	cin >> num;

	cout << num << " = " << rfact(num) << "!" << endl;
	return 0;
}

//
//题目要求的是逆向将一个数分解为它的阶乘数字
//思路就是逆向将一个数字从1开始除,并取得最大的数
uint64_t rfact(uint64_t val) {
	uint64_t ret;

	for (ret=1;ret<val;ret++)
	{
		val /= ret;
	}

	return ret;
} 