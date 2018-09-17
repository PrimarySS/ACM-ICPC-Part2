/*
题目描述

又是一年秋季时，陶陶家的苹果树结了n个果子。陶陶又跑去摘苹果，这次她有一个a公分的椅子。当他手够不着时，他会站到椅子上再试试。

这次与NOIp2005普及组第一题不同的是：陶陶之前搬凳子，力气只剩下s了。当然，每次摘苹果时都要用一定的力气。陶陶想知道在s<0之前最多能摘到多少个苹果。

现在已知n个苹果到达地上的高度xi，椅子的高度a，陶陶手伸直的最大长度b，陶陶所剩的力气s，陶陶摘一个苹果需要的力气yi，求陶陶最多能摘到多少个苹果。

输入输出格式

输入格式：
第1行：两个数 苹果数n，力气s。

第2行：两个数 椅子的高度a，陶陶手伸直的最大长度b。

第3行~第3+n-1行：每行两个数 苹果高度xi，摘这个苹果需要的力气yi。

输出格式：
只有一个整数，表示陶陶最多能摘到的苹果数。

输入输出样例

输入样例#1： 复制
8 15
20 130
120 3
150 2
110 7
180 1
50 8
200 0
140 3
120 2
输出样例#1： 复制
4
*/

#include<iostream>
using namespace std;

int main()
{
	int appleToFloorAways[5000];
	int needs[100];
	//苹果的个数//剩余摘苹果的力气//凳子的高度//伸手的高度
	int n,s,a,b;
	cin >> n >> s >> a >> b;

	//输入苹果的离地高度和需要摘其的力气值
	for(int i = 0; i < n; i++)cin >> appleToFloorAways[i] >> needs[i];

	//陶陶能摸到的高度
	int taoTouchHeight = a + b;

	//找出能摘到的苹果的力气值
	int totals = 0,apples = 0;
	for(int i = 0 ; i < n ; i++){
		if(taoTouchHeight >= appleToFloorAways[i]){
			totals += needs[i];
			if(totals <= s)apples++;
			else totals -= needs[i];
		}
	}
	cout << apples << endl;
	return 0;
}
