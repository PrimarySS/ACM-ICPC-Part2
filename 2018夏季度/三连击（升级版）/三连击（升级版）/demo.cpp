/*
题目描述

将1，2，…，9共9个数分成三组，分别组成三个三位数，且使这三个三位数的比例是A:B:C，
试求出所有满足条件的三个三位数，若无解，输出“No!!!”。

//感谢黄小U饮品完善题意

输入输出格式

输入格式：
三个数，A B C。

输出格式：
若干行，每行3个数字。按照每行第一个数字升序排列。

输入输出样例

输入样例#1：
1 2 3
输出样例#1： 
192 384 576
219 438 657
273 546 819
327 654 981
*/

#include<iostream>
using namespace std;

int main()
{
	int A,B,C;
	int b = 0,c = 0,count = 0;
	//输入三个数的比例
	cin >> A >> B >> C;
	for(int a = 123; a <= 333; a++){
		b = a * B;
		c = a * C;
		if(((a/100) * (a/10%10) * (a%10) * (b/100) * (b/10%10) * (b%10)
			* (c/100) * (c/10%10) * (c%10)) == (1*2*3*4*5*6*7*8*9)){
				cout << a << " " << b << " " << c << endl;
				count++;
		}	
	}
	if(count == 0)cout << "No!!!" << endl;
	return 0;
}

//#include <cstdio>
//#include <algorithm> //为调用之后的函数next_permutation
//using namespace std;
//
//int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//
//int main(void){
//    int x, y, z, q, w, e;
//	bool b = 0;
//    scanf_s("%d %d %d", &x, &y, &z);
//    do{
//        q = a[1] * 100 + a[2] * 10 + a[3];
//        w = a[4] * 100 + a[5] * 10 + a[6];
//        e = a[7] * 100 + a[8] * 10 + a[9];
//        if (q * y * z == w * x * z  &&  w * x * z == e * x * y  && 
//			q * y * z == e * x * y){
//				printf_s("%d %d %d\n", q, w, e);
//				b = 1;
//		}
//    }while (next_permutation(a + 1, a + 10));//按字典序排下一种可能，继续判断
//    if (b == 0)printf_s("No!!!");//三个!,三个!,三个!，重要的事情说三遍
//    return 0;
//}