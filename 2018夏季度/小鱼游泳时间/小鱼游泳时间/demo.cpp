/*
题目描述

这一天,小鱼给自己的游泳时间做了精确的计时（本题中的计时都按24小时制计算），
它发现自己从a时b分一直游泳到当天的c时d分，请你帮小鱼计算一下，
它这天一共游了多少时间呢？

输入输出格式

输入格式：
一行内输入4个整数，分别表示a,b,c,d。

输出格式：
一行内输出2个整数e和f，用空格间隔，依次表示小鱼这天一共游了多少小时多少分钟。
其中表示分钟的整数f应该小于60。

输入输出样例

输入样例#1：
12 50 19 10
输出样例#1：
6 20
*/

#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	int star = 0,end = 0,hour = 0,minute = 0;
	int totalminute = 0;
	cin >> a >> b >> c >> d;
	star = a * 60 + b;
	end =  c * 60 + d;
	totalminute = end - star;
	hour = totalminute / 60;
	minute = totalminute % 60;
	cout << hour << " " << minute << endl;
	return 0;
}
