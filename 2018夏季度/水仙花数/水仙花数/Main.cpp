#include<iostream>
using namespace std;

int main()
{
	while (true){
		int n,first = 1;
		//输入n位数
		cin >> n;
		if(n < 3 || n > 7)return 0;
		//获得n位数的起点整数
		int j = 1;
		while(j < n){
			first *= 10;
			j++;
		}
		//找出所有符合的整数153 = 1*1*1 + 5*5*5 + 3*3*3
		int end = first * 10;
		for (int i = first; i < end; i++){
			//求余
			int temp, p = i, sum = 0;
			while (p > 0){
				temp = p % 10;
				p /= 10;

				//获得幂次方和
				int s = temp;
				int k = 1;
				while (k < n){
					s *= temp;
					k++;
				}
				sum += s;
			}
			//判断是否符合
			if (i == sum){
				cout << i << endl;
			}
		}
	}
	return 0;
}