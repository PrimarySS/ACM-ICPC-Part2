/*
题目描述

已知：Sn= 1＋1／2＋1／3＋…＋1／n。显然对于任意一个整数K，当n足够大的时候，Sn大于K。

现给出一个整数K（1<=k<=15），要求计算出一个最小的n；使得Sn＞K。

输入输出格式

输入格式：
一个正整数K。

输出格式：
一个正整数N。

输入输出样例

输入样例#1：
1
输出样例#1：
2
*/

#include<iostream>
using namespace std;

int main()
{
	int k,i = 0;
	long double s = 0;
	cin >> k;
	if(k >= 1 && k <= 15)
	{
		while(s <= k)
		{
			i++;
			s = s + 1.0/i;
		}
		cout << i << endl;
	}
	return 0;
}


