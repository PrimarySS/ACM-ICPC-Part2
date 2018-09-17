/*
输入输出格式

输入格式：
第一行为两个正整数M和N，代表内存容量和文章的长度。
第二行为N个非负整数，按照文章的顺序，每个数（大小不超过1000）代表一个英文单词。文章中两个单词是同一个单词，当且仅当它们对应的非负整数相同。

输出格式：
包含一个整数，为软件需要查词典的次数。

输入输出样例

输入样例#1：					输出样例#1： 
3 7								5
1 2 1 5 4 4 1

说明

每个测试点1s
整个查字典过程如下：每行表示一个单词的翻译，冒号前为本次翻译后的内存状况：
空：内存初始状态为空。

1． 1：查找单词1并调入内存。

2． 1 2：查找单词2并调入内存。

3． 1 2：在内存中找到单词1。

4． 1 2 5：查找单词5并调入内存。

5． 2 5 4：查找单词4并调入内存替代单词1。

6． 2 5 4：在内存中找到单词4。

7． 5 4 1：查找单词1并调入内存替代单词2。

共计查了5次词典。
*/

#include <iostream>
using namespace std;
int a[101],b,M;			//b数组模拟内存

//搜索内存中有没有已存在的
int sec(int l)
{
	for(int i = 0; i < M; i++)if(a[i] == l)return 1;
    return 0;
}

int main()
{
    int num = 0,N;
    for(int i = 0; i < 101; i++)a[i] = -1;	//注意可能有单词为0，所以不能默认数组为0
    cin >> M >> N;
	int p = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> b;
        if(!sec(b))						//如果在内存中没有存在单词
        {
            num++;						//计数器加一
            a[p] = b;					//当前p指向的内存，加入内容
            if(p == M - 1)p = 0;		//如果p+1大于内存上线则p=0
            else p++;
        }
    }
    cout << num;
    return 0;
}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	int M,N,word[1000],dictionary[1000],count = 0;
//	bool flag = 1;
//	//输入词典的容量//输入文章的长度
//	cin >> M >> N;
//	//输入单词
//	for(int i = 1; i <= N; i++)cin >> word[i];
//	//存单词入词典
//	for(int i = 1; i <= N; i++){
//		for(int j = 1; j <= M; j++){
//				if(word[i] != dictionary[j])flag = 0;   //在字典中查询不到单词的情况
//				else{flag = 1;break;}					//在字典中查询得到单词的情况
//		}
//		//如果词典没有此单词，则存入单词
//		if(!flag){
//			//当词典内存未满情况
//			if(count < M){
//				dictionary[i] = word[i];		
//				count++;						//外词典查询次数
//			}
//			//当词典内存已满情况
//			else{
//				dictionary[1] = word[i];		//覆盖词典第一位置的单词
//				count++;						//外词典查询次数
//			}
//		}
//	}
//	cout << count << endl;
//	return 0;
//}