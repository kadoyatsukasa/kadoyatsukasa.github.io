#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//  [3/12/2020 Erik]
//	�Ƚ��������ֵĴ�С�������ؽϴ�ֵ
//
//	@param first ��һ����������ͨ����
//	@param second �ڶ���������ָ��
//	@return ���ؽϴ��һ������
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

	cout << "������������" << endl;
	cin >> first >> second;
	cout << "�ϴ����: " << compare(first, &second) << endl;
	return 0;
}