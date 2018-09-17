/*
题目描述

已知 n 个整数 x1,x2,…,xn，以及一个整数 k（k＜n）。从 n 个整数中任选 k 个整数相加，
可分别得到一系列的和。例如当 n=4，k＝3，4 个整数分别为 3，7，12，19 时，可得全部的组合与它们的和为：

3＋7＋12=22

3＋7＋19＝29

7＋12＋19＝38

3＋12＋19＝34。

现在，要求你计算出和为素数共有多少种。

例如上例，只有一种的和为素数：3＋7＋19＝29）。

输入输出格式

输入格式：										输出格式：
n , k （1<=n<=20，k＜n）						一个整数（满足条件的种数）。
x1,x2，…,xn （1<=xi<=5000000）

输入输出样例

输入样例#1：									输出样例#1：
4 3												1
3 7 12 19
*/

#include<iostream>
using namespace std;
int ans = 0,number[20],n,k;

//判断是否为素数方法体
bool isPrime(int add){
	for(int divisor = 2; divisor <= add / 2; divisor++){
		if(add % divisor == 0)return false;
	}
	return true;
}

//求和方法体
void dfs(int m,int i,int sum){
	//直到得到三个数的组合
	if(!m){
		if(isPrime(sum))ans++;
		return ;
	}
	//获得整数组合
	for(i; i <= n; i++){
		dfs(m - 1,i + 1,sum + number[i]);
	}
}

int main()
{
	//输入整数的个数和任意求和个数
	cin >> n >> k;
	//输入n个整数
	for(int i = 1; i <= n; i++)cin >> number[i];
	dfs(k,1,0);
	cout << ans << endl;
	return 0;
}