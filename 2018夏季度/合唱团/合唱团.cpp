/**
题目描述
有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？
输入描述:
每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n (1 <= n <= 50)，表示学生的个数，接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（-50 <= ai <= 50）。接下来的一行包含两个整数，k 和 d (1 <= k <= 10, 1 <= d <= 50)。
输出描述:
输出一行表示最大的乘积。
示例1 
输入
复制
3
7 4 7
2 50
输出
复制
49
**/

#include<iostream>
using namespace std;

int main()
{
	int n,a[50],k,d;

	//学生的个数
	cin >> n;
	//每个学生的能力值 ai
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	// k 名学生
	//位置编号的差
	cin >> k >> d;

	//输出一行表示最大的乘积
	int Tsum = 0,Fsum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			Tsum = a[i] * a[j];
			//取绝对值
			if (Tsum < 0) {
				Tsum *= -1;
			}
			int Testd  = 0;
			if (a[i] > a[j]) {
				Testd = a[i] - a[j];
			} else {
				Testd = a[j] - a[i];
			}
			//判断最值
			if (Tsum > Fsum && Testd < d)  {
				Fsum = Tsum;
			}
		}
	}
	cout << Fsum << endl;
	return 0 ;

}
