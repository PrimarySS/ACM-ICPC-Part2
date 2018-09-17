/*
题目描述

因为151既是一个质数又是一个回文数(从左到右和从右到左是看一样的)，所以 151 是回文质数。

写一个程序来找出范围[a,b](5 <= a < b <= 100,000,000)( 一亿)间的所有回文质数;

输入输出格式

输入格式：
第 1 行: 二个整数 a 和 b .

输出格式：
输出一个回文质数的列表，一行一个。

输入输出样例

输入样例#1： 复制						输出样例#1： 复制
5 500									5
										7
										11
										101
										131
										151
										181
										191
										313
										353
										373
										383
*/

#include<iostream>
using namespace std;
long long a,b;

//判断是否为质子数的方法体
bool IsPrime(long long num){
	for(int division = 2; division <= num / 2; division++){
		if(num % division == 0)return false;
	}
	return true;
}

//判断回文数
void IsReturn(){
	for(long long i = a; i <= b; i++){
		long long rem = 0,reverse = 0,temp = i;
		while(temp != 0){
			rem = temp % 10;
			reverse = reverse * 10 + rem;	//倒置整数
			temp /= 10;
		}
		if(i == reverse && IsPrime(i))cout << i << endl;
	}
}

int main()
{
	//输入区间值
	cin >> a >> b;
	IsReturn();
	return 0;
}
