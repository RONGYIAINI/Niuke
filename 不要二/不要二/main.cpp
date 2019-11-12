#include <iostream>
using namespace std;
/*
思路:	从第一个盒子开始放,如果第一个盒子放了蛋糕,则所有于其距离为2的盒子不能放蛋糕
		直接创建一个[1000][1000]的二维数组,将所有值都设为0;从[i][j]开始放;在不越界的情况下
		[i + 2][j]不能放,设为-1;[i][j + 2]不能放,设为-1;统计所有为0的盒子;
*/
int main()
{
	int w = 0, h = 0;
	
	while (cin >> w)
	{
		if (w >= 1)
		{
			break;
		}
	}
	while (cin >> h)
	{
		if (h >= 0 && h < 1000)
		{
			break;
		}
	}
	int max = 0;
	char a[1000][1000] = { 0 };
	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (a[i][j] == 0){
				max++;
				if (i + 2 < w) {
					a[i + 2][j] = -1;
				}
				if (j + 2 < h) {
					a[i][j + 2] = -1;
				}
			}
		}
	}
	cout << max;
	return 0;
}