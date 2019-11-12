#include <iostream>
using namespace std;
/*
思路:	首先设计一个函数用来判断一个数是不是Fibonacci数;
		然后让需要判断的数++,--,并记录他们各自需要多少步能成为一个Fibonacci数
		最后返回较小数;
*/
int Fibonacci(int n) //判断一个数是否为Fibonacci数
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
	cout << (min1 > min2 ? min2 : min1); //min1 > min2时返回min2;min1 < min2时返回min1;
	return 0;
}