/*
��Ŀ����  
��һ�������У����һ������ǰ��λ�����С˳���෴����ǰ��������ں����������ô���Ǿͳ�Ϊһ������
һ������������������ͳ�Ϊ������е�������������һ������Ϊ4 5 1 3 2�� ��ô������е�������Ϊ7��
����Էֱ�Ϊ(4, 1), (4, 3), (4, 2), (5, 1), (5, 3), (5, 2),(3, 2)��

��������:
��һ����һ������n(1 <= n <= 100000),  Ȼ��ڶ��и���n�����������ڵ�i����a[i]��(0 <= a[i] <= 100000)��
�������:
�����������е�������

ʾ��1 
����
5
4 5 1 3 2
���
7

˼·��
���η� �鲢����Ĺ����У���һ���Ǵ��������������У�ÿ�ζ�ȡ��С���Ǹ�Ԫ�طŵ�tmp[]�������ұߵ�����
��ʵ����ԭ������λ���Ҳ��Ԫ�ء�����ȡ����Ԫ�ض�ȡ�Ҳ��Ԫ��ʱ��˵�����ʣ�µ�Ԫ�ؾ����Ҳ�ĵ�һ��Ԫ�ش�
�����ܹ���һ������ԡ������������ʣ��n��Ԫ�أ����������+n��
���⣬����������Ҳ��Ԫ�ض�ȡ�꣬���������Ȼ��Ԫ��ʣ��ʱ�����ʣ���Ԫ���Ѿ���֮ǰ�������мӵ���������У�
����Ҫ�����һ��
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