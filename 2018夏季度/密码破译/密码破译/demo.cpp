/*
��Ŀ����

�X�m��Ȼ�������룬�������ǵ���������һ����ĸ��ɡ�����������һ����ĸÿ������ƶ�nΪ�γɡ�
z����һ����ĸ��a�����ѭ�����������ҵ����ƶ�ǰ���Ǵ���ĸ��n������������롣(��ΪСд)

���������ʽ

�����ʽ��
��һ�У�n���ڶ��У�δ�ƶ�ǰ��һ����ĸ

�����ʽ��
һ�У��Ǵ��X�m������

�����������

��������#1��			�������#1��
1						rxf
qwe
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	string str;
	cin >> n;	//�����ƶ�λ�õ�n
	cin >> str;	//����δ�ƶ����ַ���

	//�ƶ��������
	/*����ԭ�����:detector��һ��Vector����,detecot.size()������˵���б�����Ϊ:
	unsigned int����,��j��int�������Ի����:�з���/�޷��Ų�ƥ�侯��*/
	for(unsigned i = 0; i < str.size(); i++){
		str[i] += n;
		if(str[i] > 'z')str[i] = ('a' - 1) + (str[i] - 'z');
	}
	for(unsigned i = 0; i < str.size(); i++)cout << str[i];
	cout << endl;
	return 0;
}
