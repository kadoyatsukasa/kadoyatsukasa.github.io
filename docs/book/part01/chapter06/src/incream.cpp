#include<iostream>

using std::cout;
using std::cin;
using std::endl;

//���ⲿ����ѭ������
//Ȼ����е���
int incream(int count) {
	return count;
}

int main() {
	
	int times;

	cout << "����ѭ������" << endl;
	cin >> times;

	for (int i = 0; i <= times; i++)
		cout << "��" << i << "�ε���:incream(" << i << "),����ֵ��" << incream(i) << endl;
	return 0;
}