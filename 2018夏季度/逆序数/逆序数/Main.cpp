/*
题目描述  
在一个排列中，如果一对数的前后位置与大小顺序相反，即前面的数大于后面的数，那么它们就称为一个逆序。
一个排列中逆序的总数就称为这个排列的逆序数。比如一个序列为4 5 1 3 2， 那么这个序列的逆序数为7，
逆序对分别为(4, 1), (4, 3), (4, 2), (5, 1), (5, 3), (5, 2),(3, 2)。

输入描述:
第一行有一个整数n(1 <= n <= 100000),  然后第二行跟着n个整数，对于第i个数a[i]，(0 <= a[i] <= 100000)。
输出描述:
输出这个序列中的逆序数

示例1 
输入
5
4 5 1 3 2
输出
7

思路：
分治法 归并排序的过程中，有一步是从左右两个数组中，每次都取出小的那个元素放到tmp[]数组中右边的数组
其实就是原数组中位于右侧的元素。当不取左侧的元素而取右侧的元素时，说明左侧剩下的元素均比右侧的第一个元素大，
即均能构成一个逆序对。假设现在左侧剩余n个元素，则逆序对数+n。
另外，如果当所有右侧的元素都取完，但是左侧仍然有元素剩余时，左侧剩余的元素已经在之前的运算中加到了逆序对中，
不需要再添加一次
*/

#include<cstdio>
#include<cstring>
using namespace std;
int n;
int a[20];
int cnt;

void query(int a[], int first, int mid, int last, int tmp[]){
	int i = first, j = mid+1;
	int k = 0;
	while(i <= mid && j <= last){
		if(a[i] <= a[j]) tmp[k++] = a[i++];
		else{
			tmp[k++] = a[j++];
			cnt += mid-i+1;
		}
	}
	while(i <= mid){
		tmp[k++] = a[i++];
	}
	while(j <= last){
		tmp[k++] = a[j++];
	}
	for(int id = 0; id < k; id++){
		a[first + id] = tmp[id];
	}
}
void merge_sort(int* a, int L, int R, int* tmp){
	if(L < R){
		int M = L + (R-L)/2;
		merge_sort(a,L,M,tmp);
		merge_sort(a,M+1,R,tmp);
		query(a,L,M,R,tmp);
	}
}
int main(){
	while (true)
	{
		scanf_s("%d",&n);
		for(int i = 0; i < n; i++){
			scanf_s("%d",&a[i]);
		}
		int tmp[20];
		cnt = 0;
		merge_sort(a,0,n-1,tmp);
		printf_s("%d\n",cnt);
	}
	return 0;
}