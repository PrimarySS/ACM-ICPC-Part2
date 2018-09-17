#include<iostream>
using namespace std;

/**
整数列中最大值与最后的整数交换，最小值与第一个整数交换
**/

int main()
{
	int a[100],b[100];
	//输入整数列的个数
	int n;
	cin >> n;
	//输入n个整数
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];	//把不a数组存到b数组中，避免排序后干扰原数组顺序
	}
	//冒泡排序
	for (int j = 1; j <= n - 1; j++){
		for (int k = 1; k <= n - j; k++){
			if(b[k] > b[k + 1]){
				int temp = b[k + 1];
				b[k + 1] = b[k];
				b[k] = temp;
			}
		}
	}
	//获得数组的最大值和最小值
	int min = b[1];
	int max = b[n]; 

	for (int i = 1; i <= n; i++){
		//最小值与第一个整数交换
		if(a[i] == min){
			a[i] = a[1];
			a[1] = min;
		}
		//最大值与最后的整数交换
		if(a[i] == max){
			a[i] = a[n];
			a[n] = max;
		}
	}
	//遍历数组
	for (int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	return 0;
}