/*
题目描述

对于一个递归函数w(a,b,c)

如果a<=0 or b<=0 or c<=0就返回值1.

如果a>20 or b>20 or c>20就返回w(20,20,20)

如果a<b并且b<c 就返回w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)

其它别的情况就返回w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)

这是个简单的递归函数，但实现起来可能会有些问题。当a,b,c均为15时，调用的次数将非常的多。你要想个办法才行.

absi2011 : 比如 w(30,-1,0)既满足条件1又满足条件2

这种时候我们就按最上面的条件来算

所以答案为1

输入输出格式

输入格式：
会有若干行整数.
并以-1，-1，-1结束.

输出格式：
输出若干行

格式:
[b]w(a,_b,_c)_=_你的输出(_代表空格)[/b]

输入输出样例

输入样例#1					输出样例#1
1 1 1						w(1, 1, 1) = 2
2 2 2						w(2, 2, 2) = 4
-1 -1 -1
*/

#include<iostream>
using namespace std;
long long a,b,c,results[100][100][100];

int Function(int a,int b,int c){
	//若未计算过，继续递归
	if(a <= 0 || b <= 0 || c <= 0)return 1;
	else if(a > 20 || b > 20 || c > 20)return Function(20,20,20);
	//递归计算过就返回原值,避免调用的次数将非常的多
	if(!results[a][b][c]){
		if(a < b && b < c)results[a][b][c] = Function(a,b,c-1) + Function(a,b-1,c-1) - Function(a,b-1,c);
		else results[a][b][c] = Function(a-1,b,c) + Function(a-1,b-1,c) + Function(a-1,b,c-1) - Function(a-1,b-1,c-1);
	}
	return results[a][b][c];
}

int main()
{
	//输入若干行整数，并以-1，-1，-1结束.
	while(true){
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1)break;
		cout << "w" << "(" << a << ", " << b << ", " << c << ")" << " = " << Function(a,b,c) << endl;
	}
	return 0;
}