#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//传引用
void reset(int& num) {
	
	num = 0;
}

int main() {
	int num;
	cout<<"输入整数"<<endl;
	cin >> num;
	cout << "置零" << endl;
	reset(num);
	cout << num << endl;
	return 0;
}