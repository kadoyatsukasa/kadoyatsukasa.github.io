#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void mySwap(int& first,int& second) {
	int temp;			//�м����
	temp = first;		//����first�ĳ�ʼֵ
	first = second;		//��second��ֵ��first
	second = temp;		//��first�ĳ�ʼֵ��second
}

int main() {
	int first;
	int second;

	cout << "������������" << endl;
	cin >> first >> second;

	cout << "����λ�ú�" << endl;
	mySwap(first, second); //ȡ�������ĵ�ַ
	cout << first << " " <<second << endl;

	return 0;
}