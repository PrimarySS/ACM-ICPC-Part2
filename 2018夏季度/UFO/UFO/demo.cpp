/*
��Ŀ����

С�������������������з�ʽת����һ�����֣����յ����־���������������ĸ�Ļ���
���С�A����1����Z����26�����磬��USACO��С�����21*19*1*3*15=17955��
���С������� mod 47�������ǵ�����mod 47,��͵ø������С����Ҫ׼���ñ����ߣ�

д��һ�����򣬶�����������С���������������ķ����ܷ��������ִ�������
����ܴ��䣬�������GO�������������STAY����С����������������û�пո��
����һ����д��ĸ��������6����ĸ����

���������ʽ

�����ʽ��
��1�У�һ������Ϊ1��6�Ĵ�д��ĸ������ʾ���ǵ����֡�
��2�У�һ������Ϊ1��6�Ĵ�д��ĸ������ʾ��������֡�

�����ʽ��
�����������

��������#1��
[����1]							[����2]
COMETQ							ABSTAR
HVNGAT							USACO

�������#1��
[���1]							[���2]
GO								STAY
*/

#include<iostream>
#include<string>
using namespace std;
char UFONAME[7],TEAMNAME[7];

int main()
{
	//�������ǺͶ��������
	gets_s(UFONAME);
	gets_s(TEAMNAME);
	//������鳤��
	int UN_len = strlen(UFONAME);
	int TN_len = strlen(TEAMNAME);
	//������ǵ�����ֵ
	int UFOSUM = 1;
	for(int i = 0; i < UN_len; i++){
		UFONAME[i] -= 64;
		UFOSUM *= UFONAME[i];
	}
	//������������ֵ
	int TEAMSUM = 1;
	for(int i = 0; i < TN_len; i++){
		TEAMNAME[i] -= 64;
		TEAMSUM *= TEAMNAME[i];
	}
	if(UFOSUM % 47 == TEAMSUM % 47)cout << "GO" << endl;
	else cout << "STAY" << endl;
	return 0;
}
