#include<iostream>
#include<cstdlib>	//���������ͷ�ļ�
#include<ctime>		//ʱ��ͷ�ļ�
#include<Windows.h>
#include<fstream>
using namespace std;

int a[10],b[10],n;


/****��������****/

//void quicksort(int left,int right){
//	int i,j,t,temp;
//	if(left > right)return;	//���⴫�β���������
//
//	temp = a[left];	//temp���׼��
//	i = left;
//	j = right;
//
//	while(i != j){
//		//�ȴ��ұ������ѯ���õ�С�ڻ�׼��������
//		while(a[j] >= temp && i < j)j--;
//		//�ٴ�������Ҳ�ѯ���õ����ڻ�׼��������
//		while(a[i] <= temp && i < j)i++;
//
//		//�������������������е�λ��
//		if(i < j){
//			t = a[i];
//			a[i] = a[j];
//			a[j] = t;
//		}
//	}
//
//	//��i��jָ��ͬһ����ַʱ��׼����λ
//	a[left] = a[i];
//	a[i] = temp;
//
//	//���õݹ��������
//	quicksort(left,i-1);	//�Ի�׼����߼�������
//	quicksort(i+1,right);	//�Ի�׼���ұ߼�������
//}
//
//int main()
//{
//	cin >> n;	//������������
//	for(int i = 1; i <= n; i++){
//		a[i] = rand() % 100;	//¼������������a��
//	}
//
//	//��ʼʱ��
//	double startime = clock();
//
//	quicksort(1,n);	//����������
//
//	//����ʱ��
//	double endtime  = clock();
//
//	//���������˳��
//	for(int i = 1; i <= n; i++){
//		cout << a[i] << " ";
//	}
//	cout << "\n" << (double)(endtime - startime) << endl;
//	return 0;
//}



/****��������Ľ���****/


//void quicksort(int left,int right)
//{
//	int i,j,t,base;
//	i = left;
//	j = right;
//	base = a[(i+j)/2];	//��׼��
//	while(i <= j){
//		//�ٴ�������Ҳ�ѯ���õ����ڻ�׼��������
//		while(a[i] < base)i++;
//		//�ȴ��ұ������ѯ���õ�С�ڻ�׼��������
//		while(a[j] > base)j--;
//		//�������������������е�λ��
//		if (i <= j){
//			t=a[i];
//			a[i]=a[j];
//			a[j]=t;
//			i++;
//			j--;
//		}
//	}
//	//���õݹ��������
//	if (left < j)quicksort(left,j);		//�Ի�׼����߼�������
//	if (i < right)quicksort(i,right);	//�Ի�׼���ұ߼�������
//}
//
//int main()
//{
//	ofstream outfile;
//	outfile.open("int.txt");
//	if(!outfile){
//		cout << "int.txt������" << endl;
//	}
//
//	cin >> n ;
//
//	//�����������
//	for (int i=1;i <= n; i++){
//		a[i] = rand() % 10000000;
//	}
//
//	//�������ǰ������
//	outfile << "\n����ǰ������\n" << endl;
//	for(int i = 1; i <= n; i++){
//		if(i == n){
//			/*cout << a[i] << endl*/
//			outfile<< a[i] << endl;
//		}else{
//			/*cout << a[i] << " ";*/
//			outfile << a[i] << " ";
//		}
//	}
//
//	//����ʼʱ��
//	clock_t startime = clock();
//
//	//���õݹ�������
//	quicksort(1,n);
//
//	//˯��һ��
//	//Sleep(1000);
//
//	//�������ʱ��
//	clock_t endtime = clock();
//
//	//�������������
//	outfile << "\n����������\n" << endl;
//	for(int i = 1; i <= n; i++){
//		if(i == n){
//			/*cout << a[i] << endl*/
//			outfile << a[i] << endl;
//		}else{
//			/*cout << a[i] << " ";*/
//			outfile << a[i] << " ";
//		}
//	}
//	//���ʱ��
//	printf("\n������ʱ��-->>%fs\n",(double)(endtime - startime) / (double)CLOCKS_PER_SEC);
//
//	outfile << (double)(endtime - startime) / (double)CLOCKS_PER_SEC << " s";
//
//	outfile.close();
//
//	return 0;
//}

//ͳ��ÿ���������ִ���
void countNum()
{
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i] == a[j])
			{
				b[a[i]]++;
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;

	countNum();

	for (int i = 0; i < 10; i++)
	{
		if (b[i] != 0)
		{
			cout << i << " : " << b[i] << endl;
		}
		
	}
	cout << endl;

	return 0;
}