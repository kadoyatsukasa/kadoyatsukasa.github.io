#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;
using std::string;
using std::endl;

//����s��c��һ�γ��ֵ�λ������
//�����βθ���ͳ��c���ֵ��ܴ���
string::size_type
find_char(const string& s, char c, string::size_type& occurs) {
	auto ret = s.size(); //��һ�γ��ֵ�λ��(����еĻ�)
	occurs = 0;           //���ñ��ֳ��ִ����βε�ֵ
	for (decltype(ret)i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;  //��¼c��һ�γ��ֵ�λ��
			++occurs;   //�����ֵĴ�����һ
		}
	}
	return ret;         //���ִ���ͨ��occurs��ʽ�ط���
}
int main() {
	
	string source;
	char target;
	string::size_type occurs=0;

	cout << "¼��һ������" << endl;
	std::getline(cin,source);
	cout << "������ҵ��ַ�" << endl;
	cin >> target;
	
	cout << "�ַ�" << target << "���ַ���\"" << source << "\"�е�һ�γ��ֵ�������"
		<< find_char(source, target, occurs) << endl;

	return 0;
}