#include<iostream>
#include<cstdlib>	//生成随机数头文件
#include<ctime>		//时间头文件
#include<Windows.h>
#include<fstream>
using namespace std;

int a[10],b[10],n;


/****快速排序****/

//void quicksort(int left,int right){
//	int i,j,t,temp;
//	if(left > right)return;	//避免传参不符合条件
//
//	temp = a[left];	//temp存基准数
//	i = left;
//	j = right;
//
//	while(i != j){
//		//先从右边往左查询，得到小于基准数的整数
//		while(a[j] >= temp && i < j)j--;
//		//再从左边往右查询，得到大于基准数的整数
//		while(a[i] <= temp && i < j)i++;
//
//		//交换两个整数在数组中的位置
//		if(i < j){
//			t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//	}
//
//	//当i，j指向同一个地址时基准数归位
//	a[left] = a[i];
//	a[i] = temp;
//
//	//利用递归继续排序
//	quicksort(left,i-1);	//对基准数左边继续排序
//	quicksort(i+1,right);	//对基准数右边继续排序
//}
//
//int main()
//{
//	cin >> n;	//输入整数个数
//	for(int i = 1; i <= n; i++){
//		a[i] = rand() % 100;	//录入整数到数组a中
//	}
//
//	//开始时间
//	double startime = clock();
//
//	quicksort(1,n);	//调用排序函数
//
//	//结束时间
//	double endtime  = clock();
//
//	//输出排序后的顺序
//	for(int i = 1; i <= n; i++){
//		cout << a[i] << " ";
//	}
//	cout << "\n" << (double)(endtime - startime) << endl;
//	return 0;
//}



/****快速排序改进版****/


//void quicksort(int left,int right)
//{
//	int i,j,t,base;
//	i = left;
//	j = right;
//	base = a[(i+j)/2];	//基准数
//	while(i <= j){
//		//再从左边往右查询，得到大于基准数的整数
//		while(a[i] < base)i++;
//		//先从右边往左查询，得到小于基准数的整数
//		while(a[j] > base)j--;
//		//交换两个整数在数组中的位置
//		if (i <= j){
//			t=a[i];
//			a[i]=a[j];
//			a[j]=t;
//			i++;
//			j--;
//		}
//	}
//	//利用递归继续排序
//	if (left < j)quicksort(left,j);		//对基准数左边继续排序
//	if (i < right)quicksort(i,right);	//对基准数右边继续排序
//}
//
//int main()
//{
//	ofstream outfile;
//	outfile.open("int.txt");
//	if(!outfile){
//		cout << "int.txt不存在" << endl;
//	}
//
//	cin >> n ;
//
//	//随机生成整数
//	for (int i=1;i <= n; i++){
//		a[i] = rand() % 10000000;
//	}
//
//	//输出排序前的整数
//	outfile << "\n排序前的整数\n" << endl;
//	for(int i = 1; i <= n; i++){
//		if(i == n){
//			/*cout << a[i] << endl*/
//			outfile<< a[i] << endl;
//		}else{
//			/*cout << a[i] << " ";*/
//			outfile << a[i] << " ";
//		}
//	}
//
//	//排序开始时间
//	clock_t startime = clock();
//
//	//调用递归排序函数
//	quicksort(1,n);
//
//	//睡眠一秒
//	//Sleep(1000);
//
//	//排序结束时间
//	clock_t endtime = clock();
//
//	//输出排序后的整数
//	outfile << "\n排序后的整数\n" << endl;
//	for(int i = 1; i <= n; i++){
//		if(i == n){
//			/*cout << a[i] << endl*/
//			outfile << a[i] << endl;
//		}else{
//			/*cout << a[i] << " ";*/
//			outfile << a[i] << " ";
//		}
//	}
//	//输出时间
//	printf("\n排序总时间-->>%fs\n",(double)(endtime - startime) / (double)CLOCKS_PER_SEC);
//
//	outfile << (double)(endtime - startime) / (double)CLOCKS_PER_SEC << " s";
//
//	outfile.close();
//
//	return 0;
//}

//统计每个整数出现次数
void countNum()
{
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i] == a[j])
			{
				b[a[i]]++;
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	countNum();

	for (int i = 0; i < 10; i++)
	{
		if (b[i] != 0)
		{
			cout << i << " : " << b[i] << endl;
		}
		
	}
	cout << endl;

	return 0;
}