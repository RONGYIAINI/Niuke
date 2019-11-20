#include <iostream>
using namespace std;

/*
思路:	先写一个判断素数的函数,然后输入的值除2,如果得到的值(half)是一个素数,直接输出两此这个值就可以
		如果不是一个素数,让两个数都等于这个数(half);一个++,一个--;直到两个数都是素数的时候跳出,并输出
*/
int judgePrime(int n)  //判断素数的函数
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