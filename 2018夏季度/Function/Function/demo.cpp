/*
��Ŀ����

����һ���ݹ麯��w(a,b,c)

���a<=0 or b<=0 or c<=0�ͷ���ֵ1.

���a>20 or b>20 or c>20�ͷ���w(20,20,20)

���a<b����b<c �ͷ���w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)

�����������ͷ���w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)

���Ǹ��򵥵ĵݹ麯������ʵ���������ܻ���Щ���⡣��a,b,c��Ϊ15ʱ�����õĴ������ǳ��Ķࡣ��Ҫ����취����.

absi2011 : ���� w(30,-1,0)����������1����������2

����ʱ�����ǾͰ����������������

���Դ�Ϊ1

���������ʽ

�����ʽ��
��������������.
����-1��-1��-1����.

�����ʽ��
���������

��ʽ:
[b]w(a,_b,_c)_=_������(_����ո�)[/b]

�����������

��������#1					�������#1
1 1 1						w(1, 1, 1) = 2
2 2 2						w(2, 2, 2) = 4
-1 -1 -1
*/

#include<iostream>
using namespace std;
long long a,b,c,results[100][100][100];

int Function(int a,int b,int c){
	//��δ������������ݹ�
	if(a <= 0 || b <= 0 || c <= 0)return 1;
	else if(a > 20 || b > 20 || c > 20)return Function(20,20,20);
	//�ݹ������ͷ���ԭֵ,������õĴ������ǳ��Ķ�
	if(!results[a][b][c]){
		if(a < b && b < c)results[a][b][c] = Function(a,b,c-1) + Function(a,b-1,c-1) - Function(a,b-1,c);
		else results[a][b][c] = Function(a-1,b,c) + Function(a-1,b-1,c) + Function(a-1,b,c-1) - Function(a-1,b-1,c-1);
	}
	return results[a][b][c];
}

int main()
{
	//��������������������-1��-1��-1����.
	while(true){
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1)break;
		cout << "w" << "(" << a << ", " << b << ", " << c << ")" << " = " << Function(a,b,c) << endl;
	}
	return 0;
}