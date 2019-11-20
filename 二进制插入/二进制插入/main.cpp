#include <iostream>
using namespace std;

/*
思路:	由题意可知,要将n的二进制数的第j位到第i位变成m的二进制数;
		
*/
class BinInsert {
	int cot = 0;
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		int tmp = m;
		while (tmp != 0)
		{
			tmp = tmp >> 1;
			cot++;
		}
		if (cot > i - j + 1)
			return -1;
		m = m << j;
		n = n | m;
		return n;
	}
};
int main()
{
	BinInsert a;
	cout << a.binInsert(1024, 19, 2, 7);

	return 0;
}