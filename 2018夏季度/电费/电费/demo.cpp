/*
��Ŀ����

���õ�����150ǧ��ʱ�����²��ְ�ÿǧ��ʱ0.4463Ԫִ�У�
���õ�����151~400ǧ��ʱ�Ĳ��ְ�ÿǧ��ʱ0.4663Ԫִ�У�
���õ�����401ǧ��ʱ�����ϲ��ְ�ÿǧ��ʱ0.5663Ԫִ��;
С�����Լ���֤һ�£����֪ͨ����Ӧ����ѵ���Ŀ�����Ƿ���ȷ�ء�
���дһ��������֪�õ��ܼƣ����ݵ�۹涨�������Ӧ���ĵ��Ӧ���Ƕ��١�

���������ʽ

�����ʽ��
����һ����������ʾ�õ��ܼƣ���λ��ǧ��ʱ�ƣ���������10000��

�����ʽ��
���һ������������С�����1λ����λ��Ԫ�ƣ�������С�����1λ����

�����������

��������#1��
267
�������#1��
121.5
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int eSum = 0;
	double totalMoney = 0;
	cin >> eSum;
	if((eSum < 0) || (eSum >= 10000))
		return -1;
	if(eSum <= 150)
		totalMoney = eSum * 0.4463;
	else if((eSum > 150) && (eSum <= 400))
		totalMoney = 150 * 0.4463 + (eSum-150) * 0.4663;
	else
		totalMoney = 150 * 0.4463 + 250 * 0.6643 + (eSum-400) * 0.4663;
	
	cout << setiosflags(ios::fixed) << setprecision(1) << totalMoney << endl;
	return 0;
}


//#include<iostream>
//using namespace std;
//int main()
//{
//    int x;
//    scanf_s("%d",&x);
//    if(x <= 150)
//      printf("%.1f\n",x * 0.4463);
//    else
//        if((x >= 151) && (x <= 400))
//          printf("%.1f\n",150 * 0.4463 + (x-150) * 0.4663); 
//        else
//            printf("%.1f\n",150 * 0.4463 + 250 * 0.4663 + (x-400) * 0.5663);
//    return 0;
//}