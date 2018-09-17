/**
题目描述
设有n个正整数，将他们连接成一排，组成一个最大的多位整数。
如:n=3时，3个整数13,312,343,连成的最大整数为34331213。
如:n=4时,4个整数7,13,4,246连接成的最大整数为7424613。
输入描述:
有多组测试样例，每组测试样例包含两行，第一行为一个整数N（N<=100），第二行包含N个数(每个数不超过1000，空格分开)。
输出描述:
每组数据输出一个表示最大的整数。
**/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	//把整数转换为字符串
	string a[101],t;
	cin >> n;
	//输入n个数
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	//比较a[j] + a[j+1]和a[j+1] + a[j]
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i -1; j++)
		{
			if (a[j] + a[j+1] > a[j+1] + a[j])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}

	//逆序输出排列后的字符数组
	for (int i = n - 1; i >= 0; i--)
	{
		cout << a[i];
	}
	cout << endl;

	return 0;

}
