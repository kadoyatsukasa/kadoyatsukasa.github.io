#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void mySwap(int& first,int& second) {
	int temp;			//中间变量
	temp = first;		//保存first的初始值
	first = second;		//把second的值给first
	second = temp;		//把first的初始值给second
}

int main() {
	int first;
	int second;

	cout << "输入两个整数" << endl;
	cin >> first >> second;

	cout << "交换位置后" << endl;
	mySwap(first, second); //取两个数的地址
	cout << first << " " <<second << endl;

	return 0;
}