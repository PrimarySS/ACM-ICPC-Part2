/*
题目描述

有一只小鱼，它上午游泳150公里，下午游泳100公里，晚上和周末都休息（实行双休日)，
假设从周x(1<=x<=7)开始算起，请问这样过了n天以后，小鱼一共累计游泳了多少公里呢？

输入输出格式

输入格式：
输入两个整数x,n(表示从周x算起，经过n天，n在long int范围内）。

输出格式：
输出一个整数，表示小鱼累计游泳了多少公里。

输入输出样例

输入样例#1：
3 10
输出样例#1：
2000
*/

#include<iostream>
using namespace std;

int main()
{
	int x;
	long long n,s = 0;
	cin >> x >> n;

	for(long long day = 1; day <= n; day++)
	{
		if(x >= 1 && x <= 5)
			s += 250;
		if(x == 7)
			x = 1;
		else
			x++;
	}
	cout << s << endl;
	return 0;
}
