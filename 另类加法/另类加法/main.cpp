#include <iostream>
using namespace std;
/*
思路:
	二进制加法。发现一个特点。
	位的异或运算跟求'和'的结果一致：
	异或 1^1=0 1^0=1 0^0=0
	位的与运算跟求'进位‘的结果一致：
	位与 1&1=1 1&0=0 0&0=0

	异或将需要进位的位置 变成0;不需要进位的位置不变
	位于将需要进位的地方 变成1,不要进位的位置变成0  再左移一位,就表示进位
	将异或的结果和位于的结果再进行异或得到了一个结果, 
	重复操作,当所有的位置都不需要进位的时候,表示已经算出结果

	于是可以用异或运算和与运算来表示加法

	可以将其记成一个公式:a+b = (a ^ b) ^ ((a & b) << 1)
	如果 ((a & b) << 1) != 0;表示需要有些位进位,
	那么 a = a^b, b = ((a & b) << 1);
*/

class UnusualAdd {
public:
	int addAB(int A, int B) {
		int a, b;
		while (B != 0)
		{
			a = A ^ B;
			b = (A & B) << 1;
			A = a;
			B = b;
		}
		return a;
	}
};
int main()
{
	UnusualAdd a;
	cout << a.addAB(1, 2) << endl;

	return 0;
}