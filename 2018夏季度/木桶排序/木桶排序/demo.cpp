
/****木桶排序****/

#include<iostream>
using namespace std;
int a[1000],n,t,sum = 0;

int main()
{
	//初始化数组
	for(int i = 0; i < 1000; i++)a[i] = 0;

	//输入数据
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		a[t]++;		//统计每个数字出现的次数
		if(a[t] > 1)continue;
		else sum++;
	}
	cout << sum << endl;
	//输出排序后非重复数串
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < a[i]; j++){
			//出现多次的只打印一次后跳出循环
			if(a[i] > 1){
				cout << i << " ";
				break;
			}
			else cout << i << " ";
		}
	}
	cout << endl;
	return 0;
}
