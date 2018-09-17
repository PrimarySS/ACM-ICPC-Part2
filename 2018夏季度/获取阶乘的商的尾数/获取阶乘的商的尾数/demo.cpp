/*
	As the answer can be quite large, it would be enough for Koyomi just to know the last digit of the
	answer in decimal representation. And you're here to provide Koyomi with this knowledge.

	Input
	The first and only line of input contains two space-separated integers a and b (long long).

	Output
	Output one line containing a single decimal digit — the last digit of the value that interests Koyomi.

	Examples
	input
	2 4
	output
	2
	input
	0 10
	output
	0
*/

#include<iostream>
using namespace std;

int main()
{
	long long a,b,aSum = 1,bSum = 1;
	//输入a,b阶乘的阶数
	cin >> a >> b;
	//获得a阶乘的值
	for(long long i = 1; i <= a; i++)
	{
		aSum = aSum * i;
	}

	//获得b阶乘的值
	for(long long i = 1; i <= b; i++)
	{
		bSum = bSum * i;
	}

	//获得a,b阶乘的商
	long long finalSum = bSum / aSum;
	//输出阶乘商的个位数
	cout << finalSum % 10 << endl;
	return 0;
}
