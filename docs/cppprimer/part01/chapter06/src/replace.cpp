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

	cout << "输入字符串" << endl;
	std::getline(cin,source);

	if (!isAnyUpper(source))
		cout << "并没有发现大写字母" << endl;
	else {
		cout << "发现大写字母，改写为小写字母" << endl;
		cout << convertToLower(source);
	}
}
//  [3/12/2020 Erik]
//	判断字符串中是否存在大写
//	@param source 需要检测的源字符串
//	@return 如果没有大写，则返回true，否则返回false
bool isAnyUpper(const string& source) {
	auto ret = source.size();
	for (int index=0;index!=source.size();++index)
		if (std::isupper(source[index])) //判断是否存在大写
			return true;
	return false;
}

//  [3/12/2020 Erik]
//  将字符串中所有字母都转化成小写
// 
// @param source 需要转换的源字符串
// @return 转换完成的字符串
string convertToLower(string& source) {
	for (int index=0;index!=source.size();++index) //遍历字符串
		 source[index]=std::tolower(source[index]); //将所有字母都转换成小写字母
		
	return source;
}
