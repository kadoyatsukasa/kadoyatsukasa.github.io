#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool isAnyUpper(const string& source);
string convertToLower(string& source);

int main() {
	string source;

	cout << "�����ַ���" << endl;
	std::getline(cin,source);

	if (!isAnyUpper(source))
		cout << "��û�з��ִ�д��ĸ" << endl;
	else {
		cout << "���ִ�д��ĸ����дΪСд��ĸ" << endl;
		cout << convertToLower(source);
	}
}
//  [3/12/2020 Erik]
//	�ж��ַ������Ƿ���ڴ�д
//	@param source ��Ҫ����Դ�ַ���
//	@return ���û�д�д���򷵻�true�����򷵻�false
bool isAnyUpper(const string& source) {
	auto ret = source.size();
	for (int index=0;index!=source.size();++index)
		if (std::isupper(source[index])) //�ж��Ƿ���ڴ�д
			return true;
	return false;
}

//  [3/12/2020 Erik]
//  ���ַ�����������ĸ��ת����Сд
// 
// @param source ��Ҫת����Դ�ַ���
// @return ת����ɵ��ַ���
string convertToLower(string& source) {
	for (int index=0;index!=source.size();++index) //�����ַ���
		 source[index]=std::tolower(source[index]); //��������ĸ��ת����Сд��ĸ
		
	return source;
}
