#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void life(int param) {
	static int localStaticVal=2;
	int val=3;
	cout << "形参" << param << endl;
	cout << "局部变量" << val<<endl;
	cout << "静态局部变量" << localStaticVal << endl;
}

int main() {

	cout << "life()函数开始" << endl;
	life(1);
	cout << "life()函数结束" << endl;
	//cout << localStaticVal << endl;
	
	return 0;
}