/*
��Ŀ����

��һ����ͼ����N���ؽѣ�N<=200��,ÿ���ؽ�������һ�������ĵ��ס�ͬʱ��
�����ؽ�֮�������·�������涨·�����ǵ���ġ�ĳ�˿��Դ���һ����ʼ�ڵ��ף�
Ȼ������ָ�������������ڣ�����ѡ��һ��·��������������ʱ�ڵ��׹���������
���һ���ڵ��׵ķ�����ʹ�����ڵ����ĵ��ס�

����
[����]
 N					{�ؽѵĸ���}
 W1��W2������WN     {ÿ���ؽ��еĵ�����}
 X1��Y1				{��ʾ��X1�ɵ�Y1}
 X2��Y2
����
0��0				{��ʾ�������}

���
[���]
 K1-K2-k3  ���� -Kv   {�ڵ��׵�˳��}
 MAX             {����ڳ��ĵ�����}

��������							�������
6									3-4-5-6
5 10 20 5 4 5						34
1 2 
1 4 
2 4 
3 4
4 5
4 6
5 6
0 0
*/

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int N,cellar[200],Xi[200],Yi[200],Road[200];
//	//����ؽѸ���
//	cin >> N;
//	//����ÿ���ؽѵĵ�����
//	for(int i = 1; i <= N; i++)cin >> cellar[i];
//	//��������·��
//	int i = 0;
//	do{
//		i++;
//		cin >> Xi[i] >> Yi[i];
//	}while(Xi[i] != 0 || Yi[i] != 0);
//	i -= 2;
//	
//	//��������·��
//	for(int j = 1; j <= i; j++){
//		int Max = 0,temp = Yi[j];
//		Road[j] = Xi[j];	//����·���Ŀ�ͷ
//		Max += cellar[Xi[j]];	//·���ϵ�һ���ؽѵĵ�����
//		for(int k = j + 1; k <= i; k++){
//			if(Xi[k] == temp){
//				Road[++j] = Xi[k];	//����·��
//				Max += cellar[Xi[k]];	//���·������һ���ؽѵĵ�����
//				temp = Yi[k];
//			}
//		}
//		cout << Max << endl;
//	}
//	return 0;
//}

#include <iostream>
using namespace std;

int main()
{
    long f[201]={0},w[201],c[201]={0};
    bool pd[201][201]={0};
    long i,j,n,x,y,l,k,mx;
	//����ؽѸ���
    cin>>n;
	//����ÿ���ؽѵĵ�����
    for(i=1;i<=n;i++)cin>>w[i];
	//��������·��
	do
	{
		cin>>x>>y;
		if(x!=0&&y!=0)pd[x][y]=1;
	}while(x!=0||y!=0);

    f[n]=w[n];

    for(i=n-1;i>=1;i--)
    {
		l=0;k=0;
		for(j=i+1;j<=n;j++)
			if(pd[i][j]==1 && f[j]>l){
				l=f[j];
				k=j;
			}
		f[i]=l+w[i];
		c[i]=k;
	}
	k=1;
	for(j=2;j<=n;j++)
		if(f[j]>f[k])k=j;
	mx=f[k];
	cout<<k;
	k=c[k];

	while(k!=0)
	{
		cout<<'-'<<k;
		k=c[k];
	}

	cout<<endl<<mx<<endl;
	return 0;
}
