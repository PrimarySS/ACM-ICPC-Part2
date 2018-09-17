#include<iostream>
using namespace std;
long long m,n,a,b,array[33][33],map[44][44];

//标记马的控制点
void horse(long long x,long long y)
{
	map[x][y] = 1;
	map[x-1][y-2] = 1;
	map[x-2][y-1] = 1;
	map[x-2][y+1] = 1;
	map[x-1][y+2] = 1;
	map[x+1][y+2] = 1;
	map[x+2][y+1] = 1;
	map[x+2][y-1] = 1;
	map[x+1][y-2] = 1;
}

int main()
{
	cin >> m >> n >> a >> b;
	horse(a,b);
	array[1][0] = 1;//卒的应有初始步伐
	//卒开始走动
	for(long long i = 1; i <= m + 1; ++i)
	{
		for(long long j = 1; j <= n + 1; ++j)
		{
			
			if(map[i-1][j-1])//走到马的控制点，数组为0
				array[i][j] = 0;
			else
				array[i][j] = array[i][j-1] + array[i-1][j];
		}
	}
	cout << array[m+1][n+1] << endl;
	return 0;
}

