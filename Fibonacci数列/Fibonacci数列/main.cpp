#include <iostream>
using namespace std;
/*
˼·:	�������һ�����������ж�һ�����ǲ���Fibonacci��;
		Ȼ������Ҫ�жϵ���++,--,����¼���Ǹ�����Ҫ���ٲ��ܳ�Ϊһ��Fibonacci��
		��󷵻ؽ�С��;
*/
int Fibonacci(int n) //�ж�һ�����Ƿ�ΪFibonacci��
{
	if (n == 1) return 1;
	int i = 0, tmp = 0;
	int a_1 = 1, a_2 = 1;
	while (1)
	{
		if (tmp > n) {
			i = 0;
			break;
		}
		else if(tmp == n)
		{
			i = 1;
			break;
		}
		tmp = a_1 + a_2; 
		a_1 = a_2;
		a_2 = tmp;
	}
	return i;
}
int main()
{
	int num, tmp;
	cin >> num;
	tmp = num;
	int min1 = 0, min2 = 0;
	for (tmp; tmp > 0; tmp--)
	{
		if (Fibonacci(tmp)) {
			break;
		}
		min1++;
	}
	tmp = num;
	for (tmp; ; tmp++)
	{
		if (Fibonacci(tmp)) {
			break;
		}
		min2++;
	}
	cout << (min1 > min2 ? min2 : min1); //min1 > min2ʱ����min2;min1 < min2ʱ����min1;
	return 0;
}