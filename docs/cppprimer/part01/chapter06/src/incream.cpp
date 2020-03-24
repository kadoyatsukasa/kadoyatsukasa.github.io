#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//在外部进行循环调用
//然后进行递增
int incream(int count) {
	return count;
}

int main() {
	
	int times;

	cout << "输入循环次数" << endl;
	cin >> times;

	for (int i = 0; i <= times; i++)
		cout << "第" << i << "次调用:incream(" << i << "),返回值是" << incream(i) << endl;
	return 0;
}