#include <iostream>
using namespace std;
/*
˼·:	�ӵ�һ�����ӿ�ʼ��,�����һ�����ӷ��˵���,�������������Ϊ2�ĺ��Ӳ��ܷŵ���
		ֱ�Ӵ���һ��[1000][1000]�Ķ�ά����,������ֵ����Ϊ0;��[i][j]��ʼ��;�ڲ�Խ��������
		[i + 2][j]���ܷ�,��Ϊ-1;[i][j + 2]���ܷ�,��Ϊ-1;ͳ������Ϊ0�ĺ���;
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