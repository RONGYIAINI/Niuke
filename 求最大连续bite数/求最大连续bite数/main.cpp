#include <iostream>
using namespace std;

/*
思路:	要判断一个数的对应二进制数字中1的连续个数,我们可以把这个数的二进制数看成一个数组
		通过 x & 1 是否为1 我们可以得到这个2进制数的最后一位是否为1
		然后 x >> 1 ,相当于去掉这个数组的最后一个元素,
		重复判断,最后即可得到最大连续数
*/
int main()
{
	int x;
	while (cin >> x)
	{
		int max = 0, n = 0;
		while (x)
		{
			if(x & 1){  //判断最后一位是否为1
				while (x & 1) //记录它的连续为1的个数
				{
					n++;
					x = x >> 1;
				}
			}
			if (n > max) //判断是否比最大的连续个数大
				max = n;
			n = 0;
			x = x >> 1;
		}
		cout << max << endl;
	}
	return 0;
}