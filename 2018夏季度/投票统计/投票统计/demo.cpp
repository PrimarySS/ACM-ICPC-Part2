/*
���������ʽ

�����ʽ��
president.in

��һ��Ϊһ������n,����ѡ��ͳ��������

��������n�У��ֱ�Ϊ��һ����ѡ�˵���n����ѡ�˵�Ʊ����

�����ʽ��
president.out

�����У���һ����һ������m��Ϊ������ͳ���˵ĺ�����

�ڶ����ǵ�����ͳ���˵�ѡƱ��

�����������

��������#1
5
98765
12365
87954
1022356
985678
�������#1
4
1022356
˵��

Ʊ�����ܻ�ܴ󣬿��ܻᵽ100λ���֡�

n<=20
*/
#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    int number;		//��¼Ϊ������ͳ���˵ĺ���
	//Ʊ�����ܻ�ܴ󣬿��ܻᵽ100λ���֡����Զ���Ϊstring����
    string max="";
    string in;
    cin >> n;
    for (int i = 0; i < n; i++){
		cin >> in;	//���ַ�������ʽ����
        int inSize = in.size();
        int maxSize = max.size();
        if(inSize > maxSize || (inSize >= maxSize && in > max)){    //�迼�ǳ�����ȵ����
            max = in;	//�ı����ֵ
            number = i + 1;		//���ֵ�±�
        }
    }
    cout << number << '\n' << max << endl;
    return 0;
}