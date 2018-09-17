#include <iostream>
#define M 8	//ϡ���������
#define N 8	//ϡ���������
using namespace std;
typedef int Elemtype;
#define MaxSize 50


//��Ԫ��˳�������Ͷ���
typedef struct
{
	int r;	//�к� 
	int c;	//�к�
	Elemtype d;	//Ԫ��ֵ 
}TupNode;	//����Ԫ�صĽڵ����� 

//��Ԫ��˳�������� 
typedef struct
{
	int rows;	//����
	int cols;	//����
	int nums;	//����Ԫ����
	TupNode data[MaxSize];	//��Ԫ������	
}TSMatrix;

//���������ʵ��
void AssignMatrix(TSMatrix &t,Elemtype A[M][N]){
	int i,j;
	//�ɶ�ά���鴴������ 
	t.rows = M;	//����ΪM
	t.cols = N;	//����ΪN
	t.nums = 0;	//���ñ���
	
	//����ɨ��A
	for(i=0;i<M;i++)
		//����ɨ���i�� 
		for(j=0;j<N;j++){
			//ȡ��A[i][j]���ж����Ƿ�Ϊ��,ֻ�������Ԫ��
			if(A[i][j] != 0){
			//����ǣ����丳ֵ��
			t.data[t.nums].r=i; 
			t.data[t.nums].c=j;
			t.data[t.nums].d=A[i][j];
			t.nums++;
			}	
		}
}

//ת�ò���
void TranTat(TSMatrix t,TSMatrix &tb){
	int k,k1 = 0,v;
	tb.rows = t.rows;tb.cols = t.cols;tb.nums = t.nums;
	if(t.nums != 0){     //�����ڷ���Ԫ��ʱ����ת��
		for(v = 0; v < t.cols; v++)		
			for(k = 0; k < t.nums; k++){    //k����ɨ��t.data������Ԫ��
				if(t.data[k].c == v){       //�ҵ�һ���к�Ϊv��Ԫ��
					//�����н�������ӵ�tb��
					tb.data[k1].r = t.data[k].r;
					tb.data[k1].c = t.data[k].c;
					tb.data[k1].d = t.data[k].d;
					k1++;	//tb�е�Ԫ������1
				}
			}
	}
} 

//��ʾ��ά����
void DispMatrix(TSMatrix t){
	int flag = 0;
	for (int i = 0; i < t.rows; i++){
		for (int j = 0; j < t.cols; j++){
			for (int k = 0; k < t.nums; k++){
				//�ҵ�����Ԫ�ص�λ��
				if (t.data[k].r == i && t.data[k].c == j){
					printf("%d\t",t.data[k].d);
					flag = 1;//��1��Ƿ���Ԫ��
				}
			}
			//û��1��ǵ�λ�����0
			if(flag == 0)printf("%d\t",0);
			flag = 0;
		}
		printf("\n");
	}
	printf("\n");
}

//��ʾ��Ԫ��˳���
void DispTupMatrix(TSMatrix t)
{
	int k;
	if(t.nums <= 0)return;	//û�з���Ԫ��ʱֱ�ӷ���
	printf("\t%d\t%d\t%d\n",t.rows,t.cols,t.nums);
	printf("---------------------------------------------------------\n");
	for(k = 0; k < t.nums; k++)
		printf("\t%d\t%d\t%d\n",t.data[k].r,t.data[k].c,t.data[k].d);
} 

int main()
{
	//�����ά����
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
	//������ʼ��Ԫ��˳���
	AssignMatrix(T,A); 
	//��ʼ����
	printf("��ʼ����\n");
	DispMatrix(T);
	//�������Ԫ˳���
	printf("�������Ԫ˳���\n");
	DispTupMatrix(T);
	
	TSMatrix T1;
	//ת�� 
	TranTat(T,T1);
	//ת�ú�ľ���
	printf("ת�ú�ľ���\n");
	DispMatrix(T1);
	//ת�ú����Ԫ����
	printf("ת�ú����Ԫ����\n");
	DispTupMatrix(T1);
	return 0;
}


