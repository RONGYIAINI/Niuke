#include <iostream>
using namespace std;
/*
思路:	采用递归的算法
		将其看成一个xy数轴,从终点向起点走,只能向左和向下,
		也就是x-1,或者y-1;当x = 0时,就只能向下,所以只剩一种路线,
		同理,当y=0时,也只剩一种路线,
		mathlode(int m, int n) = mathlode(m, n - 1) + mathlode(m - 1, n);
*/
int mathlode(int m, int n)
{
	if (m == 0 && n == 0) //表示到达终点
		return 0;
	if (m == 0 || n == 0) //表示到达边界
		return 1;
	return mathlode(m, n - 1) + mathlode(m - 1, n);
}

int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int tmp = mathlode(m, n);
		cout << tmp << endl;
	}
	return 0;
}