/*
题目描述

小组名和彗星名都以下列方式转换成一个数字：最终的数字就是名字中所有字母的积，
其中“A”是1，“Z”是26。例如，“USACO”小组就是21*19*1*3*15=17955。
如果小组的数字 mod 47等于彗星的数字mod 47,你就得告诉这个小组需要准备好被带走！

写出一个程序，读入彗星名和小组名并算出用上面的方案能否将两个名字搭配起来
如果能搭配，就输出“GO”，否则输出“STAY”。小组名和彗星名均是没有空格或
标点的一串大写字母（不超过6个字母）。

输入输出格式

输入格式：
第1行：一个长度为1到6的大写字母串，表示彗星的名字。
第2行：一个长度为1到6的大写字母串，表示队伍的名字。

输出格式：
输入输出样例

输入样例#1：
[输入1]							[输入2]
COMETQ							ABSTAR
HVNGAT							USACO

输出样例#1：
[输出1]							[输出2]
GO								STAY
*/

#include<iostream>
#include<string>
using namespace std;
char UFONAME[7],TEAMNAME[7];

int main()
{
	//输入彗星和队伍的名称
	gets_s(UFONAME);
	gets_s(TEAMNAME);
	//获得数组长度
	int UN_len = strlen(UFONAME);
	int TN_len = strlen(TEAMNAME);
	//算出彗星的能量值
	int UFOSUM = 1;
	for(int i = 0; i < UN_len; i++){
		UFONAME[i] -= 64;
		UFOSUM *= UFONAME[i];
	}
	//算出队伍的能量值
	int TEAMSUM = 1;
	for(int i = 0; i < TN_len; i++){
		TEAMNAME[i] -= 64;
		TEAMSUM *= TEAMNAME[i];
	}
	if(UFOSUM % 47 == TEAMSUM % 47)cout << "GO" << endl;
	else cout << "STAY" << endl;
	return 0;
}
