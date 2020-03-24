#include<iostream>
#include<string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[]) {
	string output;

	
	for (int index=1;index<=argc;++index)
		output += argv[index];
	
	cout << output << endl;
	return 0;
}