#include <iostream>
using namespace std;
/*
˼·:	���õݹ���㷨
		���俴��һ��xy����,���յ��������,ֻ�����������,
		Ҳ����x-1,����y-1;��x = 0ʱ,��ֻ������,����ֻʣһ��·��,
		ͬ��,��y=0ʱ,Ҳֻʣһ��·��,
		mathlode(int m, int n) = mathlode(m, n - 1) + mathlode(m - 1, n);
*/
int mathlode(int m, int n)
{
	if (m == 0 && n == 0) //��ʾ�����յ�
		return 0;
	if (m == 0 || n == 0) //��ʾ����߽�
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