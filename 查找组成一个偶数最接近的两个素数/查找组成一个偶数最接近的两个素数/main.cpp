#include <iostream>
using namespace std;

/*
˼·:	��дһ���ж������ĺ���,Ȼ�������ֵ��2,����õ���ֵ(half)��һ������,ֱ������������ֵ�Ϳ���
		�������һ������,�������������������(half);һ��++,һ��--;ֱ������������������ʱ������,�����
*/
int judgePrime(int n)  //�ж������ĺ���
{
	int i = 2;
	if (n <= 3)
		return 1;
	while (1)
	{
		if (n % i == 0)
			break;
		if (i == n)
			break;
		i++;
	}
	if (n == i)
		return 1;
	else
		return 0;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int half = n / 2;
		if (judgePrime(half))
		{
			cout << half << endl;
			cout << half << endl;
			continue;
		}
		int left = half - 1, right = half + 1;
		while (left > 0)
		{
			if (judgePrime(left) && judgePrime(right))
				break;
			left--;
			right++;
		}
		cout << left << endl;
		cout << right << endl;
	}
	
	return 0;
}