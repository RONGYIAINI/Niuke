#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
思路:	本题的难点在于如何将" "号内的空格和双引号外的空格区分开,
		设置一个count来表示是否在引号内
		将count的初始值设为0;遇到第一个引号时,将count的值变成1,然后第2个引号将其值设为0;
		然后在[0,1]区间内的空格属于操作符,其他时候为间隔符
*/
class solution
{
	int count = 0; //引号的状态
	string s1;     //保存给一个参数
public:
	vector<string> CommandResolver(string s)
	{
		vector<string> v; //返回值
		int i = 0;
		while (i < s.size())
		{
			if (s[i] != ' ') {
				
				while (i < s.size())
				{
					if (s[i] == '"' && count == 0) {  //遇到第一个引号时
						count = 1;
						i++;
					}
					if (s[i] == ' ' && count == 0) {  //遇到[0,0]内的空格时
						i++;
						break;
					}
					
					if (s[i] == '"' && count == 1) {   //遇到第2个引号时,表示该参数已经输入完
						count = 0;
						i++;
						break;
					}
					s1.push_back(s[i]); //如果不是上面的情况,保存该字符
					i++;
					
				}
				v.push_back(s1); //保存参数
				s1.clear(); //将用来保存参数的字符串清空
			}
			else {
				i++;
			}
		}

		return v;
	}

};


int main()
{
	int count = 0;
	vector<string> save;
	string s;
	char ch;
	while (ch = getchar())
	{
		if (ch == '\n')
			break;
		s.push_back(ch);
	}
	solution a;
	save = a.CommandResolver(s);
	int size = save.size();
	cout << size << endl;
	for (int i = 0; i < size; i++)
	{
		cout << save[i] << endl;
	}
	return 0;
}