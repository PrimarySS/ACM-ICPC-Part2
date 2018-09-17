/*
输入输出格式

输入格式：
输入文件word.in只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。

输出格式：
输出文件word.out共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，
那么输出“Lucky Word”，否则输出“No Answer”；

第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。

输入输出样例

输入样例#1：					输入样例#2：
error							olympic

输出样例#1：					输出样例#2：
Lucky Word						No Answer
2								0
说明

【输入输出样例1解释】

单词error中出现最多的字母r出现了3次，出现次数最少的字母出现了1次，3-1=2，2是质数。

【输入输出样例2解释】

单词olympic中出现最多的字母i出现了2次，出现次数最少的字母出现了1次，1-1=0,0不是质数。
*/

#include<iostream>
using namespace std;

//判断是否为素数
bool IsPrime(int num){
	for(int division = 2; division <= num/2; division++)
		if(num % division == 0)return false;
	return true;
}

int main()
{
	int count[100];
	char word[100];
	//输入单词
	gets_s(word);
	//获得单词的长度
	int wlen = strlen(word);
	//统计所有字母出现次数
	for(int i = 0; i < wlen; i++)
		for(int j = i + 1; j < wlen; j++)
			if(word[i] == word[j])count[i]++;

	//获得最大出现次数和最小出现次数
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
