/*
��Ŀ����

��һ��,С����Լ�����Ӿʱ�����˾�ȷ�ļ�ʱ�������еļ�ʱ����24Сʱ�Ƽ��㣩��
�������Լ���aʱb��һֱ��Ӿ�������cʱd�֣������С�����һ�£�
������һ�����˶���ʱ���أ�

���������ʽ

�����ʽ��
һ��������4���������ֱ��ʾa,b,c,d��

�����ʽ��
һ�������2������e��f���ÿո��������α�ʾС������һ�����˶���Сʱ���ٷ��ӡ�
���б�ʾ���ӵ�����fӦ��С��60��

�����������

��������#1��
12 50 19 10
�������#1��
6 20
*/

#include<iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	int star = 0,end = 0,hour = 0,minute = 0;
	int totalminute = 0;
	cin >> a >> b >> c >> d;
	star = a * 60 + b;
	end =  c * 60 + d;
	totalminute = end - star;
	hour = totalminute / 60;
	minute = totalminute % 60;
	cout << hour << " " << minute << endl;
	return 0;
}
