/*
��Ŀ����

��֪ n ������ x1,x2,��,xn���Լ�һ������ k��k��n������ n ����������ѡ k ��������ӣ�
�ɷֱ�õ�һϵ�еĺ͡����統 n=4��k��3��4 �������ֱ�Ϊ 3��7��12��19 ʱ���ɵ�ȫ������������ǵĺ�Ϊ��

3��7��12=22

3��7��19��29

7��12��19��38

3��12��19��34��

���ڣ�Ҫ����������Ϊ�������ж����֡�

����������ֻ��һ�ֵĺ�Ϊ������3��7��19��29����

���������ʽ

�����ʽ��										�����ʽ��
n , k ��1<=n<=20��k��n��						һ��������������������������
x1,x2����,xn ��1<=xi<=5000000��

�����������

��������#1��									�������#1��
4 3												1
3 7 12 19
*/

#include<iostream>
using namespace std;
int ans = 0,number[20],n,k;

//�ж��Ƿ�Ϊ����������
bool isPrime(int add){
	for(int divisor = 2; divisor <= add / 2; divisor++){
		if(add % divisor == 0)return false;
	}
	return true;
}

//��ͷ�����
void dfs(int m,int i,int sum){
	//ֱ���õ������������
	if(!m){
		if(isPrime(sum))ans++;
		return ;
	}
	//����������
	for(i; i <= n; i++){
		dfs(m - 1,i + 1,sum + number[i]);
	}
}

int main()
{
	//���������ĸ�����������͸���
	cin >> n >> k;
	//����n������
	for(int i = 1; i <= n; i++)cin >> number[i];
	dfs(k,1,0);
	cout << ans << endl;
	return 0;
}