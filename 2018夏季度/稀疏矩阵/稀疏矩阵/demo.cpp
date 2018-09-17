#include <iostream>
#define M 8	//稀疏矩阵行数
#define N 8	//稀疏矩阵列数
using namespace std;
typedef int Elemtype;
#define MaxSize 50


//三元组顺序表的类型定义
typedef struct
{
	int r;	//行号 
	int c;	//列号
	Elemtype d;	//元素值 
}TupNode;	//数据元素的节点类型 

//三元组顺序表的类型 
typedef struct
{
	int rows;	//行数
	int cols;	//列数
	int nums;	//非零元个数
	TupNode data[MaxSize];	//三元组数组	
}TSMatrix;

//基本运算的实现
void AssignMatrix(TSMatrix &t,Elemtype A[M][N]){
	int i,j;
	//由二维数组创建矩阵 
	t.rows = M;	//行数为M
	t.cols = N;	//列数为N
	t.nums = 0;	//设置变量
	
	//逐行扫描A
	for(i=0;i<M;i++)
		//逐列扫描第i行 
		for(j=0;j<N;j++){
			//取出A[i][j]，判断其是否为零,只储存非零元素
			if(A[i][j] != 0){
			//如果是，将其赋值给
			t.data[t.nums].r=i; 
			t.data[t.nums].c=j;
			t.data[t.nums].d=A[i][j];
			t.nums++;
			}	
		}
}

//转置操作
void TranTat(TSMatrix t,TSMatrix &tb){
	int k,k1 = 0,v;
	tb.rows = t.rows;tb.cols = t.cols;tb.nums = t.nums;
	if(t.nums != 0){     //当存在非零元素时进行转置
		for(v = 0; v < t.cols; v++)		
			for(k = 0; k < t.nums; k++){    //k用于扫描t.data的所有元素
				if(t.data[k].c == v){       //找到一个列号为v的元素
					//将行列交换后添加到tb中
					tb.data[k1].r = t.data[k].r;
					tb.data[k1].c = t.data[k].c;
					tb.data[k1].d = t.data[k].d;
					k1++;	//tb中的元素增加1
				}
			}
	}
} 

//显示二维数组
void DispMatrix(TSMatrix t){
	int flag = 0;
	for (int i = 0; i < t.rows; i++){
		for (int j = 0; j < t.cols; j++){
			for (int k = 0; k < t.nums; k++){
				//找到非零元素的位置
				if (t.data[k].r == i && t.data[k].c == j){
					printf("%d\t",t.data[k].d);
					flag = 1;//用1标记非零元素
				}
			}
			//没有1标记的位置输出0
			if(flag == 0)printf("%d\t",0);
			flag = 0;
		}
		printf("\n");
	}
	printf("\n");
}

//显示三元组顺序表
void DispTupMatrix(TSMatrix t)
{
	int k;
	if(t.nums <= 0)return;	//没有非零元素时直接返回
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("---------------------------------------------------------\n");
	for(k = 0; k < t.nums; k++)
		printf("\t%d\t%d\t%d\n",t.data[k].r,t.data[k].c,t.data[k].d);
} 

int main()
{
	//定义二维数组
	int A[M][N]={
	{0,0,-3,0,0,0,0,0},
	{0,0,0,0,0,0,37,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,24,0,0,0,0},
	{0,0,0,0,0,0,0,0},
	{0,15,0,0,0,0,0,0},
	{0,0,0,0,0,0,88,0},
	{0,0,0,0,0,0,0,0}
	};
	
	TSMatrix T;
	//创建初始三元组顺序表
	AssignMatrix(T,A); 
	//初始矩阵
	printf("初始矩阵\n");
	DispMatrix(T);
	//矩阵的三元顺序表
	printf("矩阵的三元顺序表\n");
	DispTupMatrix(T);
	
	TSMatrix T1;
	//转置 
	TranTat(T,T1);
	//转置后的矩阵
	printf("转置后的矩阵\n");
	DispMatrix(T1);
	//转置后的三元矩阵
	printf("转置后的三元矩阵\n");
	DispTupMatrix(T1);
	return 0;
}


