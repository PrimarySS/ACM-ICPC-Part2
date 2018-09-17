/*
题目描述

一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，
有的还能统计出特定单词在文章中出现的次数。

现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中
出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，
即给定单词必须与文章

中的某一独立单词在不区分大小写的情况下完全相同（参见样例1 ），如果给定单词仅是
文章中某一单词的一部分则不算匹配（参见样例2 ）。

输入输出格式

输入格式：
第1 行为一个字符串，其中只含字母，表示给定单词；
第2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

输出格式：
只有一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，
分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词
首字母在文章中的位置，位置从 0 开始）；如果单词在文章中没有出现，则直接输出
一个整数-1。

输入输出样例

输入样例#1：
To 
to be or not to be is a question 
输出样例#1：
2 0

输入样例#2：
to 
Did the Ottoman Empire lose its power at that time
输出样例#2：
-1
*/

#include<iostream>
using namespace std;
char word[11],article[10000001];

int main(){
    //输入单词和文章
    gets_s(word);
    gets_s(article);
	//获得单词和文章的长度
    int art_len = strlen(article);
    int wor_len = strlen(word);
    //把文章所有字母转换为小写
    for(int i = 0; i < art_len; ++ i)
		article[i] = tolower(article[i]);
	//把单词所有字母转换为小写
    for(int i = 0;i < wor_len; ++ i)
		word[i] = tolower(word[i]);

	//定义出现次数和第一次出现索引
    int index = -1,sum = 0;
    int i,j;
    for(i = 0; i < art_len; ++ i){
        if(i == 0 || article[i-1] == ' '){//开头或者文章前一个字符为空格开始匹配 
            for(j = 0; j < wor_len; j ++){
				//如果文章第i+j个字符与单词第j字符不相等，跳出本次循环
                if(article[i+j] != word[j]) break;
				//如果文章第i+j个字符与单词第j字符相等，继续比较单词与文章的下一个字符
                else continue;
            }
        }
		//既不是开头前一个字符也不是空格 读取article下一个字符 
        else continue;
		//如果单词与文章中的匹配或者已经比较完
        if((j == wor_len && article[i+j] == ' ') || (j == wor_len && (i+j)==art_len)){
            if(index == -1) index = i;
            sum ++; 
        } 
    }
    if(sum != 0 && index != -1)
		cout << sum << " " << index << endl;
	else
		cout << -1 << endl;
    return 0;
}