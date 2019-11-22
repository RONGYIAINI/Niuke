#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
对于非0递增序列(a1 < a2 < a3 < ... < an)如何覆盖每一个种类呢？
	举一个小例子：在2 3 4 5的序列中任意找三个数求和，保证没有其他的三个数的和大于它，你肯定会选择3，4，5；那如果需要找一个整数比其中任意三个数的和都大，且为最小的一个，应该怎么选？
	答案为：（（2 + 3 + 4 + 5） - 2） + 1 即可保证序列中任取三个数不可能比它大，且为符合条件的最小值。
	覆盖(a1, a2, ...an)的数为(sum(a1, a2, ..., an) - a1) + 1;// a1的值为最小值
1. 题目中存在最差情况为，一边没有，这时候需要将此种颜色所有的手套带走才可以保证题意。
2. 第二中情况就是上面的例子所体现的情况，在左右两边分别找出能够覆盖全部颜色的最小数量
3. 判断左右两边那一边需要拿的数量最小就拿那一边，然后在另一边随便拿一个就能保证题意
*/
class Gloves {
	int	n_left = 0;
	int n_right = 0;
	int sum = 0;
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
	
		int left_min = 30, right_min = 30;
		for (int i = 0; i < n; i++)
		{
			
			if (left[i] * right[i] == 0) {
				sum += left[i] + right[i];
			}
			else {
				n_left += left[i];
				n_right += right[i];
				left_min = min(left[i], left_min);
				right_min = min(right[i], right_min);
			}
		}
		sum += min(n_left - left_min, n_right - right_min) + 2;
		return sum ;
	}
};
int main()
{
	int n = 4;
	vector<int> left{ 0,7,1,6 };
	vector<int> righ{ 1,5,0,6 };
	Gloves a;
	cout << a.findMinimum(4, left, righ);


	return 0;
}