#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

//  [3/12/2020 Erik]
//求初始化列表的数值总和
//
//		@param numbers 初始化列表
//		@return 列表数据总和
int sum(initializer_list<int> numbers) {

	initializer_list<int>::iterator num_iter;
	int result = 0;

	for (num_iter = numbers.begin(); num_iter != numbers.end(); ++num_iter)
		result += *num_iter;
	return result;
}

int main() {
	initializer_list<int> numbers{1,2,3,4,5,6,7,8,9};
	initializer_list<int>::iterator num_iter;

	cout << "初始化列表" << endl;

	for (num_iter = numbers.begin(); num_iter != numbers.end(); ++num_iter)
		cout << *num_iter << " ";
	cout << endl;

	cout << "数值总和" << sum(numbers) << endl;

	return 0;

}