/*
���������ʽ

�����ʽ��
�����ļ�word.inֻ��һ�У���һ�����ʣ�����ֻ���ܳ���Сд��ĸ�����ҳ���С��100��

�����ʽ��
����ļ�word.out�����У���һ����һ���ַ�������������ĵĵ�����Lucky Word��
��ô�����Lucky Word�������������No Answer����

�ڶ�����һ��������������뵥����Lucky Word�����maxn-minn��ֵ���������0��

�����������

��������#1��					��������#2��
error							olympic

�������#1��					�������#2��
Lucky Word						No Answer
2								0
˵��

�������������1���͡�

����error�г���������ĸr������3�Σ����ִ������ٵ���ĸ������1�Σ�3-1=2��2��������

�������������2���͡�

����olympic�г���������ĸi������2�Σ����ִ������ٵ���ĸ������1�Σ�1-1=0,0����������
*/

#include<iostream>
using namespace std;

//�ж��Ƿ�Ϊ����
bool IsPrime(int num){
	for(int division = 2; division <= num/2; division++)
		if(num % division == 0)return false;
	return true;
}

int main()
{
	int count[100];
	char word[100];
	//���뵥��
	gets_s(word);
	//��õ��ʵĳ���
	int wlen = strlen(word);
	//ͳ��������ĸ���ִ���
	for(int i = 0; i < wlen; i++)
		for(int j = i + 1; j < wlen; j++)
			if(word[i] == word[j])count[i]++;

	//��������ִ�������С���ִ���
	int maxn = count[0],minn = count[0];
	for(int i = 1; i < wlen; i++){
		if(count[i] > maxn)maxn = count[i];
		if(count[i] < minn)minn = count[i];
	}

	int isprime = maxn - minn;
	if(IsPrime(isprime))cout << "Lucky Word" << endl << isprime << endl;
	else cout << "No Answer" << endl << 0 << endl;
	return 0;
}
