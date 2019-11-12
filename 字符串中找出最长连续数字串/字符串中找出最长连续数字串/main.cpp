#include <iostream>
#include <string>
using namespace std;
/*
思路:	将字符串进行遍历;如果遇到数字,记录该数字的位置,并寻找下一个不是数字的位置
		由此我们可以得到一个数字串,求出该数字串的长度,并与最大的数字串进行比较,
		如果比最长数字串还要长,就将其保存到tmp中;在保存之前要把tmp先清空
*/
class Solu {
	string tmp; //用于保存并返回的字符串
public:
	string findnum(string str) {
		int size = str.size(); //字符串的大小
		for (int i = 0; i < size; i++)
		{
			if (str[i] >= '0' && str[i] <= '9') //寻找是否为数字
			{
				int begin = i;
				while (str[i] >= '0' && str[i] <= '9') //得到该连续数字串的最后一个数字的位置
				{
					i++;
				}
				if ((i - begin) > tmp.size()) //判断是否比已保存的数字串长,
				{
					tmp.clear(); //数字串清空
					for (int j = begin; j < i; j++)  //数字串保存
					{
						tmp.push_back(str[j]);
					}
				}
			}
		}
		return tmp;
	}
};
int main()
{
	string str;
	char s;
	while (1)
	{
		s = getchar();
		if (s == '\n') {
			break;
		}
		str.push_back(s);
	}
	Solu b;
	cout << b.findnum(str) << endl;
	return 0;
}