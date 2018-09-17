/*
题目描述

在一个地图上有N个地窖（N<=200）,每个地窖中埋有一定数量的地雷。同时，
给出地窖之间的连接路径，并规定路径都是单向的。某人可以从任一处开始挖地雷，
然后沿着指出的连接往下挖（仅能选择一条路径），当无连接时挖地雷工作结束。
设计一个挖地雷的方案，使他能挖到最多的地雷。

输入
[输入]
 N					{地窖的个数}
 W1，W2，……WN     {每个地窖中的地雷数}
 X1，Y1				{表示从X1可到Y1}
 X2，Y2
……
0，0				{表示输入结束}

输出
[输出]
 K1-K2-k3  …… -Kv   {挖地雷的顺序}
 MAX             {最多挖出的地雷数}

样例输入							样例输出
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
//	//输入地窖个数
//	cin >> N;
//	//输入每个地窖的地雷数
//	for(int i = 1; i <= N; i++)cin >> cellar[i];
//	//输入所有路径
//	int i = 0;
//	do{
//		i++;
//		cin >> Xi[i] >> Yi[i];
//	}while(Xi[i] != 0 || Yi[i] != 0);
//	i -= 2;
//	
//	//储存所有路径
//	for(int j = 1; j <= i; j++){
//		int Max = 0,temp = Yi[j];
//		Road[j] = Xi[j];	//储存路径的开头
//		Max += cellar[Xi[j]];	//路径上第一个地窖的地雷数
//		for(int k = j + 1; k <= i; k++){
//			if(Xi[k] == temp){
//				Road[++j] = Xi[k];	//连接路径
//				Max += cellar[Xi[k]];	//求和路径上下一个地窖的地雷数
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
	//输入地窖个数
    cin>>n;
	//输入每个地窖的地雷数
    for(i=1;i<=n;i++)cin>>w[i];
	//输入所有路径
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
