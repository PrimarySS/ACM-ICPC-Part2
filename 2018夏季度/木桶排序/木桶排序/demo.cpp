
/****ľͰ����****/

#include<iostream>
using namespace std;
int a[1000],n,t,sum = 0;

int main()
{
	//��ʼ������
	for(int i = 0; i < 1000; i++)a[i] = 0;

	//��������
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> t;
		a[t]++;		//ͳ��ÿ�����ֳ��ֵĴ���
		if(a[t] > 1)continue;
		else sum++;
	}
	cout << sum << endl;
	//����������ظ�����
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < a[i]; j++){
			//���ֶ�ε�ֻ��ӡһ�κ�����ѭ��
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
