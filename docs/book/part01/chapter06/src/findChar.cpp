#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;
using std::string;
using std::endl;

//返回s中c第一次出现的位置索引
//引用形参负责统计c出现的总次数
string::size_type
find_char(const string& s, char c, string::size_type& occurs) {
	auto ret = s.size(); //第一次出现的位置(如果有的话)
	occurs = 0;           //设置表现出现次数形参的值
	for (decltype(ret)i = 0; i != s.size(); ++i) {
		if (s[i] == c) {
			if (ret == s.size())
				ret = i;  //记录c第一次出现的位置
			++occurs;   //将出现的次数加一
		}
	}
	return ret;         //出现次数通过occurs隐式地返回
}
int main() {
	
	string source;
	char target;
	string::size_type occurs=0;

	cout << "录入一段文字" << endl;
	std::getline(cin,source);
	cout << "输入查找的字符" << endl;
	cin >> target;
	
	cout << "字符" << target << "在字符串\"" << source << "\"中第一次出现的索引是"
		<< find_char(source, target, occurs) << endl;

	return 0;
}