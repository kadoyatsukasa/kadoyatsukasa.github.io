#include <iostream>
using std::cout;
using std::cin;
using std::endl;

uint64_t rfact(uint64_t);


int main() {
	uint64_t num;

	cout << "����һ������:" << endl;
	cin >> num;

	cout << num << " = " << rfact(num) << "!" << endl;
	return 0;
}

//
//��ĿҪ���������һ�����ֽ�Ϊ���Ľ׳�����
//˼·��������һ�����ִ�1��ʼ��,��ȡ��������
uint64_t rfact(uint64_t val) {
	uint64_t ret;

	for (ret=1;ret<val;ret++)
	{
		val /= ret;
	}

	return ret;
} 