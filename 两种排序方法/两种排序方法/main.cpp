#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
思路:	首先,要写出字典排序和长度排序的算法,然后将字符串遍历判断,
		定义两个bool类型的变量来进行标记,如果是字典排序,f_lex = true;
		如果不是字典排序f_lex = false;同理,如果是长度排序,f_len = true;
		最后进行判断输出就行了;
*/
bool lex(string str1, string str2) //字典排序
{
	int i = 0;
	while (i < str1.size() && i < str2.size())
	{
		if (str1[i] - 'a' > str2[i] - 'a')  //因为字符无法直接比较大小,所以-'a'来进行比较
			return false;
		else if (str1[i] - 'a' < str2[i] - 'a')
			return true;
		else
			i++;
	}
	if (i >= str1.size() || i >= str2.size()) //如果因为i等于其中一个字符串的size而退出循环,说明这俩字符串前面相同,则判断其字符长度
		return (str1.size() < str2.size()); //如果前面的长度小于后面的,则是字典排序,否则不是字典排序
}
bool len(string str1, string str2) //长度排序
{
	if (str1.size() <= str2.size()) //判断前面的长度是否小于等于后面的长度就行
		return true;
	else
		return false;
}
int main()
{
	bool f_lex = true, f_len = true; //用来进行标记的bool类型变量,初值都设成true
	vector<string> str;
	string s;
	int n;
	cin >> n;
	while (str.size() < n)
	{
		cin >> s;
		str.push_back(s);
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (!(lex(str[i], str[i + 1]))) //如果不是字典排序将f_lex的值变成false;
			f_lex = false;
		if (!(len(str[i], str[i + 1]))) //如果不是长度排序将f_len的值变成false;
			f_len = false;
	}
	if (f_lex && !f_len) //如果仅是字典排序
		cout << "lexicographically";
	else if (f_len && !f_lex) //如果仅是长度排序
		cout << "lengths";
	else if (f_len && f_lex) //如果俩个都是
		cout << "both";
	else if (!f_lex && !f_len) //如果两个都不是
		cout << "none";
	return 0;
}