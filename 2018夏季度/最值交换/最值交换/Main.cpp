#include<iostream>
using namespace std;

/**
�����������ֵ������������������Сֵ���һ����������
**/

int main()
{
	int a[100],b[100];
	//���������еĸ���
	int n;
	cin >> n;
	//����n������
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];	//�Ѳ�a����浽b�����У�������������ԭ����˳��
	}
	//ð������
	for (int j = 1; j <= n - 1; j++){
		for (int k = 1; k <= n - j; k++){
			if(b[k] > b[k + 1]){
				int temp = b[k + 1];
				b[k + 1] = b[k];
				b[k] = temp;
			}
		}
	}
	//�����������ֵ����Сֵ
	int min = b[1];
	int max = b[n]; 

	for (int i = 1; i <= n; i++){
		//��Сֵ���һ����������
		if(a[i] == min){
			a[i] = a[1];
			a[1] = min;
		}
		//���ֵ��������������
		if(a[i] == max){
			a[i] = a[n];
			a[n] = max;
		}
	}
	//��������
	for (int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	return 0;
}