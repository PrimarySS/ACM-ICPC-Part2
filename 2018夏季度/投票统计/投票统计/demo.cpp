/*
输入输出格式

输入格式：
president.in

第一行为一个整数n,代表竞选总统的人数。

接下来有n行，分别为第一个候选人到第n个候选人的票数。

输出格式：
president.out

共两行，第一行是一个整数m，为当上总统的人的号数。

第二行是当上总统的人的选票。

输入输出样例

输入样例#1
5
98765
12365
87954
1022356
985678
输出样例#1
4
1022356
说明

票数可能会很大，可能会到100位数字。

n<=20
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    int number;		//记录为当上总统的人的号数
	//票数可能会很大，可能会到100位数字。所以定义为string类型
    string max="";
    string in;
    cin >> n;
    for (int i = 0; i < n; i++){
		cin >> in;	//以字符串的形式输入
        int inSize = in.size();
        int maxSize = max.size();
        if(inSize > maxSize || (inSize >= maxSize && in > max)){    //需考虑长度相等的情况
            max = in;	//改变最大值
            number = i + 1;		//最大值下标
        }
    }
    cout << number << '\n' << max << endl;
    return 0;
}