/*
题目描述
先给出一个奇数n，要求输出3个质数，这3个质数之和等于输入的奇数。

输入输出格式

输入格式：
仅有一行，包含一个正奇数n，其中9<n<20000

输出格式：
仅有一行，输出3个质数，这3个质数之和等于输入的奇数。
相邻两个质数之间用一个空格隔开，最后一个质数后面没有空格。
如果表示方法不唯一，请输出第一个质数最小的方案，如果第一个质数最小的方案不唯一，
请输出第一个质数最小的同时，第二个质数最小的方案。

输入输出样例			
输入样例#1				输出样例#1
2009					3 3 2003
*/

#include<iostream>
using namespace std;

//判断是否为质子数
bool IsPrime(int num){
	for(int division = 2; division <= num / 2; division++){
		if(num % division == 0)return false;
	}
	return true;
}

int main()
{
	int n;
	//输入整奇数
	cin >> n;
	//找出三个质子数
	bool flag = 1;
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= n; j++){
			for(int k = 2; k <= n; k++){
				if(IsPrime(i) && IsPrime(j) && IsPrime(k)){
					if((i + j + k) == n){
						cout << i << " " << j << " " << k << endl;
						return 0 ;
					}
				}
			}
		}
	}
}
