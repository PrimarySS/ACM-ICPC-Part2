#include<iostream>
using namespace std;

int main()
{
	while (true){
		int n,first = 1;
		//����nλ��
		cin >> n;
		if(n < 3 || n > 7)return 0;
		//���nλ�����������
		int j = 1;
		while(j < n){
			first *= 10;
			j++;
		}
		//�ҳ����з��ϵ�����153 = 1*1*1 + 5*5*5 + 3*3*3
		int end = first * 10;
		for (int i = first; i < end; i++){
			//����
			int temp, p = i, sum = 0;
			while (p > 0){
				temp = p % 10;
				p /= 10;

				//����ݴη���
				int s = temp;
				int k = 1;
				while (k < n){
					s *= temp;
					k++;
				}
				sum += s;
			}
			//�ж��Ƿ����
			if (i == sum){
				cout << i << endl;
			}
		}
	}
	return 0;
}