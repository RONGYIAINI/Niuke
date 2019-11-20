#include <iostream>
using namespace std;
/*
思路:	由题意可知, 子节点/2 = 根节点;
		那么让俩个数中较大数除2,判断两个数是否相等,
		如果相等,则这个数就是最近公共祖先,否则,重复此操作直至两个数相等
*/
class LCA {

public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			getMax(&a, &b); 
			a = a / 2;
		}
		return a;
	}
private:	
	void getMax(int* a, int* b)//让a为俩个数中较大的数
	{
		int tmp;
		if (*a > *b)
			return;
		else {
			tmp = *a;
			*a = *b;
			*b = tmp;
		}
	}
};
int main()
{
	LCA a;
	cout << a.getLCA(4, 9);
	return 0;
}