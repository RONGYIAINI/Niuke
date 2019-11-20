#include <iostream>
#include <string>
using namespace std;
/*
思路:	首先看字符串第一位是不是'-'或者'+';如果是'-'最后结果乘以一个-1;如果是'+'最后结果乘以一个1;
		然后遍历字符串,发现字符直接返回0;是数字,将其转换为int类型;字符类型的数字转换为整数类型的数字需要  -48;
		转换为数字后,乘以它所需要乘以的10的n次方(假如它是百位上的数字就乘以100)
		然后将其相加并返回;
*/
class Solution {
	long long int num = 0; //用来保存的数字,为了让其足够大,将其设成longlong类型
	int size; //用来标记这是第几位数字的
	int i = 0, a = 1, tmp; //a 表示是一个整数还是一个负数
public:
	int StrToInt(string str) {
		size = str.size() - 1;
		if (str[i] == '+') { //如果第一位是＋, a不变;
			i++;
			size--;
		}
		else if (str[i] == '-') { // 如果第一位是 -, a = -1;
			a = -1;
			i++;
			size--;
		}
		while (i < str.size() && size >= 0)
		{
			if (str[i] >= '0' && str[i] <= '9') //判断是不是字符类型的数字
			{
				tmp = str[i] - 48; //将字符类型的数字转换为int类型
				num += tmp * pow(10, size);//将该数字乘上10的n次方后相加
			}
			else {  //如果不是一个字符类型的数字,直接返回0;
				num = 0;
				break;
			}
			i++;
			size--;
		}
		return num * a;
	}
};
int main()
{
	string s;
	cin >> s;
	Solution a;
	cout << a.StrToInt(s);
	return 0;
}