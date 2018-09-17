/*
题目描述

蒟蒻虽然忘记密码，但他还记得密码是由一串字母组成。且密码是由一串字母每个向后移动n为形成。
z的下一个字母是a，如此循环。他现在找到了移动前的那串字母及n，请你求出密码。(均为小写)

输入输出格式

输入格式：
第一行：n。第二行：未移动前的一串字母

输出格式：
一行，是此蒟蒻的密码

输入输出样例

输入样例#1：			输出样例#1：
1						rxf
qwe
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	string str;
	cin >> n;	//输入移动位置的n
	cin >> str;	//输入未移动的字符串

	//移动获得密码
	/*出错原因分析:detector是一个Vector容器,detecot.size()在容器说明中被定义为:
	unsigned int类型,而j是int类型所以会出现:有符号/无符号不匹配警告*/
	for(unsigned i = 0; i < str.size(); i++){
		str[i] += n;
		if(str[i] > 'z')str[i] = ('a' - 1) + (str[i] - 'z');
	}
	for(unsigned i = 0; i < str.size(); i++)cout << str[i];
	cout << endl;
	return 0;
}
