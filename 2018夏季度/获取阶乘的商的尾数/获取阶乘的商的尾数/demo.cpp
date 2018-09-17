/*
	As the answer can be quite large, it would be enough for Koyomi just to know the last digit of the
	answer in decimal representation. And you're here to provide Koyomi with this knowledge.

	Input
	The first and only line of input contains two space-separated integers a and b (long long).

	Output
	Output one line containing a single decimal digit �� the last digit of the value that interests Koyomi.

	Examples
	input
	2 4
	output
	2
	input
	0 10
	output
	0
*/

#include<iostream>
using namespace std;

int main()
{
	long long a,b,aSum = 1,bSum = 1;
	//����a,b�׳˵Ľ���
	cin >> a >> b;
	//���a�׳˵�ֵ
	for(long long i = 1; i <= a; i++)
	{
		aSum = aSum * i;
	}

	//���b�׳˵�ֵ
	for(long long i = 1; i <= b; i++)
	{
		bSum = bSum * i;
	}

	//���a,b�׳˵���
	long long finalSum = bSum / aSum;
	//����׳��̵ĸ�λ��
	cout << finalSum % 10 << endl;
	return 0;
}
