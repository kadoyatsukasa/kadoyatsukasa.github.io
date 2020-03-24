#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//  [3/12/2020 Erik]
//	比较两个数字的大小，并返回较大值
//
//	@param first 第一个参数是普通变量
//	@param second 第二个参数是指针
//	@return 返回较大的一个数字
int compare(int first, int* second) {
	int result;
	
	if (first > *second)
		result = first;
	else
		result = *second;
	return result;
}

int main() {
	int first;
	int second;

	cout << "输入两个整数" << endl;
	cin >> first >> second;
	cout << "较大的数: " << compare(first, &second) << endl;
	return 0;
}