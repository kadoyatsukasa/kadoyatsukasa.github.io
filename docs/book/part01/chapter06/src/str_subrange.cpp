//  [3/12/2020 Erik]
/**
 * ���󷵻�ֵ
 */
#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

//  [3/12/2020 Erik]
//��Ϊ���в���ȷ�ķ���ֵ,������δ����޷�ͨ������
bool str_subrange(const string& str1, const string& str2) {
    if (str1.size() == str2.size())
        return str1 == str2;
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    for (decltype(size) i =0;i!=size;++i)
        if (str1[i] != str2[i])
            return; //����#1 ��û�з���ֵ,��������������һ����

    //����#2��������������δ�����κ�ֵ�ͽ����˺�����ִ��
    //���������ܼ�鲻����һ����
}

int main() {
    string str1 = "hello";
    string str2 = "world";

    str_subrange(str1, str2);
   

    return 0;
}
