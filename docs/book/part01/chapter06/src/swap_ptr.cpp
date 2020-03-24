#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//  [3/12/2020 Erik]
//交换两个指针
//
//	@param first 第一个指针
//	@param second 第二个指针
void swap_ptr(int *&first, int *&second) {
	int* temp;
	temp = first;
	first = second;
	second = temp;
}

int main() {
	int first;
	int second;
	int* first_ptr = &first;
	int* second_prt = &second;

	cout << "输入两个数" << endl;
	cin >> first >> second;
	cout << endl;

	//初始值
	cout << "first = " << first << " , second = " << second << endl;
	cout << "*first_ptr = " << *first_ptr << " , *second_ptr = " << *second_prt << endl;
	cout << "first_ptr =" << first_ptr << " , second_ptr = " << second_prt << endl;
	cout << "&first = " << &first << " , &second = " << &second << endl;
	cout << endl;

	cout << "交换位置" << endl;
	swap_ptr(first_ptr, second_prt);
	
	//验证
	cout <<"first = " <<first<<" , second = " << second<<endl;
	cout <<"*first_ptr = "<<*first_ptr <<" , *second_ptr = " <<*second_prt << endl;
	cout << "first_ptr =" << first_ptr << " , second_ptr = " << second_prt << endl;
	cout << "&first = " << &first << " , &second = " << &second << endl;
} 