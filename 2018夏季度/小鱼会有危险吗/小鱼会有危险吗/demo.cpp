/*
题目描述

有一次，小鱼要从A处沿直线往右边游，小鱼第一秒可以游7米，从第二秒开始每秒游的距离
只有前一秒的98%。有个极其邪恶的猎人在距离A处右边s米的地方，安装了一个隐蔽的探测器，
探测器左右x米之内是探测范围。一旦小鱼进入探测器的范围，探测器就会在这一秒结束时
把信号传递给那个猎人，猎人在一秒后就要对探测器范围内的水域进行抓捕，这时如果小鱼
还在这范围内就危险了。也就是说小鱼一旦进入探测器范围，如果能在下1秒的时间内马上游出
探测器的范围，还是安全的。现在给出s和x的数据，请你判断小鱼会不会有危险？
如果有危险输出'y'，没有危险输出'n'。

输入输出格式
输入格式：
一行内输入两个实数，用空格分隔，表示s和x。均不大于100

输出格式：
一行内输出'y'或者'n'表示小鱼是否会有危险。

输入输出样例
输入样例#1：			输出样例#1：
14 1					n
*/

#include<iostream>
using namespace std;
int s,x;
double font = 7.0,fs = 7.0;

//进入危险区方法体
void dangerous(){
	font = font * 0.98;
	fs = fs + font;
	if(fs > (s + x))cout << "n" << endl;
	else cout << "y" << endl;
}

int main()
{
	//输入起点到探测器的距离和探测器的探测半径
	cin >> s >> x;
	//当第一秒进入危险区的情况
	if(font >= (s - x))dangerous();
	//当第一秒没有进入危险区
	else {
		while(fs < (s - x)){
			font = font * 0.98;
			fs = fs + font;
		}
		dangerous();	//进入危险区后下一秒能否逃出
	}
	return 0;
}


//double sum = 0,et = 7;
//int s,x;
//int main()
//{
//    cin >> s >> x;
//    int left = s - x,right = s + x;
//    while(sum < left)
//    {
//        sum += et;
//        et *= 0.98;
//    }
//	et *= 0.98;
//    if(sum + et > right)cout << "n" << endl;
//    else cout << "y" << endl;
//    return 0;
//}
