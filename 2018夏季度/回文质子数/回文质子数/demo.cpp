/*
��Ŀ����

��Ϊ151����һ����������һ��������(�����Һʹ��ҵ����ǿ�һ����)������ 151 �ǻ���������

дһ���������ҳ���Χ[a,b](5 <= a < b <= 100,000,000)( һ��)������л�������;

���������ʽ

�����ʽ��
�� 1 ��: �������� a �� b .

�����ʽ��
���һ�������������б�һ��һ����

�����������

��������#1�� ����						�������#1�� ����
5 500									5
										7
										11
										101
										131
										151
										181
										191
										313
										353
										373
										383
*/

#include<iostream>
using namespace std;
long long a,b;

//�ж��Ƿ�Ϊ�������ķ�����
bool IsPrime(long long num){
	for(int division = 2; division <= num / 2; division++){
		if(num % division == 0)return false;
	}
	return true;
}

//�жϻ�����
void IsReturn(){
	for(long long i = a; i <= b; i++){
		long long rem = 0,reverse = 0,temp = i;
		while(temp != 0){
			rem = temp % 10;
			reverse = reverse * 10 + rem;	//��������
			temp /= 10;
		}
		if(i == reverse && IsPrime(i))cout << i << endl;
	}
}

int main()
{
	//��������ֵ
	cin >> a >> b;
	IsReturn();
	return 0;
}
