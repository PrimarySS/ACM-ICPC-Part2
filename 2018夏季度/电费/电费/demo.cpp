/*
题目描述

月用电量在150千瓦时及以下部分按每千瓦时0.4463元执行，
月用电量在151~400千瓦时的部分按每千瓦时0.4663元执行，
月用电量在401千瓦时及以上部分按每千瓦时0.5663元执行;
小玉想自己验证一下，电费通知单上应交电费的数目到底是否正确呢。
请编写一个程序，已知用电总计，根据电价规定，计算出应交的电费应该是多少。

输入输出格式

输入格式：
输入一个整数，表示用电总计（单位以千瓦时计），不超过10000。

输出格式：
输出一个数，保留到小数点后1位（单位以元计，保留到小数点后1位）。

输入输出样例

输入样例#1：
267
输出样例#1：
121.5
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int eSum = 0;
	double totalMoney = 0;
	cin >> eSum;
	if((eSum < 0) || (eSum >= 10000))
		return -1;
	if(eSum <= 150)
		totalMoney = eSum * 0.4463;
	else if((eSum > 150) && (eSum <= 400))
		totalMoney = 150 * 0.4463 + (eSum-150) * 0.4663;
	else
		totalMoney = 150 * 0.4463 + 250 * 0.6643 + (eSum-400) * 0.4663;
	
	cout << setiosflags(ios::fixed) << setprecision(1) << totalMoney << endl;
	return 0;
}


//#include<iostream>
//using namespace std;
//int main()
//{
//    int x;
//    scanf_s("%d",&x);
//    if(x <= 150)
//      printf("%.1f\n",x * 0.4463);
//    else
//        if((x >= 151) && (x <= 400))
//          printf("%.1f\n",150 * 0.4463 + (x-150) * 0.4663); 
//        else
//            printf("%.1f\n",150 * 0.4463 + 250 * 0.4663 + (x-400) * 0.5663);
//    return 0;
//}